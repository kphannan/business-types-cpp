set(PROJECT_NAME GraphX)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE APP_SRC_FILES app/src/main/cpp/src/*.cpp)

add_executable(${PROJECT_NAME} src/main/cpp/src/foo.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE libs::Lib1)
target_link_libraries(${PROJECT_NAME} PRIVATE libs::Lib2)
