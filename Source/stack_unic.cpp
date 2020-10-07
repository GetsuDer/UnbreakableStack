#include <cstdio>

#include "stack_global.h"

void print_type(int type)
{
    if (type == t_int) {
        fprintf(stderr, "int");
    }
    if (type == t_double) {
        fprintf(stderr, "double");
    }
    if (type == t_float) {
        fprintf(stderr, "float");
    }
    if (type == t_char) {
        fprintf(stderr, "char");
    }
    if (type == t_unsigned) {
        fprintf(stderr, "unsigned");
    }
}

bool poisoned((void *)thou, int type)
{
    if (type == t_int) {
        return POISON_int == *(int *)thou;
    }
    if (type == t_double) {
        return POISON_double == *(double *)thou;
    }
    if (type == t_float) {
        return POISON_float == *(float *)thou;
    }
    if (type == t_char) {
        return POISON_char == *(char *)thou;
    }
    if (type == t_unsigned) {
        return POISON_unsigned == *(unsigned *)thou;
    }
    return true;
}

void print_type_value((void *)thou, int type)
{
    if (type == t_double) {
        fprintf(stderr, "%lf", *(double *)thou);
    }
    if (type == t_float) {
        fprintf(stderr, "%f", *(float *)thou);
    }
    if (type ==  t_int) {
        fprintf(stderr, "%d", *(int *)thou);
    }
    if (type == t_unsigned) {
        fprintf(stderr, "%u", *(unsigned *)thou);
    }
    if (type == t_char) {
        fprintf(stderr, "%c", *(char *)thou);
    }
}
