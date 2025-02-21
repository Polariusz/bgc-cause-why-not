#include <stdio.h>
#include <stdlib.h>

#define FNOTFOUND "File not created."

int main(void) {
    FILE *fp;
    if ((fp = fopen("text.bin", "w")) == NULL) {
	printf("%s\n", FNOTFOUND);
    }

    unsigned short v = 0x1234;
    fwrite(&v, sizeof v, 1, fp);

    return 0;
}
