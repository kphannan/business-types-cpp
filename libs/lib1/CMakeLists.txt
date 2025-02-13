set(PROJECT_NAME Lib1)

project(${PROJECT_NAME})

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/src/*.cpp)

add_library(${PROJECT_NAME} ${SRC_FILES})

add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(${PROJECT_NAME}
    PRIVATE
    cxx_std_23
)

# if(BUILD_TESTING)
add_subdirectory(src/test)

# endif()