#ifndef SOCIAL_PLANS_MANAGEMENT_PLANREPOSITORYMAP_H
#define SOCIAL_PLANS_MANAGEMENT_PLANREPOSITORYMAP_H

#include "GenericRepositoryMap.h"
#include "../PlanRepository.h"

class PlanRepositoryMap: public PlanRepository, GenericRepositoryMap<Plan> {
    long getIdEntity(Plan *entity) override;

    void setIdEntity(Plan *entity, long id) override;
};


#endif //SOCIAL_PLANS_MANAGEMENT_PLANREPOSITORYMAP_H
