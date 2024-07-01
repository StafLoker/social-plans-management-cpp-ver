#ifndef SOCIAL_PLANS_MANAGEMENT_USERREPOSITORYMAP_H
#define SOCIAL_PLANS_MANAGEMENT_USERREPOSITORYMAP_H


#include "../UserRepository.h"
#include "GenericRepositoryMap.h"

class UserRepositoryMap : public UserRepository, GenericRepositoryMap<User> {
    optional<User*> findByName(const string &name) override;

    optional<User*> findByMobile(const string &mobile) override;

    long getIdEntity(User *entity) override;

    void setIdEntity(User *entity, long id) override;
};


#endif //SOCIAL_PLANS_MANAGEMENT_USERREPOSITORYMAP_H
