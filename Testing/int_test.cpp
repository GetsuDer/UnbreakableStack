#include <cstdio>
#include <iostream>
#include <cmath>

#include "test_lib.h"
#include "stack_global.h"

#undef TYPE
#define TYPE int
#include "stack.h"
#include "stack.cpp"

void test_int()
{
    TEST_BEGIN;
    Stack_int *s = (Stack_int *)calloc(1, sizeof(*s));
    TEST(Stack_Construct(s), OK);
    TEST_END;

    TEST_BEGIN;
    for (int i = 0; i < 5; i++) {
        TEST(Stack_Push(s, i), OK);
    }
    Stack_Dump(s);
    for (int i = 4; i >= 3; i--) {
        TEST(Stack_Top(s), i);
        TEST(Stack_Pop(s), OK);
    }
    Stack_Dump(s);
    TEST_END;

    TEST_BEGIN;
    TEST(Stack_Destruct(s), true);
    TEST(!Stack_Err(s), true);
    TEST_END;

    return;
}
