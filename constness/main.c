#include <stdio.h>

int main(void)
{
    const int x = 20;
    int *y = &x;

    printf("*y: %d\n", *y);
    return 0;
}
