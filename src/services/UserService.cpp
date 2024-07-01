#include "UserService.h"

#include "exceptions/SecurityProhibitionException.h"
#include "exceptions/DuplicateException.h"

const User *UserService::create(const string &username, const string &password, int age, const string &mobile) {
    User user(username, mobile, password, age);
    if (this->userRepository->findByName(user.getName()).has_value()) {
        throw DuplicateException("The username already exists: " + user.getName());
    }
    if (this->userRepository->findByMobile(user.getMobile()).has_value()) {
        throw DuplicateException("The mobile number already exists: " + user.getMobile());
    }
    return this->userRepository->create(&user);
}

void UserService::logIn(const string &username, const string &password) {
    auto user = this->userRepository->findByName(username);
    if (!user.has_value() || user.value()->getPassword() != password) {
        throw SecurityProhibitionException("Unauthorized credentials");
    }
    this->session->setLoggedUser(user.value());
}

void UserService::logOut() {
    this->session->setLoggedUser(nullptr);
}