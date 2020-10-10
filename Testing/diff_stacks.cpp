#include <cstdio>
#include <cmath>
#include <iostream>


#include "test_lib.h"

#define TYPE unsigned
#include "stack.cpp"
#undef TYPE
#define TYPE float
#include "stack.cpp"


void diff_stacks()
{
    TEST_BEGIN;
    STACK_FLOAT(s_float);
    STACK_UNSIGNED(s_unsigned);
    TEST_END;

    TEST_BEGIN;
    int old_size = 0;
    for (unsigned i = 0; i < 5; i++) {
        TEST(Stack_Push(&s_float, i * 1.5), OK);
        TEST(Stack_Push(&s_unsigned, i), OK);
        TEST(Stack_Size(&s_float) - 1, old_size);
        TEST(Stack_Size(&s_unsigned) - 1, old_size);
        old_size = Stack_Size(&s_float);
    }
    Stack_Dump_float(&s_float);
    Stack_Dump_unsigned(&s_unsigned);

    for (unsigned i = 4; i >= 3; i--) {
        TEST(fabs(Stack_Top(&s_float) - i * 1.5) < EPS, true);
        TEST(Stack_Top(&s_unsigned), i);
        TEST(Stack_Pop(&s_float), OK);
        TEST(Stack_Pop(&s_unsigned), OK);
        TEST(Stack_Size(&s_float) + 1, old_size);
        TEST(Stack_Size(&s_unsigned) + 1, old_size);
        old_size = Stack_Size(&s_float);
    }
    Stack_Dump_float(&s_float);
    Stack_Dump_unsigned(&s_unsigned);
    TEST_END;
    return;
}
