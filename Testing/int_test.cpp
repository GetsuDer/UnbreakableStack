#include <cstdio>
#include <iostream>
#include <cmath>

#include "test_lib.h"
#include "stack_global.h"

#undef TYPE
#define TYPE int
#include "stack.h"
#include "../Source/stack.cpp"

void test_int()
{
    TEST_BEGIN;
    Stack_int *s = (Stack_int *)calloc(1, sizeof(*s));
    TEST(Stack_Construct(s), OK);
    TEST_END;

    TEST_BEGIN;
    for (int i = 0; i < 100; i++) {
        TEST(Stack_Push(s, i), OK);
    }
    for (int i = 99; i >= 10; i--) {
        TEST(Stack_Top(s), i);
        TEST(Stack_Pop(s), OK);
    }
    TEST_END;

    TEST_BEGIN;
    TEST(Stack_Destruct(s), OK);
    TEST(!Stack_Err(s), OK);
    TEST_END;

    return;
}
