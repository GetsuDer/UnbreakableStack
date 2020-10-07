void *errptr = (void *)13;
STACK_SIZE errsize = -777;
STACK_CAPACITY errcapacity = -666;
int POISON_int = 0xDEADBEEF;
double POISON_double = nan("");

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

