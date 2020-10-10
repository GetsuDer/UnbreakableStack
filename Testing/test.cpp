#include <iostream>
#include <cmath>


#include "test_lib.h"
#include "test_lib_unic.h"
#include "stack.h"

int main()
{
    test_int();
    test_double();
    diff_stacks();
    TEST_SUMMARY; 
    return 0;
}
