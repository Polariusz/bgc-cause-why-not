#include <stdio.h>

// This is insane
#define LOOP_BE(b, e) \
do { \
for (int i = (b); i < (e); i++) { \
    printf("i:%d ", i); \
} \
printf("\n"); \
} while(0) 

int main(void)
{
    LOOP_BE(11, 33);
    return 0;
}
