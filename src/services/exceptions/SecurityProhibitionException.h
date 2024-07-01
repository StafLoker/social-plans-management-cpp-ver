#ifndef SOCIAL_PLANS_MANAGEMENT_SECURITYPROHIBITIONEXCEPTION_H
#define SOCIAL_PLANS_MANAGEMENT_SECURITYPROHIBITIONEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class SecurityProhibitionException : public logic_error {
public:
    explicit SecurityProhibitionException(const string &detail) : logic_error(
            string("Security Authorization Exception. You are not registered") + " >>> " + detail) {}
};

#endif //SOCIAL_PLANS_MANAGEMENT_SECURITYPROHIBITIONEXCEPTION_H
