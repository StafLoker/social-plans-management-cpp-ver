#ifndef SOCIAL_PLANS_MANAGEMENT_COMMAND_H
#define SOCIAL_PLANS_MANAGEMENT_COMMAND_H

using namespace std;

#include "string"

class Command {
public:
    virtual void execute(const string *values);

    virtual string& value();

    virtual string& helpParameters();

    virtual string& helpComment();
};

#endif //SOCIAL_PLANS_MANAGEMENT_COMMAND_H
