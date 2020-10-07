#include <cstdio>
#include <cmath>
#include <iostream>

#include "test_lib.h"
#include "stack_global.h"

#undef TYPE
#define TYPE double
#include "stack.h"
#include "../Source/stack.cpp"

void test_double()
{
    TEST_BEGIN;
    Stack_double *s = (Stack_double *)calloc(1, sizeof(*s));
    TEST(Stack_Construct(s), OK);
    TEST_END;

    TEST_BEGIN;
    for (int i = 0; i < 100; i++) {
        TEST(Stack_Push(s, 1.75 * i), OK);
    }
    for (int i = 99; i >= 10; i--) {
        TEST(fabs(Stack_Top(s) - 1.75 * i) < EPS, true);
        TEST(Stack_Pop(s), OK);
    }
    TEST_END;

    TEST_BEGIN;
    TEST(Stack_Destruct(s), OK);
    TEST(!Stack_Err(s), OK);
    TEST_END;

    return;
}
