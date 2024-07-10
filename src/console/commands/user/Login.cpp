#include "Login.h"

void Login::execute(const string *values) {
    Command::execute(values);
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
