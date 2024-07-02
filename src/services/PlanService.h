#ifndef SOCIAL_PLANS_MANAGEMENT_PLANSERVICE_H
#define SOCIAL_PLANS_MANAGEMENT_PLANSERVICE_H


#include "../data/daos/PlanRepository.h"
#include "../data/daos/ActivityRepository.h"
#include "Session.h"

class PlanService {
private:
    PlanRepository *planRepository;
    ActivityRepository *activityRepository;
    Session *session;

public:
    PlanService(PlanRepository *planRepository,
                ActivityRepository *activityRepository,
                Session *session) : planRepository(planRepository), activityRepository(activityRepository), session(session) {}

    const Plan *create(const string &name, chrono::system_clock::time_point date, const string &meetingPlace, optional<int> capacity);

    void deletePlan(long planId);

    const Plan *addActivity(long planId, long activityId);

    const Plan *enrollSubscriber(long planId);

    float price(long planId) const;

    int duration(long planId) const;

    const list<Plan *> availablePlans() const;

    const list<Plan *> subscribedPlans() const;

    const list<Plan *> priceRangePlans(float price, float range) const;

    const list<Plan *> weekendPlans() const;

    const list<Plan *> plansContainingKeyword(const string &keyword) const;

private:
    void checkNoTimeCollisionBetweenSubscribedPlans(Plan *plan, User *user) const;

    chrono::system_clock::time_point getNextFriday() const;
};


#endif //SOCIAL_PLANS_MANAGEMENT_PLANSERVICE_H
