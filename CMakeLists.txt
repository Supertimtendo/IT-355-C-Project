cmake_minimum_required(VERSION 3.24)
project(it355)

set(CMAKE_CXX_STANDARD 17)

add_executable(it355 main.c account.c account.h bank.c bank.h)
