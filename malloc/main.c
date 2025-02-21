#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mallocing_lul()
{
    int *foo = malloc(sizeof(int));
    *foo = 10;

    printf("foo: %d\n", *foo);
    free(foo);
    return;
}

int mallocing_bunch()
{
    char *bunch;

    if((bunch = malloc(3640)) == NULL) {
	printf("malloc to `bunch` failed");
	return 1;
    }
    memset(bunch, 0, 3640);

    for(int i = 0; i < 3640; i++) {
	printf("%d ", *(bunch + i));
    }

    printf("\n");
    free(bunch);

    return 0;
}

int main(void)
{
    mallocing_bunch();
    return 0;
}
