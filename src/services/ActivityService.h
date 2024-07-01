#ifndef SOCIAL_PLANS_MANAGEMENT_ACTIVITYSERVICE_H
#define SOCIAL_PLANS_MANAGEMENT_ACTIVITYSERVICE_H


#include "../data/daos/ActivityRepository.h"

class ActivityService {
private:
    ActivityRepository *activityRepository;
public:
    ActivityService(ActivityRepository *activityRepository) : activityRepository(activityRepository) {}

    const Activity *
    create(const string &type, const string &name, const string &description, int duration, float price, optional<int> capacity);

private:
    Activity *createActivityBasedOnType(const string &type, const string &name, const string &description, int duration, float price,
                                        optional<int> capacity);
};


#endif //SOCIAL_PLANS_MANAGEMENT_ACTIVITYSERVICE_H
