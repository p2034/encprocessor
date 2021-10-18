cmake_minimum_required(VERSION 3.8)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# expected behaviour
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++lastest")

project(MY_PROJECT)

# add your .cpp files here
add_executable(test.out main.cpp tests/tests.cpp src/error/error.cpp src/crypto/aes.cpp src/core/iedata.cpp src/core/oedata.cpp src/core/iefile.cpp src/core/oefile.cpp)

target_link_libraries(test.out)