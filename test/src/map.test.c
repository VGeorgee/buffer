
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "greatest.h"
#include "map.h"


SUITE_EXTERN(other_suite);

SUITE(suite);

TEST map_tests(void) {

    ASSERT( put_map(0, 2) == 1 );
    ASSERT( get_map(0) == 2 );
    ASSERT( put_map(0, 2) == -1 );
    ASSERT( get_map(0) == 2 );
    ASSERT( remove_map(0) == 2 );
    ASSERT( remove_map(0) == -1 );
    ASSERT( get_map(0) == -1 );
    ASSERT( put_map(0, 2) == 1 );
    ASSERT( get_map(0) == 2 );

    ASSERT( put_map(17, 28) == 1 );
    ASSERT( get_map(17) == 28 );
    ASSERT( put_map(17, 28) == -1 );
    ASSERT( get_map(17) == 28 );
    ASSERT( remove_map(17) == 28 );
    ASSERT( remove_map(17) == -1 );
    ASSERT( get_map(17) == -1 );
    ASSERT( put_map(17, 28) == 1 );
    ASSERT( get_map(17) == 28 );

    ASSERT( put_map(128, 28) == 1 );
    ASSERT( put_map(128, 18) == -1 );
    ASSERT( get_map(128) == 28 );
    ASSERT( put_map(128, 28) == -1 );
    ASSERT( get_map(128) == 28 );
    ASSERT( remove_map(128) == 28 );
    ASSERT( remove_map(128) == -1 );
    ASSERT( get_map(128) == -1 );
    ASSERT( put_map(128, 28) == 1 );
    ASSERT( get_map(128) == 28 );

    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv){
    GREATEST_MAIN_BEGIN();

    RUN_TEST(map_tests);

    GREATEST_MAIN_END();

    return 0;
}
