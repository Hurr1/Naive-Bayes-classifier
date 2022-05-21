cmake_minimum_required(VERSION 3.16.3)
project(NaiveBayes)

add_subdirectory(CSVRow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC CSVRow)
target_link_directories(${PROJECT_NAME} PUBLIC CSVRow)
target_link_libraries(${PROJECT_NAME} CSVRow)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


