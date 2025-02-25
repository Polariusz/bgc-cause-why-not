#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
    va_list va;

    va_start(va, format);
    int rv = vprintf(format, va);
    va_end(va);
    return rv;
}

int main(void)
{
    int foo = 42;
    double bar = 69.0;
    my_printf("x is %d, y is %lf\n", foo, bar);
    my_printf("Just Monika.\n");
    return 0;
}
