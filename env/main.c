#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *val = getenv("MAIL");

    if(val == NULL) {
	printf("Could not find env: `MAIL`.\n");
	return 1;
    }

    printf("Value: %s\n", val);
    return 0;
}
