cmake_minimum_required(VERSION 3.4)
project(FeatureDetector CXX)

add_subdirectory(src/x86)
add_executable(FeatureDetector_main src/Main.cpp)
target_include_directories(FeatureDetector PUBLIC src)
target_link_libraries(FeatureDetector_main PUBLIC FeatureDetector)
