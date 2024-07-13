#include "Login.h"

#include "../../exceptions/UnsupportedCommandException.h"
#include "../../exceptions/UnsupportedAttributesException.h"

void Login::execute(const vector<string&> *values) {
    if (this->session->getLoggedUser().has_value()) {
        throw UnsupportedCommandException("You are already logged in.");
    }
    if (values->size() != 2) {
        throw UnsupportedAttributesException(this->helpParameters());
    }
    this->userService->logIn(values[0], values[1]);
    this->view->show("Hello, " + this->session->getSecuredUser()->getName());
}

string &Login::value() {
    return const_cast<string &>(this->VALUE);
}

string &Login::helpParameters() {
    return const_cast<string &>(this->PARAMETER_HELP);
}

string &Login::helpComment() {
    return const_cast<string &>(this->COMMENT_HELP);
}