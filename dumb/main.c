#include <unistd.h>

void my_print(char *t)
{
    char *p = t;
    while (*p != '\0') {
	write(1, p, 1);
	++p;
    }
}

int main(void)
{
    my_print("1,99€\n");

    my_print("Just Monika.\n");
    return 0;
}
