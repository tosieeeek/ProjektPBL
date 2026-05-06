cmake_minimum_required(VERSION 4.0)
project(wisielec)

set(CMAKE_CXX_STANDARD 20)

add_executable(wisielec main.cpp
        HangmanGame.cpp
        HangmanGame.h
        WordManager.cpp
        WordManager.h)
