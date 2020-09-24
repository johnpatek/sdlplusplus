cmake_minimum_required(VERSION 2.8)

project(sdlplusplus)

if(WIN32)
    list(APPEND EXTRA_LIBS user32 gdi32 winmm imm32 ole32 oleaut32 version uuid advapi32 setupapi shell32 vcruntime)
endif()

add_subdirectory(sdl2)

if(WIN32)
    set(PTHREAD "")
    find_library(SDL2_LIB_NAME SDL2_static.lib PATHS ${PROJECT_BINARY_DIR}/sdl2/Release)
else()
    set(CMAKE_CXX_FLAGS  "-std=c++14")
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)    
    set(PTHREAD Threads::Threads)
    find_library(SDL2_LIB_NAME libSDL2_static.a PATHS ${PROJECT_BINARY_DIR})
endif(WIN32)

file(GLOB SDLPP_SOURCES
    "include/sdlpp/*.h"    
    "include/sdlpp.h"    
    "src/sdlpp/*.cpp"
    "src/sdlpp.cpp")

add_library(
    sdlpp-sdk 
    STATIC
    ${SDLPP_SOURCES})
    
target_include_directories(
    sdlpp-sdk
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/sdl2/include)

target_link_libraries(
    sdlpp-sdk 
    PUBLIC
    ${PTHREAD}
    ${SDL2_LIB_NAME})