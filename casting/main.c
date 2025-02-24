#include <stdio.h>
#include <stdint.h>

struct Words {
    int16_t v[2];
};

void fun(int32_t *pv, struct Words *pw)
{
    for(int i = 0; i < 5; i++) {
	(*pv)++;

	printf("%x, %x-%x\n", *pv, pw->v[1], pw->v[0]);
    }
}

int main(void)
{
    int32_t v = 0x12345678;

    struct Words *pw = (struct Words *)&v;

    fun(&v, pw);

    printf("Just Monika.\n");
    return 0;
}
