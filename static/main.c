#include <stdio.h>

void counter() {
    static int cnt = 1;

    printf("Called %d times.", cnt);
    cnt++;
}

int main(void)
{
    counter();
    counter();
    counter();
    counter();
    printf("Just Monika.\n");
    return 0;
}
