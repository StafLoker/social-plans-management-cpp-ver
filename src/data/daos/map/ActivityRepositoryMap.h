#ifndef SOCIAL_PLANS_MANAGEMENT_ACTIVITYREPOSITORYMAP_H
#define SOCIAL_PLANS_MANAGEMENT_ACTIVITYREPOSITORYMAP_H

#include "GenericRepositoryMap.h"
#include "../ActivityRepository.h"

class ActivityRepositoryMap: public ActivityRepository, GenericRepositoryMap<Activity> {
    long getIdEntity(Activity *entity) override;

    void setIdEntity(Activity *entity, long id) override;
};


#endif //SOCIAL_PLANS_MANAGEMENT_ACTIVITYREPOSITORYMAP_H
