#include "ActivityService.h"

#include "../data/models/exceptions/InvalidAttributeException.h"
#include "../data/models/spm/activityTypes/Theater.h"
#include "../data/models/spm/activityTypes/Cinema.h"

const Activity *ActivityService::create(const string &type, const string &name, const string &description, int duration, float price,
                                        optional<int> capacity) {
    return this->activityRepository->create(this->createActivityBasedOnType(type, name, description, duration, price, capacity));
}

// @TODO maybe error
Activity *
ActivityService::createActivityBasedOnType(const string &type, const string &name, const string &description, int duration, float price,
                                           optional<int> capacity) {
    Activity activity;

    if (type == "Theater") {
        activity = Theater(name, description, duration, price);
    } else if (type == "Cinema") {
        activity = Cinema(name, description, duration, price);
    } else if (type == "Generic") {
        activity = Activity(name, description, duration, price);
    } else {
        throw InvalidAttributeException("Unsupported activity type: " + type);
    }
    if (capacity.has_value()) {
        activity.setCapacity(capacity.value());
    }

    return &activity;
}

/* Solution

 Activity* ActivityService::createActivityBasedOnType(const std::string &type, const std::string &name, const std::string &description, int duration, float price,
                                                     std::optional<int> capacity) {
    Activity* activity = nullptr;

    if (type == "Theater") {
        activity = new Theater(name, description, duration, price);
    } else if (type == "Cinema") {
        activity = new Cinema(name, description, duration, price);
    } else if (type == "Generic") {
        activity = new Activity(name, description, duration, price);
    } else {
        throw InvalidAttributeException("Unsupported activity type: " + type);
    }

    if (capacity.has_value()) {
        activity->setCapacity(capacity.value());
    }

    return activity;
}
 */


