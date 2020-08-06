cmake_minimum_required(VERSION 3.1)
project(Calculator)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

# Add sources
file(GLOB SOURCES
    # "${PROJECT_SOURCE_DIR}/src/main.c"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

set(LIB_INC_DIR ${PROJECT_SOURCE_DIR}/lib/include)
set(LIB_LINK_DIR ${PROJECT_SOURCE_DIR}/lib/lib)

# Specify include Directory
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${LIB_INC_DIR}")


link_directories(${LIB_LINK_DIR})

add_executable(Calculator ${SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Calculator Threads::Threads)

target_link_libraries(Calculator libzlog.a)

set_property(TARGET Calculator PROPERTY CXX_STANDARD 11)
set_property(TARGET Calculator PROPERTY CXX_STANDARD_REQUIRED ON)