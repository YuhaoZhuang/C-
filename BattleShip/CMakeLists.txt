cmake_minimum_required(VERSION 3.13)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(BATTLESHIP_COMPILE_OPTIONS -Wall -Werror)

add_executable(BattleShip main.cpp board.cpp board.h)