#include <stdio.h>
#include <math.h>

// x = ax² + bx + c
//
//   !
// 0 = ax² + bx + c
// x = (-b +- sqr(b²-4ac))/(2a)

#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUADN(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUAD(a, b, c) QUADP(a, b, c), QUADN(a, b, c)

int main(void)
{
    printf("0 = 2x² + 10x + 5\n");
    printf("x = + %f - %f\n", QUAD(2, 10, 5));
    printf("Just Monika.\n");
    return 0;
}
