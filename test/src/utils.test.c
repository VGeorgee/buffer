
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "greatest.h"
#include "utils.h"

SUITE_EXTERN(other_suite);

SUITE(suite);

TEST get_optimal_size_for_tests(void) {
    ASSERT(get_optimal_size_for(1) == 1);
    ASSERT(get_optimal_size_for(2) == 2);
    ASSERT(get_optimal_size_for(3) == 4);
    ASSERT(get_optimal_size_for(4) == 4);
    ASSERT(get_optimal_size_for(5) == 8);
    ASSERT(get_optimal_size_for(7) == 8);
    ASSERT(get_optimal_size_for(8) == 8);
    ASSERT(get_optimal_size_for(9) == 16);
    ASSERT(get_optimal_size_for(15) == 16);
    ASSERT(get_optimal_size_for(16) == 16);
    ASSERT(get_optimal_size_for(17) == 32);
    ASSERT(get_optimal_size_for(31) == 32);
    ASSERT(get_optimal_size_for(32) == 32);
    ASSERT(get_optimal_size_for(33) == 64);
    ASSERT(get_optimal_size_for(62) == 64);
    ASSERT(get_optimal_size_for(64) == 64);
    ASSERT(get_optimal_size_for(65) == 128);
    ASSERT(get_optimal_size_for(128) == 128);
    PASS();
}

GREATEST_MAIN_DEFS();



int main(int argc, char **argv){
    GREATEST_MAIN_BEGIN();

    RUN_TEST(get_optimal_size_for_tests);



    GREATEST_MAIN_END();

    return 0;
}

