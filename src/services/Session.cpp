#include "Session.h"
#include "exceptions/SecurityAuthorizationException.h"


void Session::assertLogin() {
    if (this->loggedUser == nullptr) {
        throw SecurityAuthorizationException("Use command/s ~ login ~ and/or ~ create-user ~");
    }
}

User *Session::getSecuredUser() {
    this->assertLogin();
    return this->loggedUser;
}

void Session::setLoggedUser(User *loggedUser) {
    this->loggedUser = loggedUser;
}

optional<User *> Session::getLoggedUser() {
    return make_optional(this->loggedUser);
}
