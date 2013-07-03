project (Epoch)
cmake_minimum_required (VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
set(CMAKE_COLOR_MAKEFILE ON)

find_package(SFML COMPONENTS graphics window system)
find_package(V8)

set(EPOCH_ROOT "${CMAKE_SOURCE_DIR}/../")
set(EPOCH_HEADERS "${EPOCH_ROOT}/headers")
set(EPOCH_SOURCE "${EPOCH_ROOT}/source")

set(PROJECT_BINARY_DIR "#{EPOCH_ROOT}/dist")
set(PROJECT_INCLUDE_DIR, "${EPOCH_HEADERS}")
set(PROJECT_SOURCE_DIR ${EPOCH_SOURCE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../dist")

include_directories(${EPOCH_HEADERS})
include_directories(${PROJECT_SOURCE_DIR})


FILE(GLOB EPOCH_SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(epoch ${EPOCH_SOURCE_FILES})
