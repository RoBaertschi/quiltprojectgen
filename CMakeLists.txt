cmake_minimum_required(VERSION 3.5)

project(quiltprojectgen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libgit2)

add_executable(${PROJECT_NAME}
    main.cpp
)
target_link_libraries(libgit2)
