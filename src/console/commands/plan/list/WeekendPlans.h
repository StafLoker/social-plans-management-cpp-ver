#ifndef SOCIAL_PLANS_MANAGEMENT_WEEKENDPLANS_H
#define SOCIAL_PLANS_MANAGEMENT_WEEKENDPLANS_H

#include "../../Command.h"

#include "../../../../services/PlanService.h"
#include "../../../../services/Session.h"
#include "../../../View.h"

class WeekendPlans : public Command {
private:
    const string VALUE = "create-user";
    const string PARAMETER_HELP = "<name>;<password>;<age>;<mobile>";
    const string COMMENT_HELP = "Register new user";

    Session *session;
    PlanService *planService;
    View *view;

public:
    WeekendPlans(Session *session, PlanService *planService, View *view) : session(session), planService(planService), view(view) {}

    void execute(const string *values) override;

    string &value() override;

    string &helpParameters() override;

    string &helpComment() override;

    {

    };


#endif //SOCIAL_PLANS_MANAGEMENT_WEEKENDPLANS_H
