cmake_minimum_required(VERSION 3.6)
project(JsonRepository)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Domain/Foo.cpp src/Domain/Foo.h src/Repository/Repository.h src/Repository/JsonRepository/FooJsonRepository.cpp src/Repository/JsonRepository/FooJsonRepository.h src/Libraries/json.hpp src/Repository/JsonRepository/JsonRepository.hpp)
add_executable(JsonRepository ${SOURCE_FILES})