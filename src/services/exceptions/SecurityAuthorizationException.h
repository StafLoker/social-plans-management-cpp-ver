#ifndef SOCIAL_PLANS_MANAGEMENT_SECURITYAUTHORIZATIONEXCEPTION_H
#define SOCIAL_PLANS_MANAGEMENT_SECURITYAUTHORIZATIONEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class SecurityAuthorizationException : public logic_error {
public:
    explicit SecurityAuthorizationException(const string &detail) : logic_error(
            string("Security Prohibition Exception. You are not authorized") + " >>> " + detail) {}
};

#endif //SOCIAL_PLANS_MANAGEMENT_SECURITYAUTHORIZATIONEXCEPTION_H
