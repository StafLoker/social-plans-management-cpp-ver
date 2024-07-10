#include "Logout.h"

void Logout::execute(const string *values) {
    this->userService->logOut();
}

string &Logout::value() {
    return const_cast<string &>(this->VALUE);
}

string &Logout::helpParameters() {
    return const_cast<string &>(this->PARAMETER_HELP);
}

string &Logout::helpComment() {
    return const_cast<string &>(this->COMMENT_HELP);
}
