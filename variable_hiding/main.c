#include <stdio.h>
#include <float.h>

int main(void)
{
    int a = 10;
    {
	int a = 20;
	printf("a:%d\n", a);
    }

    printf("a:%d\n", a);
    return 0;
}
