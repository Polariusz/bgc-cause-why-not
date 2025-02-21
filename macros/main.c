#include <stdio.h>

#define HAPPINESS 2
#define PI 3.14159
#define SQR(x) ((x)*(x))
#define FO_AR(x, y) ((x)*(y))
#define TR_AR(w, h) ((w)*(h) / 2)
#define CI_AR(r) (PI * (r)*(r))

void func_mlem() {
    printf("func: %s\n", __func__);
}

int main(void)
{

    printf("Let's do some math\n");
    printf("PI: %f\n", PI);
    printf("SQR(%d): %d\n", 3, SQR(3));
    printf("FO_AR(%d, %d): %d\n", 3, 4, FO_AR(3, 4));
    printf("TR_AR(%d, %d): %d\n", 10, 2, TR_AR(10, 2));
    printf("CI_AR(%d): %lf\n", 100, CI_AR(100));
    printf("\n");

#if 0
    int c = 0;
    while(1) {
        printf("%d ", c);
        c++;
        if(c > 100)
            break;
    }
    printf("\n");
#endif

#if HAPPINESS == 0
    printf("I am sadge.\n");
#elif HAPPINESS == 1
    printf("I am happy.\n");
#else
    printf("I am crazy.\n");
#endif

    printf("Just Monika.\n");

    printf("\n");
    printf("date: %s ", __DATE__);
    printf("time: %s\n", __TIME__);
    printf("func: %s\n", __func__);
    func_mlem();
    printf("C Ver: %ld\n", __STDC_VERSION__);
    return 0;
}
