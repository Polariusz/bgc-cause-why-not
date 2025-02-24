#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int math(int(*op)(int, int), int a, int b)
{
    return op(a, b);
}

void print_num(int foo)
{
    printf("%d\n", foo);

    return;
}

void miku(void)
{
    void (*fn_ptr_addr)(int) = &print_num;
    void (*fn_ptr)(int) = print_num;
    fn_ptr_addr(31);
    fn_ptr(13);

    return;
}

int main(void)
{
    printf("%d\n", math(add, 2, 3));
    printf("%d\n", math(mul, 2, 3));
    
    printf("Just Monika.\n");
    return 0;
}
