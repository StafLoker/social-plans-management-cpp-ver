#ifndef SOCIAL_PLANS_MANAGEMENT_DEPENDENCYINJECTION_H
#define SOCIAL_PLANS_MANAGEMENT_DEPENDENCYINJECTION_H

#include "data/daos/UserRepository.h"
#include "data/daos/PlanRepository.h"
#include "data/daos/ActivityRepository.h"
#include "data/daos/map/UserRepositoryMap.h"
#include "data/daos/map/PlanRepositoryMap.h"
#include "data/daos/map/ActivityRepositoryMap.h"

#include "services/Session.h"
#include "services/UserService.h"
#include "services/PlanService.h"
#include "services/ActivityService.h"

#include "console/View.h"
#include "console/ViewConsole.h"
#include "console/ErrorHandler.h"
#include "console/CommandLineInterface.h"
#include "console/commands/user/CreateUser.h"
#include "console/commands/user/Login.h"
#include "console/commands/user/Logout.h"
#include "console/commands/activity/CreateActivity.h"
// #include "console/commands/plan/"

class DependencyInjection {
private:
    static const DependencyInjection dependencyInjection;

    UserRepository userRepository = UserRepositoryMap();
    PlanRepository planRepository = PlanRepositoryMap();
    ActivityRepository activityRepository = ActivityRepositoryMap();

    Session session;
    UserService userService = UserService(&userRepository, &session);
    PlanService planService = PlanService(&planRepository, &activityRepository, &session);
    ActivityService activityService = ActivityService(&activityRepository);

    View view = ViewConsole();
    CommandLineInterface commandLineInterface = CommandLineInterface(&session, &view);
    ErrorHandler errorHandler = ErrorHandler(&commandLineInterface, &view);

    DependencyInjection() {
        this->commandLineInterface.add(new CreateUser(&view, &userService));
        this->commandLineInterface.add(new Login(&view, &userService, &session));
        this->commandLineInterface.add(new Logout(&userService));
        this->commandLineInterface.add(new CreateActivity(&view, &activityService, &session));
        // add plan commands
    }

public:
    static DependencyInjection getDependencyInjection() {
        return dependencyInjection;
    }

    void run() {
        this->errorHandler.runErrorManager();
    }
};

#endif //SOCIAL_PLANS_MANAGEMENT_DEPENDENCYINJECTION_H
