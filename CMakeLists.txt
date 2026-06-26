cmake_minimum_required(VERSION 4.2)
project(cflow)

set(CMAKE_CXX_STANDARD 20)

add_executable(cflow
        src/main.cpp
        src/analyzer/analyzer.hpp
        src/checker/checker.hpp
        src/analyzer/analyzer.cpp
        src/call_graph/graph.hpp
        src/call_graph/graph.cpp
)
