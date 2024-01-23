#ifndef SOCIAL_PLANS_MANAGEMENT_INVALIDATTRIBUTEEXCEPTION_H
#define SOCIAL_PLANS_MANAGEMENT_INVALIDATTRIBUTEEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InvalidAttributeException : public logic_error {
public:
    explicit InvalidAttributeException(const string &detail) : logic_error(
            string("Invalid attribute exception. Attribute out of range") + " >>> " + detail) {}
};

#endif //SOCIAL_PLANS_MANAGEMENT_INVALIDATTRIBUTEEXCEPTION_H
