cmake_minimum_required(VERSION 3.15)
project(Buffer2 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(include/utils)
include_directories(test/src)

add_library(Buffer
        src/utils/map.c
        src/utils/stack.c
        src/utils/utils.c
        src/buffer.c
        include/utils/map.h
        include/utils/pair.h
        include/utils/stack.h
        include/utils/utils.h
        include/buffer.h)

add_executable(Bufferexe
        test/src/buddy.test.c
        src/utils/map.c
        src/utils/stack.c
        src/utils/utils.c
        src/buffer.c
        include/utils/map.h
        include/utils/pair.h
        include/utils/stack.h
        include/utils/utils.h
        include/buffer.h)

