#include "Plan.h"

#include "../exceptions/InvalidAttributeException.h"

Plan::Plan(string name, User *owner, string meetingPlace,
           chrono::system_clock::time_point date) : name(
        std::move(name)), meetingPlace(std::move(meetingPlace)), owner(owner),
                                                    date(date) {}

Plan::Plan(string name, User *owner, string meetingPlace,
           chrono::system_clock::time_point date, int capacity) : name(
        std::move(name)), meetingPlace(std::move(meetingPlace)), owner(owner),
                                                                  date(date) {
    this->setCapacity(capacity);
}

void Plan::addSubscriber(User *user) {
    if (this->capacity.has_value()) {
        if (this->subscribers.size() == this->capacity) {
            throw InvalidAttributeException("Capacity full, cannot add user: " +
                                            user->getName());
        }
    }
    this->subscribers.push_back(user);
}

/**
 * Calculate available spots
 * @return `-1` if not have capacity, other case `>=0`
 */
int Plan::availableSpots() const {
    if (!this->capacity.has_value()) {
        return -1;
    }
    return this->capacity.value() - this->subscribers.size();
}

void Plan::addActivity(Activity *activity) {
    if (std::find(this->activities.begin(), this->activities.end(), activity) !=
        this->activities.end()) {
        throw InvalidAttributeException(
                string("Activity with ID: ") + to_string(activity->getId()) +
                string("already exists in the activities list."));
    }
    if (activity->getCapacity().has_value() && this->capacity.has_value()) {
        if (activity->getCapacity().value() < this->capacity.value()) {
            this->capacity = activity->getCapacity();
        }
    }
    this->activities.push_back(activity);
}

float Plan::price(User *user) const {
    float sum = 0.0;
    for (const Activity *activity: this->activities) {
        sum += activity->getPrice(user->getAge());
    }
    return sum;
}

int Plan::duration() const {
    int sum = 0;
    for (const Activity *activity: this->activities) {
        sum += activity->getDuration() + TIME_DISPLACEMENT;
    }
    return sum;
}

// getters & setters

long Plan::getId() const {
    return this->id;
}

void Plan::setId(long id) {
    this->id = id;
}

const string &Plan::getName() const {
    return this->name;
}

void Plan::setName(const string &name) {
    this->name = name;
}

const string &Plan::getMeetingPlace() const {
    return this->meetingPlace;
}

void Plan::setMeetingPlace(const string &meetingPlace) {
    this->meetingPlace = meetingPlace;
}

const User *Plan::getOwner() const {
    return this->owner;
}

void Plan::setOwner(User *owner) {
    this->owner = owner;
}

const chrono::system_clock::time_point &Plan::getDate() const {
    return date;
}

void Plan::setDate(const chrono::system_clock::time_point &date) {
    this->date = date;
}

const optional<int> &Plan::getCapacity() const {
    return this->capacity;
}

void Plan::setCapacity(int capacity) {
    this->capacity = capacity;
}