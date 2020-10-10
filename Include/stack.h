#define BIRD unsigned int
#define STACK_SIZE int
#define STACK_CAPACITY int

void *errptr = (void *)13;
STACK_SIZE errsize = -777;
STACK_CAPACITY errcapacity = -666;
int POISON_int = 0xDEADBEEF;
double POISON_double = 12345.54321;
unsigned POISON_unsigned = 0x0EADBEEF;
float POISON_float = 12345.54321;
char POISON_char = 127;
BIRD bird_prototype = 0xDEADBEEFULL;
