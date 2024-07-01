#include "ActivityRepositoryMap.h"

long ActivityRepositoryMap::getIdEntity(Activity *entity) {
    return entity->getId();
}

void ActivityRepositoryMap::setIdEntity(Activity *entity, long id) {
    entity->setId(id);
}
