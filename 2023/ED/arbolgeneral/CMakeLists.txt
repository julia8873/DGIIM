cmake_minimum_required(VERSION 3.26)
project(arbolgeneral)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(arbolgeneral
        node.tpp
        tree.h
        tree.tpp)
