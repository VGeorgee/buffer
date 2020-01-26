#ifndef STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #define STD
#endif

#include "pair.h"

typedef struct stack
{
    PAIR *head;
    PAIR *tail;
    int size;
} STACK;

STACK *new_stack();
int push_stack(STACK *stack, int lower_bound, int upper_bound);
PAIR *pop_stack(STACK *stack);