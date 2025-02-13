cmake_minimum_required(VERSION 3.31.5)

set(PROJECT_NAME GraphBase)

project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DOWNLOAD_EXTRACT_TIMESTAMP true)

add_subdirectory(app)
add_subdirectory(libs)

# ----- Unit Test Framework -----

# Fetch Google Test as needed
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 6910c9d9165801d8827d628cb72eb7ea9dd538c5 # release-1.16.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# # ## Unit Testing with Google Test
# enable_testing()
