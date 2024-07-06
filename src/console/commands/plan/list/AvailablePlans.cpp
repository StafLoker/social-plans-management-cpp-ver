#include "AvailablePlans.h"

void CreateUser::execute(const string *values) {

}

string &CreateUser::value() {
    return const_cast<string &>(this->VALUE);
}

string &CreateUser::helpParameters() {
    return const_cast<string &>(this->PARAMETER_HELP);
}

string &CreateUser::helpComment() {
    return const_cast<string &>(this->COMMENT_HELP);
}