cmake_minimum_required(VERSION 3.16)

project(CaesarsEncryption VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Widgets)

qt_standard_project_setup(REQUIRES 6.5)

# Define your sources
set(SOURCES
        src/main.cpp
        src/core/AffineCipher.cpp
        src/core/FileHandler.cpp
        src/controllers/ApplicationController.cpp
)

set(HEADERS
        src/core/AffineCipher.h
        src/core/FileHandler.h
        src/controllers/ApplicationController.h
)

# Add the executable with all your sources
qt_add_executable(appCaesarsEncryption
        ${SOURCES}
        ${HEADERS}
)

# Add QML module
qt_add_qml_module(appCaesarsEncryption
        URI CaesarsEncryption
        VERSION 1.0
        QML_FILES qml/Main.qml
)

# Set properties for the app
set_target_properties(appCaesarsEncryption PROPERTIES
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

# Link Qt libraries
target_link_libraries(appCaesarsEncryption
        PRIVATE Qt6::Quick Qt6::Widgets
)

# Installation
include(GNUInstallDirs)
install(TARGETS appCaesarsEncryption
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_add_resources(appCaesarsEncryption "resources"
        PREFIX "/"
        FILES
        qml/Main.qml
)