
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "greatest.h"
#include "utils.h"
#include "buffer.h"

SUITE_EXTERN(other_suite);

SUITE(suite);

void allocate(int n){
    int *c = (int *) balloc(2);
    if(n){
        allocate(n - 1);
    }
    bfree(c);
}

TEST buddy_tests(void) {
    init_buddy();
    int *a = (int *) balloc(1024);
    int *b = (int *) balloc(2048);
    int *c = (int *) balloc(123);
    int *d = (int *) balloc(1023);
    bfree(a);
    bfree(b);
    bfree(c);
    bfree(d);
    allocate(4096);
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
