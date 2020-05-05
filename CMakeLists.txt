cmake_minimum_required(VERSION 3.16)
project(showkeys C)

set(CMAKE_C_STANDARD 11)

add_compile_definitions(SK_NO_REPEATS)
#add_compile_definitions(DEBUG)

include_directories(.)

#target_include_directories(showkeys /usr/include)

add_executable(showkeys
        config.h
        keystack.c
        keystack.h
        showkeys.c
        showkeys.h)

target_link_libraries(showkeys -lX11 -lxosd -lpthread -lXext -lX11 -lXinerama -lXtst)