#ifndef STACK_GLOBAL_H
#define STACK_GLOBAL_H

//! Type of stack size var. May be changed in future
#define STACK_SIZE int

//! Type of stack capacity var. May be changed in future
#define STACK_CAPACITY int
#define STACK_CHECK(thou) \
    if (Stack_Err(thou)) {\
        Stack_Dump(thou);\
        assert(0);\
    }

//! Knowingly wrong pointer, but not NULL
void *errptr = (void *) 1;

//! Special wrong stack size value (poison)
STACK_SIZE errsize = -777;

//! Special wrong stack capacity value (poison)
STACK_CAPACITY errcapacity = -666;

//! Values for error codes. 0 - success, not 0 - error.
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
