#ifndef SOCIAL_PLANS_MANAGEMENT_USERSERVICE_H
#define SOCIAL_PLANS_MANAGEMENT_USERSERVICE_H


#include "../data/daos/UserRepository.h"
#include "Session.h"

class UserService {
private:
    UserRepository *userRepository;
    Session *session;
public:
    UserService(UserRepository *userRepository, Session *session) : userRepository(userRepository), session(session) {}

    const User* create(const string& username, const string& password, int age, const string& mobile);

    void logIn(const string& username, const string& password);

    void logOut();
};


#endif //SOCIAL_PLANS_MANAGEMENT_USERSERVICE_H
