
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "greatest.h"
#include "stack.h"

SUITE_EXTERN(other_suite);

SUITE(suite);

TEST stack_assertions(void) {
    STACK *stack = new_stack();
    ASSERT(stack->size == 0);
    push_stack(stack, 0, 2);
    ASSERT(stack->size == 1);
    push_stack(stack, 0, 2);
    ASSERT(stack->size == 2);
    push_stack(stack, 0, 2);
    ASSERT(stack->size == 3);
    push_stack(stack, 0, 2);
    ASSERT(stack->size == 4);
    ASSERT(pop_stack(stack)->lower_bound == 0);
    ASSERT(stack->size == 3);
    push_stack(stack, 37, 38);
    ASSERT(stack->size == 4);
    ASSERT(pop_stack(stack)->lower_bound == 37);
    ASSERT(stack->size == 3);
    ASSERT(pop_stack(stack)->lower_bound == 0);
    ASSERT(stack->size == 2);
    ASSERT(pop_stack(stack)->lower_bound == 0);
    ASSERT(stack->size == 1);
    ASSERT(pop_stack(stack)->lower_bound == 0);
    ASSERT(stack->size == 0);
    ASSERT(pop_stack(stack) == NULL);
    ASSERT(stack->size == 0);
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv){
    GREATEST_MAIN_BEGIN();
    RUN_TEST(stack_assertions);
    GREATEST_MAIN_END();
    return 0;
}

