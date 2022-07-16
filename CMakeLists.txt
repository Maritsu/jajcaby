cmake_minimum_required(VERSION 3.0.0)
project(jajcaby VERSION 0.0.0)

add_executable(bin/debug/jajcaby src/main.cpp)

target_link_libraries(bin/debug/jajcaby SDL2main SDL2 GL)
