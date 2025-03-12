#include <stdio.h>
#include <complex.h>

#ifdef __STDC_NO_COMPLEX__
#error Complex numbers not supported!
#endif

#if __STDC_IEC_559_COMPLEX__ != 1
#error Need IEC 60559 complex support!
#endif

int main(void)
{
    double complex a_complex_number_waow = 10 + 3*I;

    printf("y = %f + %fi\n", creal(a_complex_number_waow), cimag(a_complex_number_waow));

    float complex x = 3 + 1*I;
    float complex y = 11 - 3*I;

    float complex z = x - y;
    printf("z = %f + %fi\n", crealf(z), cimagf(z));

    if(z == (float complex) -8.0 + 4.0 *I) {
	printf("ayy, I can check for such thing, if it is equal or not.\n");
    } else {
	printf("oh no no no\n");
    }

    printf("Just Monika.\n");
    return 0;
}
