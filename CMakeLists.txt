cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(de_app)

add_definitions('-g')
add_definitions('-Wall')
#add_definitions('-std=c++11')

include_directories(include)

add_executable(${PROJECT_NAME} main.cpp DiffEqSolver.cpp)

