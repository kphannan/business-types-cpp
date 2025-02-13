set(PROJECT_NAME lib2_unit)

project(${PROJECT_NAME})

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    libs::Lib2
    GTest::gtest_main
)

# ## Unit Testing with Google Test
enable_testing()

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
