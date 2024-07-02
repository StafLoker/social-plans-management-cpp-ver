#ifndef SOCIAL_PLANS_MANAGEMENT_DUPLICATEEXCEPTION_H
#define SOCIAL_PLANS_MANAGEMENT_DUPLICATEEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class DuplicateException : public logic_error {
public:
    explicit DuplicateException(const string &detail) : logic_error(
            string("Duplicate Exception. The attribute must be unique") + " >>> " + detail) {}
};

#endif //SOCIAL_PLANS_MANAGEMENT_DUPLICATEEXCEPTION_H
