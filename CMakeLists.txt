cmake_minimum_required(VERSION 3.14)
project(AutonomousVehicleSimulator)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(Simulator
    main.cpp
    MainWindow.cpp
    Logger.cpp
    Vehicle.cpp
    DecisionMaker.cpp
)

target_link_libraries(Simulator
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)