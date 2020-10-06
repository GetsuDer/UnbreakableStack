// There is no include guard here, it must be so!

//! This is magic for right preprocessing
#define CAT_IMPL(a) Stack_##a

//! This is magic for right preprocessing
#define Stack(a) CAT_IMPL(a)

//! This is magic for right preprocessing
#define CAT_IMPL2(a) POISON_##a

//! This is magic for right preprocessing
#define POISON(a) CAT_IMPL2(a)

/*
 * this magic doesnt work yet
#define CAT_IMPL3(a,b) print_##a(b)
#define PRINT(a,b) CAT_IMPL3(a,b)
*/

//! Poisoned value for type int
constexpr int POISON_int = 0xDEADBEEF;


//! \"Template\" for different stacks 
struct Stack(TYPE)
{
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    TYPE * data;
};

int Stack_Construct(Stack(TYPE) *thou);
bool Stack_Destruct(Stack(TYPE) *thou);
int Stack_Push(Stack(TYPE) *thou, TYPE elem);
int Stack_Pop(Stack(TYPE) *thou);
TYPE Stack_Top(Stack(TYPE) *thou);
int Stack_Err(Stack(TYPE) *thou);
void Stack_Dump(Stack(TYPE) *thou);
void print_err(int err, Stack(TYPE) *thou);
