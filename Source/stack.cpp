#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>

//! This is magic for right preprocessing
#define CAT_IMPL(a) Stack_##a

//! This is magic for right preprocessing
#define Stack(a) CAT_IMPL(a)

//! This is magic for right preprocessing
#define CAT_IMPL2(a) POISON_##a

//! This is magic for right preprocessing
#define POISON(a) CAT_IMPL2(a)

#define CAT_IMPL3(a) Print_##a
#define PRINT(a) CAT_IMPL3(a)

//! Type for guard bird
#define BIRD unsigned long long

//! Type for stack size
#define STACK_SIZE int

//! Type for stack capacity
#define STACK_CAPACITY int

//! Stack name
#define STACK_VAR_NAME const char *name


//! \"Template\" for different stacks
struct Stack(TYPE)
{
    BIRD bird1;
    STACK_VAR_NAME;
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    TYPE * data;
    BIRD bird2;
};

int Stack_Construct(Stack(TYPE) *thou);
bool Stack_Destruct(Stack(TYPE) *thou);
int Stack_Push(Stack(TYPE) *thou, TYPE elem);
int Stack_Pop(Stack(TYPE) *thou);
STACK_SIZE Stack_Size(Stack(TYPE) *thou);
TYPE Stack_Top(Stack(TYPE) *thou);
int Stack_Err(Stack(TYPE) *thou);
void print_err(int err, Stack(TYPE) *thou);

#ifndef STACK_GLOBAL_H
#define STACK_GLOBAL_H

//! Type of stack size var. May be changed in future
#define STACK_SIZE int

//! Type of stack capacity var. May be changed in future
#define STACK_CAPACITY int

#define CAT_IMPL4(a,b) Stack_Dump_##a (b)
#define Stack_Dump(a,b) CAT_IMPL4(a,b)

