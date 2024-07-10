#ifndef SOCIAL_PLANS_MANAGEMENT_LOGOUT_H
#define SOCIAL_PLANS_MANAGEMENT_LOGOUT_H


#include "../Command.h"
#include "../../../services/UserService.h"

class Logout : public Command {
private:
    const string VALUE = "logout";
    const string PARAMETER_HELP;
    const string COMMENT_HELP = "Ends the session";

    UserService *userService;

public:
    explicit Logout(UserService *userService) : userService(userService) {}

    void execute(const string *values) override;

    string &value() override;

    string &helpParameters() override;

    string &helpComment() override;
};


#endif //SOCIAL_PLANS_MANAGEMENT_LOGOUT_H
