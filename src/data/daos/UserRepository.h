#ifndef SOCIAL_PLANS_MANAGEMENT_USERREPOSITORY_H
#define SOCIAL_PLANS_MANAGEMENT_USERREPOSITORY_H

#include "GenericRepository.h"
#include "../models/User.h"

#include <optional>
#include <string>

using namespace std;

class UserRepository : public GenericRepository<User> {
public:
    virtual optional<User*> findByName(const string &name);

    virtual optional<User*> findByMobile(const string &mobile);
};

#endif //SOCIAL_PLANS_MANAGEMENT_USERREPOSITORY_H