//! Short record for debug checks
#define STACK_CHECK(a,thou) \
    if (Stack_Err(thou)) {\
        Stack_Dump(a,thou);\
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

#endif

//! \brief Dumps Stack for type int and its content into stderr (now)
//! \param [in] thou - pointer on stack
#define Stack_Dump_int(thou) \
{ \
    fprintf(stderr, "stack dump [TYPE = int]"); \
    int err = Stack_Err((thou)); \
    if (!err) { \
        fprintf(stderr, " (ok) "); \
    } else { \
        print_err(err, (thou)); \
    } \
    if (err != WRONG_STACK_POINTER) { \
        fprintf(stderr, "var name = %s ", (thou)->name);\
        fprintf(stderr, "\n [ %p ] ", thou); \
        fprintf(stderr, "[ in file: %s on func: %s on line: %d ]", __FILE__, __func__, __LINE__);  \
        fprintf(stderr, "\n size = %d, capacity = %d ", (thou)->size, (thou)->capacity);\
        for (int i = 0; i < (thou)->size; i++) {\
            fprintf(stderr, "\n *[%d] = %d", i, (thou)->data[i]);\
            if ((thou)->data[i] == POISON_int) {\
                fprintf(stderr, " !Poisoned!");\
            }\
        }\
    }\
    fprintf(stderr, "\n");\
}

//! \brief Dumps Stack for type unsigned and its content into stderr (now)
//! \param [in] thou - pointer on stack
#define Stack_Dump_unsigned(thou) \
{ \
    fprintf(stderr, "stack dump [TYPE = unsigned]"); \
    int err = Stack_Err(thou); \
    if (!err) { \
        fprintf(stderr, " (ok) "); \
    } else { \
        print_err(err, thou); \
    } \
    if (err != WRONG_STACK_POINTER) { \
        fprintf(stderr, "var name = %s ", (thou)->name);\
        fprintf(stderr, "\n [ %p ] ", thou); \
        fprintf(stderr, "[ in file: %s on func: %s on line: %d ]", __FILE__, __func__, __LINE__);  \
        fprintf(stderr, "\n size = %d, capacity = %d ", thou->size, thou->capacity);\
        for (int i = 0; i < thou->size; i++) {\
            fprintf(stderr, "\n *[%d] = %u", i, thou->data[i]);\
            if (thou->data[i] == POISON_unsigned) {\
                fprintf(stderr, " !Poisoned!");\
            }\
        }\
    }\
    fprintf(stderr, "\n");\
}

//! \brief Dumps Stack for type double and its content into stderr (now)
//! \param [in] thou - pointer on stack
#define Stack_Dump_double(thou) \
{ \
    fprintf(stderr, "stack dump [TYPE = double]"); \
    int err = Stack_Err(thou); \
    if (!err) { \
        fprintf(stderr, " (ok) "); \
    } else { \
        print_err(err, thou); \
    } \
    if (err != WRONG_STACK_POINTER) { \
        fprintf(stderr, "var name = %s ", (thou)->name);\
        fprintf(stderr, "\n [ %p ] ", thou); \
        fprintf(stderr, "[ in file: %s on func: %s on line: %d ]", __FILE__, __func__, __LINE__);  \
        fprintf(stderr, "\n size = %d, capacity = %d ", thou->size, thou->capacity);\
        for (int i = 0; i < thou->size; i++) {\
            fprintf(stderr, "\n *[%d] = %lf", i, thou->data[i]);\
            if (thou->data[i] == POISON_double) {\
                fprintf(stderr, " !Poisoned!");\
            }\
        }\
    }\
    fprintf(stderr, "\n");\
}

//! \brief Dumps Stack for type float and its content into stderr (now)
//! \param [in] thou - pointer on stack
#define Stack_Dump_float(thou) \
{ \
    fprintf(stderr, "stack dump [TYPE = float]"); \
    int err = Stack_Err(thou); \
    if (!err) { \
        fprintf(stderr, " (ok) "); \
    } else { \
        print_err(err, thou); \
    } \
    if (err != WRONG_STACK_POINTER) { \
        fprintf(stderr, "var name = %s ", (thou)->name);\
        fprintf(stderr, "\n [ %p ] ", thou); \
        fprintf(stderr, "[ in file: %s on func: %s on line: %d ]", __FILE__, __func__, __LINE__);  \
        fprintf(stderr, "\n size = %d, capacity = %d ", thou->size, thou->capacity);\
        for (int i = 0; i < thou->size; i++) {\
            fprintf(stderr, "\n *[%d] = %f", i, thou->data[i]);\
            if (thou->data[i] == POISON_float) {\
                fprintf(stderr, " !Poisoned!");\
            }\
        }\
    }\
    fprintf(stderr, "\n");\
}

//! \brief Dumps Stack for type char and its content into stderr (now)
//! \param [in] thou - pointer on stack
#define Stack_Dump_char(thou) \
{ \
    fprintf(stderr, "stack dump [TYPE = char]"); \
    int err = Stack_Err(thou); \
    if (!err) { \
        fprintf(stderr, " (ok) "); \
    } else { \
        print_err(err, thou); \
    } \
    if (err != WRONG_STACK_POINTER) { \
        fprintf(stderr, "var name = %s ", (thou)->name);\
        fprintf(stderr, "\n [ %p ] ", thou); \
        fprintf(stderr, "[ in file: %s on func: %s on line: %d ]", __FILE__, __func__, __LINE__);  \
        fprintf(stderr, "\n size = %d, capacity = %d ", thou->size, thou->capacity);\
        for (int i = 0; i < thou->size; i++) {\
            fprintf(stderr, "\n *[%d] = %c", i, thou->data[i]);\
            if (thou->data[i] == POISON_char) {\
                fprintf(stderr, " !Poisoned!");\
            }\
        }\
    }\
    fprintf(stderr, "\n");\
}

#define STACK_INT(a) Stack_int a; \
   a.name = #a;

#define STACK_UNSIGNED(a) Stack_unsigned a;
#define STACK_DOUBLE(a, b) Stack_double a;
#define STACK_FLOAT(a) Stack_float a;
#define STACK_CHAR(a) Stack_char a;

//! \brief Constructor for stack. 
//! \param [in] thou - valid pointer on allocated for stack memory
//! \return Error number (see global_stack.h Stack_Errors enum)
int Stack_Construct(Stack(TYPE) *thou)
{
    assert(thou);
    thou->size = 0;
    thou->capacity = 0;
    thou->data = NULL;
    STACK_CHECK(TYPE, thou);
    return Stack_Err(thou);
}

//! \brief Destructor for stack
//! \param [in] thou Valid pointer on stack
//! \return Returns true, if after destruction stack is poisoned (destructed correctly), else false 
bool Stack_Destruct(Stack(TYPE) *thou)
{
    STACK_CHECK(TYPE, thou);
    
    if (thou->data) {
        free(thou->data);
        thou->data = (TYPE *) errptr;
    }
    thou->size = errsize;
    thou->capacity = errcapacity;
    free(thou);
    return !Stack_Err(thou);
}

//! \brief Add elem in stack
//! \param[in] elem Elem to be added
//! \param[in] thou Valid pointer on stack in which elem must be inserted
//! \return Returns 0 (OK) if success, else ErrorCode from Stack_Errors (see global_stack.h)
int Stack_Push(Stack(TYPE) *thou, TYPE elem)
{
    STACK_CHECK(TYPE, thou);
    
    if (thou->capacity == 0) {
        thou->data = (TYPE *) calloc(1, sizeof(TYPE));
        thou->capacity = 1;
    }
    if (thou->size == thou->capacity) {
        thou->data = (TYPE *) realloc(thou->data, (thou->capacity * 2 + 1) * sizeof(TYPE));
        thou->capacity = thou->capacity * 2 + 1;
    }
    thou->data[thou->size] = elem;
    thou->size++;

    STACK_CHECK(TYPE, thou);
    return Stack_Err(thou);
}

//! \brief Pops the stack top elem
//! \param [in] thou Stack to be processed
//! \return Return 0 (OK) if success, error code from Stack_Errors else (see global_stack.h)
int Stack_Pop(Stack(TYPE) *thou)
{
    STACK_CHECK(TYPE, thou);
    thou->size--;
    STACK_CHECK(TYPE, thou);
    return 0; 
}

//! \brief Take the stack top without deleting
//! \param [in] thou Stack to be processed
//! \return Return value from stack top. If trying to see elem from empty stack, returns POISONED VALUE (see global_stack.h)
TYPE Stack_Top(Stack(TYPE) *thou)
{
    STACK_CHECK(TYPE, thou);
    if (thou->size <= 0) {
        return POISON(TYPE);
    }
    return thou->data[thou->size - 1];
}

//! \brief Check stack
//! \param [in] thou Pointer on stack to be checked
//! \return Returns error code from Stack_Errors (see global_stack.h) or 0 (OK)
int Stack_Err(Stack(TYPE) *thou)
{
    if (!thou) {
        return WRONG_STACK_POINTER;
    }
    if (thou->size < 0) {
        return NEGATIVE_SIZE;
    }
    if (thou->capacity < 0) {
        return NEGATIVE_CAPACITY;
    }
    if (thou->size > thou->capacity) {
        return SIZE_GREATER_CAPACITY;
    }
    if (thou->size != 0 && !thou->data) {
        return NULL_DATA;
    }
    if (thou->data == errptr) {
        return DEAD_DATA_POINTER;
    }
    return OK;
}

//! \brief Stack size
//! \param [in] thou Stack for stack size info
//! \return returns Stack size
STACK_SIZE Stack_Size(Stack(TYPE) *thou)
{
    STACK_CHECK(TYPE, thou);
    assert(thou);
    return thou->size;
}
//! \brief Check on empty stack
//! \param [in] thou Stack to be checked
//! \return Returns true if stack is empty
bool Stack_Empty(Stack(TYPE) *thou)
{
    STACK_CHECK(TYPE, thou);
    assert(thou);
    return !thou->size;
}
//! \brief Error decryption
//! \param [in] err Error code from Stack_Errors (see global_stack.h)
//! \param [in] thou Stack for additional info (if null, just basic decryption)
void print_err(int err, Stack(TYPE) *thou = NULL) 
{
    if (err == WRONG_STACK_POINTER) {
        fprintf(stderr, " Dumping stack on NULL pointer, nothing interesting? ");
        return;
    }
    if (err == NEGATIVE_SIZE) {
        fprintf(stderr, " Stack size is negative");
        if (thou) {
            fprintf(stderr, ": %d ", thou->size);
            if (thou->size == errsize) {
                fprintf(stderr, " [POISONED!] ");
            }
        }
        return;
    }
    if (err == NEGATIVE_CAPACITY) {
        fprintf(stderr, " Stack capacity is negative");
        if (thou) {
            fprintf(stderr, ": %d ", thou->capacity);
            if (thou->size == errcapacity) {
                fprintf(stderr, " [POISONED!] ");
            }
        }
        return;
    }
    if (err == SIZE_GREATER_CAPACITY) {
        fprintf(stderr, " Stack size is > then stack capacity");
        if (thou) {
            fprintf(stderr, ": %d  > %d ", thou->size, thou->capacity);
        }
        return;
    }
    if (err == NULL_DATA) {
        fprintf(stderr, " Stack data pointer is null, but stack size is not zero!");
        if (thou) {
           fprintf(stderr, "Stack size is: %d ", thou->size);
        }
        return;
    }
    if (err == DEAD_DATA_POINTER) {
        fprintf(stderr, " Stack data pointer is poisoned, may be stack was destructed? ");
        return;
    }
    fprintf(stderr, " Sorry, i don`t know this mistake :( ");
    return;
}
