cmake_minimum_required(VERSION 3.6)
project(JsonRepository)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Werror -std=c++11")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

find_package(GTest REQUIRED)
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(JsonRepositoryTests test/test.cpp)
target_link_libraries(JsonRepositoryTests ${GTEST_BOTH_LIBRARIES})

set(SOURCE_FILES src/main.cpp src/Domain/Foo.cpp src/Domain/Foo.h src/Repository/Repository.h src/Repository/JsonRepository/FooJsonRepository.cpp src/Repository/JsonRepository/FooJsonRepository.h src/Libraries/json.hpp src/Repository/JsonRepository/JsonRepository.hpp)
add_executable(JsonRepository ${SOURCE_FILES})