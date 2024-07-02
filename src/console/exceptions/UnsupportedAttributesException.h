#ifndef SOCIAL_PLANS_MANAGEMENT_UNSUPPORTEDATTRIBUTESEXCEPTION_H
#define SOCIAL_PLANS_MANAGEMENT_UNSUPPORTEDATTRIBUTESEXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class UnsupportedAttributesException : public logic_error {
public:
    explicit UnsupportedAttributesException(const string &detail) : logic_error(
            string("Unsupported Attributes Exception. The entered attributes are incorrect") + " >>> " + detail) {}
};

#endif //SOCIAL_PLANS_MANAGEMENT_UNSUPPORTEDATTRIBUTESEXCEPTION_H
