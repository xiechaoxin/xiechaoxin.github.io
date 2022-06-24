cmake_minimum_required(VERSION 3.21)
project(employeeManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(employeeManagementSystem main.cpp src/workerManager.cpp src/workerManager.h src/worker.cpp src/worker.h src/employee.cpp src/employee.h src/manager.cpp src/manager.h src/boss.cpp src/boss.h)
