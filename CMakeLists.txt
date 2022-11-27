cmake_minimum_required(VERSION 3.22)
project(responsive)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.5_1")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(responsive  main.cpp
        responsive_label.cpp
        responsive_label.h
        responsive_layout.cpp
        responsive_layout.h
        responsive_window.cpp
        responsive_window.h
        screenshot.cpp
        screenshot.h scroll_layout.cpp scroll_layout.h scroll_layout1.cpp scroll_layout1.h)
target_link_libraries(responsive
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
