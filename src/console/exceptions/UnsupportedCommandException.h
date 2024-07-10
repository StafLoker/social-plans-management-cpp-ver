#ifndef SOCIAL_PLANS_MANAGEMENT_UNSUPPORTEDCOMMANDEXCEPTION_H
#define SOCIAL_PLANS_MANAGEMENT_UNSUPPORTEDCOMMANDEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class UnsupportedCommandException : public logic_error {
public:
    explicit UnsupportedCommandException(const string &detail) : logic_error(
            string("Unsupported Command Exception. The entered command does not exist") + " >>> " + detail) {}
};

#endif //SOCIAL_PLANS_MANAGEMENT_UNSUPPORTEDCOMMANDEXCEPTION_H
