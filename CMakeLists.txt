cmake_minimum_required(VERSION 3.4)
project(FeatureDetector CXX)

add_subdirectory(src/x86)
target_include_directories(FeatureDetectorLib PUBLIC src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(FeatureDetector src/Main.cpp)
    target_link_libraries(FeatureDetector PUBLIC FeatureDetectorLib)
endif()
