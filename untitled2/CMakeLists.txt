cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 container.c container.h train.c train.h ship.c ship.h plane.c plane.h random.c random.h file_work.c file_work.h timer.c timer.h transport.c transport.h main.c exceptions.c exceptions.h)
