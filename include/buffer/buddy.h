#ifndef STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #define STD
#endif

#include "stack.h"
#include "map.h"
#include "utils.h"

#define BYTE(x) x
#define KBYTE(x) BYTE(x) * 1024
#define MBYTE(x) KBYTE(x) * 1024
#define GBYTE(x) MBYTE(x) * 1024

#define INITIAL_MEMORY_SIZE MBYTE(1)


void init_buddy();
void *balloc(int n);
void bfree(int n);