#include <stdio.h>

#define TYPESTR(x) _Generic((x), \
			int: "It's an i32", \
			float: "It's an f32", \
			long: "It's an i64", \
			unsigned long: "It's an u64", \
			default: "It's something")

void generic(int i)
{
    char *generic = _Generic(i,
	int: "It's an i32",
	float: "It's an f32",
	default: "It's something"
    );

    printf("%s\n", generic);
}

void genericWithMacro()
{
    printf("%s\n", TYPESTR((int)3));
    printf("%s\n", TYPESTR((char*)"hi"));
    printf("%s\n", TYPESTR((float)1.0));
    printf("%s\n", TYPESTR((unsigned long)1));
}

int main(void)
{
    generic(1);
    printf("\n");

    genericWithMacro();

    printf("Just Monika.\n");
    return 0;
}
