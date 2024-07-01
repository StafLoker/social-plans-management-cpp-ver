#include "UserRepositoryMap.h"

optional<User*> UserRepositoryMap::findByName(const string &name) {
    auto it = this->repository.begin();
    for (; it != this->repository.end() && it->second->getName() != name; ++it);
    return make_optional(it->second);
}

optional<User*> UserRepositoryMap::findByMobile(const string &mobile) {
    auto it = this->repository.begin();
    for (; it != this->repository.end() && it->second->getMobile() != mobile; ++it);
    return make_optional(it->second);
}

void UserRepositoryMap::setIdEntity(User *entity, long id) {
    entity->setId(id);
}

long UserRepositoryMap::getIdEntity(User *entity) {
    return entity->getId();
}
