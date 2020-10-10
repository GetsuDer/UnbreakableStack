#include <cstdio>
#include <cmath>
#include <iostream>

#include "test_lib.h"

#define TYPE double
#include "stack.cpp"

void test_double()
{
    TEST_BEGIN;
    STACK_DOUBLE(s_double);
    TEST_END;

    TEST_BEGIN;
    int old_size = 0;
    for (int i = 0; i < 5; i++) {
        TEST(Stack_Push(&s_double, i * 1.5), OK);
        TEST(Stack_Size(&s_double) - 1, old_size);
        old_size = Stack_Size(&s_double);
    }
    Stack_Dump_double(&s_double);
    for (int i = 4; i >= 3; i--) {
        TEST(fabs(Stack_Top(&s_double) - i * 1.5) < EPS, true);
        TEST(Stack_Pop(&s_double), OK);
        TEST(Stack_Size(&s_double) + 1, old_size);
        old_size = Stack_Size(&s_double);
    }
    Stack_Dump_double(&s_double);
    TEST_END;
    return;
}
