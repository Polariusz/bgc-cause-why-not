#include <unistd.h>
#include <string.h>
#include <stdio.h>

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
    char *txt = "1,99€";
    my_print("1,99€\n");
    printf("%s, len: %ld\n", txt, strlen(txt));
    // > 1,99€, len: 7

    my_print("Just Monika.\n");
    return 0;
}
