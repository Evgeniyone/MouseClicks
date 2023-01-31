cmake_minimum_required(VERSION 3.5)

project(
  MouseClicks
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

set(PROJECT_SOURCES source/main.cpp source/mainwindow.cpp source/mainwindow.h
                    source/mainwindow.ui)

add_executable(MouseClicks ${PROJECT_SOURCES})

target_link_libraries(MouseClicks PRIVATE Qt6::Widgets)
