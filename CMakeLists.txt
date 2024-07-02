# Minimum CMake configuration required
cmake_minimum_required(VERSION 3.27)

# Set C++ language version
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall")

###########
# Project #
###########

# Name and Version
project(social_plans_management VERSION 0.0.1)

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
)

# Add main executable
add_executable(social_plans_management ${SOURCES})

################
# Dependencies #
################