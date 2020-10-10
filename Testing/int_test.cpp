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
    STACK_INT(s_int);
    TEST_END;

    TEST_BEGIN;
    int old_size = 0;
    for (int i = 0; i < 5; i++) {
        TEST(Stack_Push(&s_int, i), OK);
        TEST(Stack_Size(&s_int) - 1, old_size);
        old_size = Stack_Size(&s_int);
    }
    Stack_Dump_int(&s_int);
    for (int i = 4; i >= 3; i--) {
        TEST(Stack_Top(&s_int), i);
        TEST(Stack_Pop(&s_int), OK);
        TEST(Stack_Size(&s_int) + 1, old_size);
        old_size = Stack_Size(&s_int);
    }
    Stack_Dump_int(&s_int);
    TEST_END;

    return;
}
