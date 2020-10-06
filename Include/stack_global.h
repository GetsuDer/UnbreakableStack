#ifndef STACK_GLOBAL_H
#define STACK_GLOBAL_H

#define STACK_SIZE int
#define STACK_CAPACITY int
#define STACK_CHECK(thou) \
    if (Stack_Err(thou)) {\
        Stack_Dump(thou);\
        assert(0);\
    }

void *errptr = (void *) 1;
STACK_SIZE errsize = -777;
STACK_CAPACITY errcapacity = -666;

enum Stack_Errors
{
    OK = 0,
    NEGATIVE_SIZE,
    NEGATIVE_CAPACITY,
    SIZE_GREATER_CAPACITY,
    NULL_DATA,
    POISONED_VALUE,
    WRONG_STACK_POINTER,
    DEAD_DATA_POINTER
};
#endif
