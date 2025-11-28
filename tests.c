#include "brackets.h"
#include <assert.h>
#include <stdio.h>

void run_tests() {
    printf("Running tests...\n");

    assert(check_balanced("") == BALANCED);
    assert(check_balanced("abc 123") == BALANCED);
    assert(check_balanced("(){}[]<>") == BALANCED);
    assert(check_balanced("([{<>}])") == BALANCED);
    assert(check_balanced("(a[b{c<d>e}f]g)") == BALANCED);

    assert(check_balanced("(") == NOT_BALANCED);
    assert(check_balanced(")") == NOT_BALANCED);
    assert(check_balanced("([)]") == NOT_BALANCED);
    assert(check_balanced("({)}") == NOT_BALANCED);
    assert(check_balanced("<<") == NOT_BALANCED);
    assert(check_balanced("}{") == NOT_BALANCED);

    printf("All tests passed!\n");
}

int main() {
    run_tests();
    return 0;
}