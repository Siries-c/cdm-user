cmake_minimum_required(VERSION 3.5)

project(01_UDP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Core Network REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        cudp.h cudp.cpp
        ctcp.h ctcp.cpp
        ctcpudp.h ctcpudp.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(01_UDP
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        cudp.h cudp.cpp
        ctcp.h ctcp.cpp
        ctcpudp.h ctcpudp.cpp
    )
else()
    if(ANDROID)
        add_library(01_UDP SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(01_UDP
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# 这里是修改的部分
target_link_libraries(01_UDP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Core Qt6::Network)

set_target_properties(01_UDP PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS 01_UDP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(01_UDP)
endif()
