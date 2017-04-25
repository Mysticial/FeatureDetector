cmake_minimum_required(VERSION 3.4)
project(FeatureDetector CXX)

add_subdirectory(src/x86)
add_executable(FeatureDetector_main src/Main.cpp)
target_link_libraries(FeatureDetector_main FeatureDetector)
