#include "stack.h"
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <typeinfo>

#define Stack_Dump(thou) \
{ \
    fprintf(stderr, "stack dump [TYPE = %s]", typeid(TYPE).name()); \
    int err = Stack_Err(thou); \
    if (!err) { \
        fprintf(stderr, " (ok) "); \
    } else { \
        print_err(err, thou); \
    } \
    if (err != WRONG_STACK_POINTER) { \
        fprintf(stderr, "\n [ %p ] ", thou); \
        fprintf(stderr, "[ in file: %s on func: %s on line: %d ]", __FILE__, __func__, __LINE__);  \
        fprintf(stderr, "\n size = %d, capacity = %d ", thou->size, thou->capacity);\
        for (int i = 0; i < thou->size; i++) {\
            fprintf(stderr, "\n *[%d] = ", i);\
            fprintf(stderr, " %d ", thou->data[i]);\
            if (thou->data[i] == POISON(TYPE)) {\
                fprintf(stderr, "!Poisoned!");\
            }\
        }\
    }\
    fprintf(stderr, "\n");\
}

int Stack_Construct(Stack(TYPE) *thou)
{
    assert(thou);
    thou->size = 0;
    thou->capacity = 0;
    thou->data = NULL;
    STACK_CHECK(thou);
    return 0;
}

int Stack_Destruct(Stack(TYPE) *thou)
{
    STACK_CHECK(thou);
    
    if (thou->data) {
        free(thou->data);
        thou->data = (TYPE *) errptr;
    }
    thou->size = errsize;
    thou->capacity = errcapacity;
    free(thou);
    return 0;
}

int Stack_Push(Stack(TYPE) *thou, TYPE elem)
{
    STACK_CHECK(thou);
    
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

    STACK_CHECK(thou);
    return 0;
}

int Stack_Pop(Stack(TYPE) *thou)
{
    STACK_CHECK(thou);
    thou->size--;
    STACK_CHECK(thou);
    return 0; 
}

TYPE Stack_Top(Stack(TYPE) *thou)
{
    STACK_CHECK(thou);
    return thou->data[thou->size - 1];
}

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

void print_err(int err, Stack(TYPE) *thou) 
{
    if (err == WRONG_STACK_POINTER) {
        fprintf(stderr, " Dumping stack on NULL pointer, nothing interesting? ");
        return;
    }
    if (err == NEGATIVE_SIZE) {
        fprintf(stderr, " Stack size is negative: %d ", thou->size);
        if (thou->size == errsize) {
            fprintf(stderr, " [POISONED!] ");
        }
        return;
    }
    if (err == NEGATIVE_CAPACITY) {
        fprintf(stderr, " Stack capacity is negative: %d ", thou->capacity);
        if (thou->size == errcapacity) {
            fprintf(stderr, " [POISONED!] ");
        }
        return;
    }
    if (err == SIZE_GREATER_CAPACITY) {
        fprintf(stderr, " Stack size is > then stack capacity: %d  > %d ", thou->size, thou->capacity);
    return;
    }
    if (err == NULL_DATA) {
        fprintf(stderr, " Stack data pointer is null, but stack size is not zero! %d ", thou->size);
        return;
    }
    if (err == DEAD_DATA_POINTER) {
        fprintf(stderr, " Stack data pointer is poisoned, may be stack was destructed? ");
        return;
    }
    fprintf(stderr, " Sorry, i don`t know this mistake :( ");
    return;
}
