#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_memcpy(void* dest, void* src, int len)
{
    char *s = src, *d = dest;

    while(len--) {
	*d++ = *s++;
    }

    return dest;
}

void print_arr(int *arr, int len)
{
    printf("arr: {");
    for(int i = 0; i < len; i++)
	printf("%d,", *(arr + i));
    printf("}\n");
}

int main(void)
{
    char *str1 = "Just Monika";
    char str2[100];

    my_memcpy(str2, str1, 12);

    printf("str2: `%s`\n", str2);


    int arr1[] = {10, 20, 30};
    int arr2[100];

    my_memcpy(arr2, arr1, 3*sizeof(int));

    print_arr(arr2, 3);

    return 0;
}
