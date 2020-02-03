
#include "stack.h"

STACK *new_stack(){
    STACK *stack = calloc(sizeof(STACK), 1);
    stack->size = 0;
    stack->head = NULL;
    stack->tail = NULL;
    return stack;
}


int push_stack(STACK *stack, int lower_bound, int upper_bound){
    PAIR *pair = calloc(sizeof(PAIR), 1);
    pair->lower_bound = lower_bound;
    pair->upper_bound = upper_bound;

    pair->next = stack->head;
    stack->head = pair;
    if(stack->size == 0) stack->tail = pair;

    stack->size++;

    return stack->size;
}


PAIR *pop_stack(STACK *stack){
    if(stack->size == 0) return NULL;
    stack->size--;
    PAIR *p = stack->head;
    stack->head = p->next;
    return p;
}