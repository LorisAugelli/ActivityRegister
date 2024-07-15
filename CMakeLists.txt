cmake_minimum_required(VERSION 3.28)
project(ActivityRegister)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED core net base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_executable(ActivityRegister
        Activity.h
        Register.h
        Register.cpp
        MainFrame.cpp
        MainFrame.h
        App.cpp
        App.h)

target_link_libraries(ActivityRegister ${wxWidgets_LIBRARIES})