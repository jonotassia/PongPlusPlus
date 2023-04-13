cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PongPlusPlus)

find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
find_library(SDL2_LIBRARY NAME SDL2)

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

# Set the directories that should be included in the build command for this target

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
 