
file(GLOB SOURCES
*_test.cpp
)

# strip file extension
foreach(test_file ${SOURCES})
get_filename_component(test_name ${test_file} NAME_WE)

# if(NOT ${test_name} STREQUAL "openapi_json2_test")
#     continue()
# endif()

add_executable(${test_name} ${test_file})

# custom json
target_compile_definitions(${test_name} PRIVATE OPENAPI_CUSTOM_JSON=1)

# common libs
target_link_libraries(${test_name} PRIVATE gtest_main openapi_json openapi_runtime)

# my lib includes dep of nlomann json
target_link_libraries(${test_name} PRIVATE custom_json)

# openapi test needed
if(NOT OPENAPI_JSON STREQUAL "OPENAPI_NLOHMANNJSON")
    target_link_libraries(${test_name} PRIVATE openapi_nlohmann_json) # nlohmann json is always needed for test
endif()

# openapi test json dir
target_include_directories(
    ${test_name}
    PUBLIC
    ${openapi_runtime_SOURCE_DIR}/json/test
)

add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endforeach()

