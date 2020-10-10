#include <cstdio>
#include <iostream>
#include <cmath>

#include "test_lib.h"

#undef TYPE
#define TYPE int
#include "stack.cpp"

void test_int()
{
    TEST_BEGIN;
    STACK_INT(s);

    TEST_END;

    TEST_BEGIN;
    for (int i = 0; i < 5; i++) {
        TEST(Stack_Push(&s, i), OK);
    }
    Stack_Dump_int(&s);
    for (int i = 4; i >= 3; i--) {
        TEST(Stack_Top(&s), i);
        TEST(Stack_Pop(&s), OK);
    }
    Stack_Dump_int(&s);
    TEST_END;

    return;
}
