cmake_minimum_required(VERSION 3.21)
project(Pokemon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pokemon main.cpp pokemon.cpp pokemon.h pokemon_database.cpp pokemon_database.h move_database.cpp move_database.h move_struct.cpp move_struct.h trainers_database.cpp trainers_database.h trainers_struct.cpp trainers_struct.h pokemon_battle.h pokemon_battle.cpp external_functions.h external_functions.cpp)
