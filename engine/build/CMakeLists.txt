project (Epoch)
cmake_minimum_required (VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
set(CMAKE_COLOR_MAKEFILE ON)


find_package(SFML REQUIRED system window graphics network audio)
find_package(V8)


set(EPOCH_ROOT "${CMAKE_SOURCE_DIR}/../")
set(EPOCH_HEADERS "${EPOCH_ROOT}/headers")
set(EPOCH_SOURCE "${EPOCH_ROOT}/source")
set(EPOCH_DEPENDENCIES "${EPOCH_ROOT}/dependencies")

set(PROJECT_BINARY_DIR "#{EPOCH_ROOT}/dist")
set(PROJECT_INCLUDE_DIR, "${EPOCH_HEADERS}")
set(PROJECT_SOURCE_DIR ${EPOCH_SOURCE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../dist")

SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost)

INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})

include_directories(${EPOCH_HEADERS})
include_directories(${PROJECT_SOURCE_DIR})

include_directories("${EPOCH_DEPENDENCIES}/linenoise")

set(LINENOISE_SRC "${EPOCH_DEPENDENCIES}/linenoise/linenoise.c")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")


FILE(GLOB EPOCH_SOURCE_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(epoch ${EPOCH_SOURCE_FILES} ${LINENOISE_SRC})

target_link_libraries(epoch ${SFML_LIBRARIES}
                            ${V8_LIBRARIES}
                            ${Boost_LIBRARIES})
