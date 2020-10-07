#include <cstdio>
#include <cmath>
#include <iostream>


#include "test_lib.h"
#include "stack_global.h"

#define TYPE unsigned
#include "stack.h"
#include "stack.cpp"
#undef TYPE 

#define TYPE float
#include "stack.h"
#include "stack.cpp"


void diff_stacks()
{
    TEST_BEGIN;
    Stack_unsigned *s1 = (Stack_unsigned *)calloc(1, sizeof(*s1));
    Stack_float *s2 = (Stack_float *)calloc(1, sizeof(*s2));
    TEST(Stack_Err(s1), OK);
    TEST(Stack_Err(s2), OK);

    for (unsigned i = 0; i < 5; i++) {
        Stack_Push(s1, i);
        TEST(Stack_Top(s1), i);
    }
    Stack_Dump(s1);
    for (int i = 0; i < 5; i++) {
        Stack_Push(s2, i * 1.5f);
        TEST(fabs(Stack_Top(s2) - i * 1.5f) < EPS, true);
    }
    Stack_Dump(s2);
    Stack_Push(s2, POISON_float);
    TEST(Stack_Err(s2), OK);
    Stack_Destruct(s1);
    Stack_Destruct(s2);
    return;
}
