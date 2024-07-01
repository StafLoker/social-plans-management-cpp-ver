#include "PlanRepositoryMap.h"

void PlanRepositoryMap::setIdEntity(Plan *entity, long id) {
    entity->setId(id);
}

long PlanRepositoryMap::getIdEntity(Plan *entity) {
    return entity->getId();
}
