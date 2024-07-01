#ifndef SOCIAL_PLANS_MANAGEMENT_USERREPOSITORYMAP_H
#define SOCIAL_PLANS_MANAGEMENT_USERREPOSITORYMAP_H


#include "../UserRepository.h"

class UserRepositoryMap : public UserRepository {
    optional<User> findByName(const string &name) override;

    optional<User> findByMobile(const string &mobile) override;
};


#endif //SOCIAL_PLANS_MANAGEMENT_USERREPOSITORYMAP_H
