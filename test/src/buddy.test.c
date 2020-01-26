
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "greatest.h"
#include "utils.h"
#include "buddy.h"

SUITE_EXTERN(other_suite);

SUITE(suite);

TEST buddy_tests(void) {
    init_buddy();
    int a = balloc(1024);
    int b = balloc(2048);
    printf("memory pointer:::   %d\n", a);
    bfree(a);
    bfree(b);
    bfree(b);
    PASS();
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv){
    GREATEST_MAIN_BEGIN();

    RUN_TEST(buddy_tests);

    GREATEST_MAIN_END();

    return 0;
}
// */
