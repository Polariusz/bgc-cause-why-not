#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char**argv) {
    int res = 0;
    while(*argv != NULL) {
	res += atoi(*argv);
	argv++;
    }

    printf("%d\n", res);
}

int main(int argc, char **argv)
{
    (void)argc;

    if(argc != 3) {
	printf("Usage: ./mult x y\n");
	return 69;
    }

    printf("res: %d\n", atoi(argv[1]) * atoi(argv[2]));

    return 0;
}
