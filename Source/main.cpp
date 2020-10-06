#include <cstdio>
#include "stack_global.h"

#define TYPE int
#include "stack.cpp"

int main()
{
    Stack_int *s = (Stack_int *)calloc(1, sizeof(*s));
    Stack_Construct(s);
    Stack_Push(s, 1);
    fprintf(stdout,"%d\n", Stack_Top(s));
    Stack_Dump(s);
    Stack_Destruct(s);
    
    return 0;
}
