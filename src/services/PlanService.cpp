#include "PlanService.h"

#include "exceptions/SecurityProhibitionException.h"
#include "exceptions/NotFoundException.h"
#include "exceptions/DuplicateException.h"
#include "../data/models/exceptions/InvalidAttributeException.h"

const Plan *
PlanService::create(const string &name, chrono::system_clock::time_point date, const string &meetingPlace, optional<int> capacity) {
    Plan plan(name, this->session->getSecuredUser(), meetingPlace, date);
    if (capacity.has_value()) {
        plan.setCapacity(capacity.value());
    }
    return this->planRepository->create(&plan);
}

void PlanService::deletePlan(long planId) {
    auto plan = this->planRepository->readById(planId);
    if (plan.has_value()) {
        if (plan.value()->getOwner() != this->session->getSecuredUser()) {
            throw SecurityProhibitionException("To delete the plan with id: " + to_string(plan.value()->getId()));
        }
        this->planRepository->deleteById(planId);
    }

}

const Plan *PlanService::addActivity(long planId, long activityId) {
    auto plan = this->planRepository->readById(planId);
    if (!plan.has_value()) {
        throw NotFoundException("The plan with ID: " + to_string(planId));
    }
    if (plan.value()->getOwner() != this->session->getSecuredUser()) {
        "To add activities to the plan with ID: " + to_string(plan.value()->getId()) +
        " you must be the owner; the owner is: " + plan.value()->getOwner()->getName();
    }
    auto activity = this->activityRepository->readById(activityId);
    if (!activity.has_value()) {
        throw NotFoundException("The activity with ID: " + to_string(activityId));
    }
    plan.value()->addActivity(activity.value());
    return this->planRepository->update(plan.value());
}

const Plan *PlanService::enrollSubscriber(long planId) {
    auto plan = this->planRepository->readById(planId);
    if (!plan.has_value()) {
        throw NotFoundException("The plan with ID: " + to_string(planId));
    }
    if (plan.value()->getDate() < chrono::system_clock::now()) {
        auto t = std::chrono::system_clock::to_time_t(plan.value()->getDate());
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H.%M", std::localtime(&t));
        throw InvalidAttributeException("The plan with ID: " + std::to_string(planId) + " was conducted on: " + std::string(buffer));
    }
    auto user = this->session->getSecuredUser();
    if (std::find(plan.value()->getSubscribers().begin(), plan.value()->getSubscribers().end(), user) !=
        plan.value()->getSubscribers().end()) {
        throw DuplicateException("You cannot join a plan twice, ID introduced: " + to_string(planId));
    }
    this->checkNoTimeCollisionBetweenSubscribedPlans(plan.value(), user);
    plan.value()->addSubscriber(user);
    return this->planRepository->update(plan.value());
}

float PlanService::price(long planId) const {
    auto plan = this->planRepository->readById(planId);
    if (!plan.has_value()) {
        throw NotFoundException("The plan with ID: " + to_string(planId));
    }
    auto user = this->session->getSecuredUser();
    if (std::find(plan.value()->getSubscribers().begin(), plan.value()->getSubscribers().end(), user) ==
        plan.value()->getSubscribers().end()) {
        throw SecurityProhibitionException(
                "You cannot check the price of a plan you are not participating in, ID introduced: " + to_string(planId));
    }
    return plan.value()->price(user);
}

int PlanService::duration(long planId) const {
    auto plan = this->planRepository->readById(planId);
    if (!plan.has_value()) {
        throw NotFoundException("The plan with ID: " + to_string(planId));
    }
    auto user = this->session->getSecuredUser();
    if (std::find(plan.value()->getSubscribers().begin(), plan.value()->getSubscribers().end(), user) ==
        plan.value()->getSubscribers().end()) {
        throw SecurityProhibitionException(
                "You cannot check the price of a plan you are not participating in, ID introduced: " + to_string(planId));
    }
    return plan.value()->duration();
}

const list<Plan *> PlanService::availablePlans() const {
    list<Plan *> list;
    for (auto plan: this->planRepository->findAll()) {
        if (plan->getDate() > chrono::system_clock::now()) {
            list.push_back(plan);
        }
    }
    return list;
}

const list<Plan *> PlanService::subscribedPlans() const {
    list<Plan *> list;
    auto user = this->session->getSecuredUser();
    for (auto plan: this->planRepository->findAll()) {
        if (std::find(plan->getSubscribers().begin(), plan->getSubscribers().end(), user) !=
            plan->getSubscribers().end()) {
            list.push_back(plan);
        }
    }
    return list;
}

const list<Plan *> PlanService::priceRangePlans(float price, float range) const {
    if (price < range) {
        throw InvalidAttributeException("The price " + to_string(price) + " cannot be less than the range " + to_string(range));
    }
    list<Plan *> list;
    auto user = this->session->getSecuredUser();
    for (const auto plan: this->planRepository->findAll()) {
        if (plan->price(user) >= price - range && plan->price(user) <= price + range) {
            list.push_back(plan);
        }
    }
    return list;
}

const list<Plan *> PlanService::weekendPlans() const {
    list<Plan *> weekendPlans;
    auto nextEndOfFriday = getNextFriday();
    +chrono::hours(23) + chrono::minutes(59) + chrono::seconds(59);
    auto nextMonday = nextEndOfFriday + chrono::hours(48) + chrono::seconds(1);

    for (const auto plan: availablePlans()) {
        if (plan->getDate() > nextEndOfFriday && plan->getDate() < nextMonday) {
            weekendPlans.push_back(plan);
        }
    }

    return weekendPlans;
}

const list<Plan *> PlanService::plansContainingKeyword(const string &keyword) const {
    list<Plan *> list;
    for (const auto plan: this->availablePlans()) {
        for (const auto activity: plan->getActivities()) {
            if (activity->getName().find(keyword) != string::npos || activity->getDescription().find(keyword) != string::npos) {
                list.push_back(plan);
            }
        }
    }
    return list;
}

void PlanService::checkNoTimeCollisionBetweenSubscribedPlans(Plan *plan, User *user) const {
    for (const auto pl: this->planRepository->findAll()) {
        if (find(pl->getSubscribers().begin(), pl->getSubscribers().end(), user) != pl->getSubscribers().end()) {
            if (pl->getDate() < plan->getDate() + chrono::minutes(plan->duration()) &&
                pl->getDate() + chrono::minutes(pl->duration()) > plan->getDate()) {
                throw InvalidAttributeException(
                        "You cannot join the plan with ID: " + std::to_string(plan->getId()) + " because it overlaps with plan ID: " +
                        std::to_string(pl->getId()));
            }
        }
    }
}

chrono::system_clock::time_point PlanService::getNextFriday() const {
    time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm local_tm = *localtime(&tt);

    int daysUntilFriday = (5 - local_tm.tm_wday + 7) % 7; // tm_wday: 0 = Sunday, 1 = Monday, ..., 5 = Friday
    local_tm.tm_mday += daysUntilFriday;
    local_tm.tm_hour = 0;
    local_tm.tm_min = 0;
    local_tm.tm_sec = 0;

    time_t nextFriday_tt = mktime(&local_tm);
    return chrono::system_clock::from_time_t(nextFriday_tt);
}
