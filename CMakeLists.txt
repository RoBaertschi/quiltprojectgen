cmake_minimum_required(VERSION 3.5)

project(quiltprojectgen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Clone.cpp
)
target_include_directories(${PROJECT_NAME}
    PRIVATE include
)

include(CTest)

add_test(NAME BasicFunctionality COMMAND ${PROJECT_NAME} test/CTest -d -r)

# add_test(NAME CloningInFilledRepo COMMAND ${PROJECT_NAME} test/CTest)
# set_property(TEST CloningInFilledRepo PROPERTY WILL_FAIL true)

install(TARGETS ${PROJECT_NAME} CONFIGURATIONS Release DESTINATION bin)
include(CPack)

