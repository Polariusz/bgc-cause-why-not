#include <stdio.h>
#include <stdarg.h>

void print_all(int count, ...)
{
    va_list va;

    va_start(va, count);
    for(int i = 0; i < count; i++) {
	int n = va_arg(va, int); // get the next int

	printf("%d ", n);
    }
    printf("\n");
}

int main(void)
{
    print_all(5, 1, 2, 3, 4, 5);
    printf("Just Monika.\n");
    return 0;
}
