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
set(SOURCES src/main.cpp)

# Add main executable
add_executable(social_plans_management ${SOURCES})

################
# Dependencies #
################