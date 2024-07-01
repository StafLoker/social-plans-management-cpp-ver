#ifndef SOCIAL_PLANS_MANAGEMENT_NOTFOUNDEXCEPTION_H
#define SOCIAL_PLANS_MANAGEMENT_NOTFOUNDEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class NotFoundException : public logic_error {
public:
    explicit NotFoundException(const string &detail) : logic_error(
            string("Not Found Exception. The object does not exist") + " >>> " + detail) {}
};

#endif //SOCIAL_PLANS_MANAGEMENT_NOTFOUNDEXCEPTION_H
