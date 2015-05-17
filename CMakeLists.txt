cmake_minimum_required(VERSION 2.8.11)

project(SIA)

# Qt Directory
set(CMAKE_PREFIX_PATH "/opt/Qt5.3.0/5.3/gcc_64/")

# Libs Include
include_directories(/usr/lib)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# C++ Support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Boost REQUIRED COMPONENTS thread filesystem system regex REQUIRED)

# Tell CMake to create the helloworld executable
add_executable(sia library/md5.cpp config.cpp formlogin.cpp main.cpp mainwindow.cpp)

# Use the Widgets module from Qt 5.
target_link_libraries(sia Qt5::Widgets ${Boost_LIBRARIES} mongoclient pthread boost_thread boost_system boost_regex boost_filesystem ssl crypto)
