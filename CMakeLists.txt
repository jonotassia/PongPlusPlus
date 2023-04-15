cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PongPlusPlus)

# Needed so that cmake uses our find modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Create an option to switch between a system sdl library and a vendored sdl library
option(MYGAME_VENDORED "Use vendored libraries" OFF)

if(MYGAME_VENDORED)
    add_subdirectory(vendored/sdl EXCLUDE_FROM_ALL)
else()
    # 1. Look for a SDL2 package, 2. look for the SDL2 component and 3. fail if none can be found
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
    
    # 1. Look for a SDL2 package, 2. Look for the SDL2maincomponent and 3. DO NOT fail when SDL2main is not available 
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

    # Look for SDL ttf
    find_package(SDL2_ttf REQUIRED)
endif()

include_directories(${CMAKE_SOURCE_DIR}/headers)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp 
    src/game.cpp 
    src/control.cpp 
    src/render.cpp 
    src/ball.cpp 
    src/paddle.cpp 
    src/player.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications  
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::Main SDL2::TTF)