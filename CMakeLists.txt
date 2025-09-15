cmake_minimum_required(VERSION 4.0)
project(RedisKnockoff)

set(CMAKE_CXX_STANDARD 20)

add_executable(RedisKnockoff main.cpp
        main.cpp
        Engine.h
        Engine.cpp
        IndexMap.h
        IndexMap.cpp)
