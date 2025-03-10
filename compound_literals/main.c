#include <stdio.h>

int sum(int arr[], int n)
{
    int res = 0;
    int cnt = 0;
    while(cnt < n) {
	res += arr[cnt++];
    }
    return res;
}

int main(void)
{
    // like what even is this.
    int *p = (int []) {1, 2, 3, 4};
    printf("%d\n", p[1]);
    // > 2

    int arr1[] = {3, 6, 9, 12};
    int sum1 = sum(arr1, 4);
    printf("sum1 is: %d\n", sum1);
    // > sum1 is: 30

    // okay, this is... quite nice I think.
    int sum2 = sum((int []) {1, 2, 4, 8, 16, 32, 64}, 7);
    printf("sum2 is: %d\n", sum2);
    // > sum2 is: 127

    printf("Just Monika.\n");
    // > Just Monika.
    return 0;
}
