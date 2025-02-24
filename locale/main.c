#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "de_DE.UTF-8");
    struct lconv *x = localeconv();
    printf("%s\n", x->int_curr_symbol);

    printf("Just Monika.\n");
    return 0;
}
