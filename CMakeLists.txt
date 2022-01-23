cmake_policy(SET CMP0048 NEW) # set version in project
project(openapi_custom_json_example VERSION 0.0.1 LANGUAGES CXX)

cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 20) # shared pointer for []char

message(STATUS "Fetching openapi-runtime")
include(FetchContent)
FetchContent_Declare(openapi_runtime
  GIT_REPOSITORY https://github.com/cpp-openapi/runtime.git
  GIT_TAG e2c99d9e510fc9f493df690ef9106c43c7997018)
# only support wchar for now
set(OPENAPI_UTF16_STRINGS ON CACHE BOOL "" FORCE)
FetchContent_GetProperties(openapi_runtime)
if(NOT json_POPULATED)
  FetchContent_Populate(openapi_runtime)
  add_subdirectory(${openapi_runtime_SOURCE_DIR} ${openapi_runtime_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

message(STATUS "Fetching nlohmann json")
include(FetchContent)
FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.4)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# json dep end

file(GLOB SOURCES
    include/*.h
    src/*.cpp
)

add_library(custom_json
  STATIC ${SOURCES})

target_include_directories(
    custom_json
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(custom_json
  PUBLIC openapi_json
  PUBLIC nlohmann_json::nlohmann_json
)

# tests
# import google test
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
message(STATUS "Fetching googletest")
FetchContent_MakeAvailable(googletest)
enable_testing()
add_subdirectory(test)