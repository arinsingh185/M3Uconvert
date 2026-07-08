cmake_minimum_required(VERSION 3.19)
project(M3Uconvert LANGUAGES CXX)

# Enforce standard compiler configurations explicitly
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt6 Packages
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# Native executable creation using explicit absolute path tracking
add_executable(M3Uconvert WIN32 MACOSX_BUNDLE 
    "${CMAKE_CURRENT_SOURCE_DIR}/M3Uconvert/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/M3Uconvert/MainWindow.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/M3Uconvert/MainWindow.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/M3Uconvert/m3uconvert.ui"
)


# Link the libraries 
target_link_libraries(M3Uconvert PRIVATE Qt6::Core Qt6::Widgets)

# Installation configuration
include(GNUInstallDirs)
install(TARGETS M3Uconvert 
    BUNDLE DESTINATION . 
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} 
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET M3Uconvert
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
