#ifndef STACK_GLOBAL_H
#define STACK_GLOBAL_H

//! Type of stack size var. May be changed in future
#define STACK_SIZE int

//! Type of stack capacity var. May be changed in future
#define STACK_CAPACITY int

//! Short record for debug checks
#define STACK_CHECK(thou) \
    if (Stack_Err(thou)) {\
        Stack_Dump(thou);\
        assert(0);\
    }

//! Knowingly wrong pointer, but not NULL
extern void *errptr;

//! Special wrong stack size value (poison)
extern STACK_SIZE errsize;

//! Special wrong stack capacity value (poison)
extern STACK_CAPACITY errcapacity;


//! Poisoned value for type int
extern int POISON_int;

//! Poisoned value for type double
extern double POISON_double;

//! Poisoned value for type double
extern unsigned POISON_unsigned;

//! Poisoned value for type double
extern float POISON_float;

//! Poisoned value for type double
extern char POISON_char;

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


void Print_int(int a);
void Print_double(double a);
void Print_char(char c);
void Print_unsigned(unsigned u);
void Print_float(float f);

#endif
