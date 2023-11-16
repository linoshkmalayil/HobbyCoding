file(REMOVE CMakeFiles)
file(REMOVE MakeFile)
file(REMOVE CMakeCache.txt)
file(REMOVE cmake_install.cmake)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

project(TicTacToe)

include_directories(
    states
    board_renderer
    ttt_logic
)
message(CMAKE_CXX_COMPILER="${CMAKE_CXX_COMPILER}")

if(${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/x86_64-w64-mingw32-g++")
    set(EXECNAME ${PROJECT_NAME}_win64)
    message("NOTE:Binary will be generated in the '../bin' directory of build location, run ../bin/TicTacToe_win64.exe to execute")
else()
    message("NOTE:Binary will be generated in the '../bin' directory of build location, run ../bin/TicTacToe_linux to execute")
    set(EXECNAME ${PROJECT_NAME}_linux)
endif()

add_executable(
    ${EXECNAME}
    game_main.cpp
    board_renderer/render_board.cpp
    ttt_logic/ttt_game.cpp
)
