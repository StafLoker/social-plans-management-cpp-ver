#ifndef SOCIAL_PLANS_MANAGEMENT_CREATEACTIVITY_H
#define SOCIAL_PLANS_MANAGEMENT_CREATEACTIVITY_H

#include "../Command.h"

#include "../../../services/ActivityService.h"
#include "../../../services/Session.h"
#include "../../View.h"

class CreateActivity : public Command {
private:
    const string VALUE = "create-activity";
    const string PARAMETER_HELP = "<type: Generic, Theatre, Cinema>, <name>;<description>;<duration: minutes>;<cost>;<<capacity>>";
    const string COMMENT_HELP = "Create a new activity";

    View *view;
    ActivityService *activityService;
    Session *session;

public:
    CreateActivity(View *view, ActivityService *activityService, Session *session) : view(view), activityService(activityService),
                                                                                     session(session) {}

    void execute(const string *values) override;

    string &value() override;

    string &helpParameters() override;

    string &helpComment() override;

};


#endif //SOCIAL_PLANS_MANAGEMENT_CREATEACTIVITY_H
