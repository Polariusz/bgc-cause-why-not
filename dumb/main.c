#include <stdio.h>
#include <stdlib.h>
#include "nxtypes.h"

int main(void)
{
    u32 *mlem;
    if((mlem = malloc(sizeof(u32))) == NULL) {
	printf("buy more ram.\n");
	return 69;
    }
    *mlem = 2;
    printf("mlem: %d\n", *mlem);

    u64 *plink;
    if((plink = malloc(sizeof(u64))) == NULL) {
	printf("buy more ram.\n");
	return 69;
    }
    *plink = 30;
    printf("plink: %ld\n", *plink);

    printf("Just Monika.\n");
    return 0;
}
