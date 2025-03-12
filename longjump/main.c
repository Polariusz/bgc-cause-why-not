#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void depth2()
{
    printf("Entering depth 2...\n");
    longjmp(env, 69);
    printf("Leaving depth 2...\n"); // won't happen
}

void depth1()
{
    printf("Entering depth 1...\n");
    depth2();
    printf("Leaving depth 1...\n"); // won't happen
}

int main(void)
{
    switch(setjmp(env)) {
	case 0:
	    printf("calling into method setjmp, returned 0\n");
	    depth1();
	    printf("returned from depth1()\n"); // will not happen
	case 69:
	    printf("calling into method setjmp, returned 69\n");
	    printf("  meaning that we bailed out to main.\n");
    }

    printf("Just Monika.\n");
    return 0;
}
