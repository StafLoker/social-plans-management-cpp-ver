#ifndef SOCIAL_PLANS_MANAGEMENT_SESSION_H
#define SOCIAL_PLANS_MANAGEMENT_SESSION_H


#include "../data/models/User.h"
#include "optional"

class Session {
private:
    User *loggedUser;
public:
    Session() {
        this->loggedUser = nullptr;
    }

    void assertLogin();

    User *getSecuredUser();

    void setLoggedUser(User *loggedUser);

    optional<User *> getLoggedUser();
};


#endif //SOCIAL_PLANS_MANAGEMENT_SESSION_H
