#include <stdio.h>

int main(void)
{
    int two_dimentional[3][2] = {1, 2, 3, 5, 6};

    for(int i = 0; i < 3; i ++) {
	for(int j = 0; j < 2; j ++) {
	    printf("%d ", two_dimentional[i][j]);
	}
	printf("\n");
    }
    // > 1 2
    // > 3 5
    // > 6 0

    int one_dimentional[5] = {0};

    for(int i = 0; i < 5; i ++) {
	printf("%d ", one_dimentional[i]);
    }
    printf("\n");
    // > 0 0 0 0 0

    printf("Just Monika.\n");
    return 0;
}
