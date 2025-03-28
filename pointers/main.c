#include <stdio.h>

void ptr1(void)
{
    int arr[5] = {11, 22, 33, 44, 55};
    int *p_arr = &arr[0];

    for(int i = 0; i < 5; i++) {
        printf("%d ", *(p_arr + i));
    }
    printf("\n");

    printf("%d\n", *p_arr);
}

void ptr2(void)
{
    int arr[6] = {1,2,3,4,5,999};
    int *p_arr = &arr[0];
    while(*p_arr != 999) {
        *p_arr*=2;
        printf("%d ", *p_arr);
        p_arr+=1;
    }
    printf("\n");
}

int my_strlen(char* txt)
{
    char *s = txt;

    while(*s != '\0') {
        s++;
    }
    return s-txt;
}

int main(void)
{
    char text[] = "I think, therefore: I am.";
    printf("len of text: `%s` is: %d\n", text, my_strlen(text));
    return 0;
}
