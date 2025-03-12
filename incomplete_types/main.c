#include <stdio.h>

void incomplete_entry()
{
    // These are incomplete, but that's okay!

    struct Fruit *carrot;
    union Peps *dog;
    enum Planet *moon;

    // This will fail:
    // 
    // int x = *carrot;
    // > error: invalid use of undefined type ‘struct Fruit’
}

int main(void)
{
    incomplete_entry();
    printf("Just Monika.\n");
    return 0;
}
