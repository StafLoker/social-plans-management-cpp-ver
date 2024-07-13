# Minimum CMake configuration required
cmake_minimum_required(VERSION 3.30)

# Set C++ language version
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall")

###########
# Project #
###########

set(PROJECT_NAME social_plans_management)

# Name and Version
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

# Variables
set(SOURCES src/main.cpp
        src/data/models/User.cpp
        src/data/models/User.h
        src/data/models/exceptions/InvalidAttributeException.h
        src/data/models/spm/Activity.cpp
        src/data/models/spm/Activity.h
        src/data/models/spm/activityTypes/Theater.cpp
        src/data/models/spm/activityTypes/Theater.h
        src/data/daos/GenericRepository.h
        src/data/daos/UserRepository.h
        src/data/daos/ActivityRepository.h
        src/data/models/spm/Plan.cpp
        src/data/models/spm/Plan.h
        src/data/models/spm/activityTypes/Cinema.cpp
        src/data/models/spm/activityTypes/Cinema.h
        src/data/daos/PlanRepository.h
        src/data/daos/map/ActivityRepositoryMap.cpp
        src/data/daos/map/ActivityRepositoryMap.h
        src/data/daos/map/PlanRepositoryMap.cpp
        src/data/daos/map/PlanRepositoryMap.h
        src/data/daos/map/UserRepositoryMap.cpp
        src/data/daos/map/UserRepositoryMap.h
        src/data/daos/map/GenericRepositoryMap.cpp
        src/data/daos/map/GenericRepositoryMap.h
        src/services/Session.cpp
        src/services/Session.h
        src/services/UserService.cpp
        src/services/UserService.h
        src/services/PlanService.cpp
        src/services/PlanService.h
        src/services/ActivityService.cpp
        src/services/ActivityService.h
        src/services/exceptions/DuplicateException.h
        src/services/exceptions/NotFoundException.h
        src/services/exceptions/SecurityAuthorizationException.h
        src/services/exceptions/SecurityProhibitionException.h
        src/console/CommandLineInterface.cpp
        src/console/CommandLineInterface.h
        src/console/commands/Command.h
        src/console/ErrorHandler.cpp
        src/console/ErrorHandler.h
        src/console/ViewConsole.cpp
        src/console/ViewConsole.h
        src/console/View.h
        src/console/exceptions/UnsupportedAttributesException.h
        src/console/exceptions/UnsupportedCommandException.h
        src/console/commands/user/CreateUser.cpp
        src/console/commands/user/CreateUser.h
        src/console/commands/user/Login.cpp
        src/console/commands/user/Login.h
        src/console/commands/user/Logout.cpp
        src/console/commands/user/Logout.h
        src/console/commands/activity/CreateActivity.cpp
        src/console/commands/activity/CreateActivity.h
        src/DependencyInjection.h
        src/console/commands/plan/crud/CreatePlan.cpp
        src/console/commands/plan/crud/CreatePlan.h
        src/console/commands/plan/crud/DeletePlan.cpp
        src/console/commands/plan/crud/DeletePlan.h
        src/console/commands/plan/list/AvailablePlans.cpp
        src/console/commands/plan/list/AvailablePlans.h
        src/console/commands/plan/list/CostRangePlans.cpp
        src/console/commands/plan/list/CostRangePlans.h
        src/console/commands/plan/list/PlansContainingKeyword.cpp
        src/console/commands/plan/list/PlansContainingKeyword.h
        src/console/commands/plan/list/SubscribedPlans.cpp
        src/console/commands/plan/list/SubscribedPlans.h
        src/console/commands/plan/list/WeekendPlans.cpp
        src/console/commands/plan/list/WeekendPlans.h
        src/console/commands/plan/AddActivityToPlan.cpp
        src/console/commands/plan/AddActivityToPlan.h
        src/console/commands/plan/EnrollSubscriber.cpp
        src/console/commands/plan/EnrollSubscriber.h
        src/console/commands/plan/GetPlanDuration.cpp
        src/console/commands/plan/GetPlanDuration.h
        src/console/commands/plan/GetPlanPrice.cpp
        src/console/commands/plan/GetPlanPrice.h
)

# Add main executable
add_executable(${PROJECT_NAME} ${SOURCES})

#########
# Tests #
#########

include(CTest)
enable_testing()

################
# Dependencies #
################