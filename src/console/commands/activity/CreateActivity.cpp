#include "CreateActivity.h"

void CreateActivity::execute(const string *values) {

}

string &CreateActivity::value() {
    return const_cast<string &>(this->VALUE);
}

string &CreateActivity::helpParameters() {
    return const_cast<string &>(this->PARAMETER_HELP);
}

string &CreateActivity::helpComment() {
    return const_cast<string &>(this->COMMENT_HELP);
}
