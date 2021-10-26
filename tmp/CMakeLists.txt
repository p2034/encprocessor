cmake_minimum_required(VERSION 3.8)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# expected behaviour
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++lastest")

project(ENCPROCESSOR)

# add your .cpp files here
add_executable(test.out ../tests/main.cpp ../tests/tests.cpp ../src/encprocessor/crypto/aes.cpp
                                                             ../src/encprocessor/core/encdata.cpp
                                                             ../src/encprocessor/core/encfile.cpp)

target_include_directories(test.out PUBLIC ../src/encprocessor)

target_link_libraries(test.out)