cmake_minimum_required(VERSION 3.26)

project(QtContainer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets WebChannel WebSockets WebEngineWidgets REQUIRED)

add_executable(QtContainer
    main.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    resources.qrc
    websockettransport.h websockettransport.cpp
    websocketclientwrapper.h websocketclientwrapper.cpp
    containerapi.h containerapi.cpp
)

target_link_libraries(QtContainer Qt5::Widgets Qt5::WebChannel Qt5::WebSockets Qt5::WebEngineWidgets)
