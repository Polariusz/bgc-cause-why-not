#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    const unsigned char *s = src;
    unsigned char *d = dest;

    while(n-- > 0)
        *d++ = *s++;

    return dest;
}

void print_arr(int *arr, int len)
{
    printf("arr: {");
    for(int i = 0; i < len; i++)
	printf("%d,", *(arr + i));
    printf("}\n");
}

struct Foo {
    int a;
    int b;
    char c;
};

void print_foo(struct Foo *arr, int len)
{
    printf("arr: {\n");
    for(int i = 0; i < len; i++)
	printf("    Foo: {a:%d b:%d, c:%c},\n", (*(arr + i)).a, (*(arr + i)).b, (*(arr + i)).c);
    printf("}\n");
}

int main(void)
{
    int arr1[] = {1, 3, 69, 420, 999};
    int arr2[30];
    my_memcpy(arr2, arr1, 5*sizeof(int));

    print_arr(arr2, 5);

    struct Foo foo_arr1[] = {
	{.a=1, .b=10, .c='a'},
	{.a=2, .b=20, .c='b'},
	{.a=3, .b=30, .c='c'},
	{.a=4, .b=40, .c='d'},
    };

    struct Foo foo_arr2[4];

    my_memcpy(foo_arr2, foo_arr1, 4*sizeof(struct Foo));
    print_foo(foo_arr2, 4);
    
    printf("Just Monika.\n");
    return 0;
}
