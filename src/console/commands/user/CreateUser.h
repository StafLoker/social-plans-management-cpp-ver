#ifndef SOCIAL_PLANS_MANAGEMENT_CREATEUSER_H
#define SOCIAL_PLANS_MANAGEMENT_CREATEUSER_H


#include "../Command.h"

#include "../../../services/UserService.h"
#include "../../View.h"

class CreateUser : public Command {
private:
    const string VALUE = "create-user";
    const string PARAMETER_HELP = "<name>;<password>;<age>;<mobile>";
    const string COMMENT_HELP = "Register new user";

    View *view;
    UserService *userService;

public:
    CreateUser(View *view, UserService *userService) : view(view), userService(userService) {}

    void execute(const string *values) override;

    string &value() override;

    string &helpParameters() override;

    string &helpComment() override;
};


#endif //SOCIAL_PLANS_MANAGEMENT_CREATEUSER_H
