cmake_minimum_required(VERSION 3.21)
project(appointmentSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(appointmentSystem appointmentSystem.cpp identity.cpp identity.h student.cpp student.h teacher.cpp teacher.h manager.cpp manager.h globalFile.cpp globalFile.h computerRoom.cpp computerRoom.h orderFile.cpp orderFile.h)
