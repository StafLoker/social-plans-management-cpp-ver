#ifndef SOCIAL_PLANS_MANAGEMENT_LOGIN_H
#define SOCIAL_PLANS_MANAGEMENT_LOGIN_H


#include "../Command.h"

#include "../../../services/UserService.h"
#include "../../../services/Session.h"
#include "../../View.h"

class Login : public Command {
private:
    const string VALUE = "login";
    const string PARAMETER_HELP = "<username>;<password>";
    const string COMMENT_HELP = "Login to the system";

    View *view;
    UserService *userService;
    Session *session;

public:
    Login(View *view, UserService *userService, Session *session) : view(view), userService(userService), session(session) {}

    void execute(const string *values) override;

    string &value() override;

    string &helpParameters() override;

    string &helpComment() override;
};


#endif //SOCIAL_PLANS_MANAGEMENT_LOGIN_H
