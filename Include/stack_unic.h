void *errptr = (void *)13;
STACK_SIZE errsize = -777;
STACK_CAPACITY errcapacity = -666;
int POISON_int = 0xDEADBEEF;
double POISON_double = 12345.54321;
unsigned POISON_unsigned = 0x0EADBEEF;
float POISON_float = 12345.54321;
char POISON_char = 127;

struct Stack_int
{
    int type;
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    int *data;
}

struct Stack_double
{
    int type;
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    double *data;
}

struct Stack_unsigned
{
    int type;
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    unsigned *data;
}

struct Stack_char
{
    int type;
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    char *data;
}

sturct Stack_float
{
    int type;
    STACK_SIZE size;
    STACK_CAPACITY capacity;
    float *data;
}

//! \brief Wrapper for print template
//! \param [in] a Integer to be printed
void Print_int(int a)
{
    fprintf(stderr, "%d", a);
    return;
}

//! \brief Wrapper for print template
//! \param [in] a Double to be printed
void Print_double(double a)
{
    fprintf(stderr, "%lf", a);
    return;
}

//! \brief Wrapper for print template
//! \param [in] c Char to be printed
void Print_char(char c)
{
    fprintf(stderr, "%c", c);
    return;
}

//! \brief Wrapper for print template
//! \param [in] u Unsigned to be printed
void Print_unsigned(unsigned u)
{
    fprintf(stderr, "%u", u);
    return;
}

//! \brief Wrapper for print template
//! \param [in] f Float to be printed
void Print_float(float f)
{
    fprintf(stderr, "%f", f);
    return;
}

//! \brief Wrapper for print template
int find_type(Stack_double *thou)
{
    return t_double;
}

//! \brief Wrapper for print template
int find_type(Stack_float *thou)
{
    return t_float;
}

//! \brief Wrapper for print template
int find_type(Stack_int *thou)
{
    return t_int;
}
//! \brief Wrapper for print template
int find_type(Stack_char *thou)
{
    return t_char;
}

//! \brief Wrapper for print template
int find_type(Stack_unsigned *thou)
{
    return t_unsigned;
}
