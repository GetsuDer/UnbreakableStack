// There is no include guard here, it must be so!

#define CAT_IMPL(a) Stack_##a
#define Stack(a) CAT_IMPL(a)

#define CAT_IMPL2(a) POISON_##a
#define POISON(a) CAT_IMPL2(a)
/*
#define CAT_IMPL3(a,b) print_##a(b)
#define PRINT(a,b) CAT_IMPL3(a,b)
*/
constexpr int POISON_int = 0xDEADBEEF;

struct Stack(TYPE)
{
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    TYPE * data;
};

int Stack_Construct(Stack(TYPE) *thou);
int Stack_Destruct(Stack(TYPE) *thou);
int Stack_Push(Stack(TYPE) *thou, TYPE elem);
int Stack_Pop(Stack(TYPE) *thou);
TYPE Stack_Top(Stack(TYPE) *thou);
int Stack_Err(Stack(TYPE) *thou);
void Stack_Dump(Stack(TYPE) *thou);
void print_err(int err, Stack(TYPE) *thou);
