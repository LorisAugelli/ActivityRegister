cmake_minimum_required(VERSION 3.28)
project(ActivityRegister)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

find_package(wxWidgets REQUIRED core net base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

set(SOURCE_FILES
        Activity.h
        Register.h
        Register.cpp)

add_executable(ActivityRegister
        Activity.h
        Register.h
        Register.cpp
        MainFrame.cpp
        MainFrame.h
        App.cpp
        App.h)
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(ActivityRegister ${wxWidgets_LIBRARIES} ${CMAKE_PROJECT_NAME}_lib)