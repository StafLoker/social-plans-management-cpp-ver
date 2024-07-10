#ifndef SOCIAL_PLANS_MANAGEMENT_ADDACTIVITYTOPLAN_H
#define SOCIAL_PLANS_MANAGEMENT_ADDACTIVITYTOPLAN_H

#include "../Command.h"

#include "../../../services/PlanService.h"
#include "../../../services/Session.h"
#include "../../View.h"

class AddActivityToPlan : public Command {
private:
    const string VALUE = "create-user";
    const string PARAMETER_HELP = "<name>;<password>;<age>;<mobile>";
    const string COMMENT_HELP = "Register new user";

    Session *session;
    PlanService *planService;
    View *view;

public:
    AddActivityToPlan(Session *session, PlanService *planService, View *view) : session(session), planService(planService), view(view) {}

    void execute(const string *values) override;

    string &value() override;

    string &helpParameters() override;

    string &helpComment() override;{

};


#endif //SOCIAL_PLANS_MANAGEMENT_ADDACTIVITYTOPLAN_H
