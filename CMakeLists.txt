cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(VideoEncoder
  VERSION 0.0.1
  DESCRIPTION "VideoEncoder"
  LANGUAGES C CXX)
set(TARGET_NAME "VideoEncoder")
set(DEFAULT_BUILD_TYPE "Release")

#stNDARD STUFF
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS_COMMON}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(OpenCV REQUIRED)
#include fix for OpenCV
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

set(SRC
    src/main.cc

    src/fitnesscalculation.cc
    src/fitness/basefitness.h
    src/fitness/basefitness.cc
    src/fitness/bgfitness.cc
    src/fitness/bgfitness.h
    src/fitness/none.cc
    src/fitness/none.h

    ../../IncludeSpdlog/spdlog.cc
)

set(HEADERS
    src/fitnesscalculation.h
    ../../IncludeSpdlog/spdlog.h
)

add_executable(${TARGET_NAME}
    ${SRC}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core ${OpenCV_LIBS} Threads::Threads )
