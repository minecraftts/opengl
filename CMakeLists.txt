cmake_minimum_required(VERSION 3.9)
cmake_policy(SET CMP0042 NEW)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(opengl)

set(SOURCE "src/bindings.cc")
add_definitions(-DNAPI_EXPERIMENTAL)

include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC})

add_library(${PROJECT_NAME} SHARED ${SOURCE} ${CMAKE_JS_SRC})

add_subdirectory(deps/glew-cmake)

option(glew-cmake_BUILD_SHARED OFF) 
option(ONLY_LIBS ON)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
target_link_libraries(${PROJECT_NAME} libglew_static)
target_include_directories(${PROJECT_NAME} PRIVATE deps/glew-cmake/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})
