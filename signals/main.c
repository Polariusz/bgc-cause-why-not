#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void non_undefined_sigint_handler(int signum)
{
    (void)signum;
    signal(SIGINT, SIG_DFL);
}

void do_non_undefined_sigint(void)
{
    signal(SIGINT, non_undefined_sigint_handler);
    printf("Hit ^C twice to return...\n");
    while(1 == 1);
    return;
}

volatile sig_atomic_t different_count = 0;
void different_sigint_handler(int signum)
{
    signal(SIGINT, different_sigint_handler);
    
    (void)signum;

    different_count++; // undefined behaviour
}

void do_different_sigint(void)
{
    signal(SIGINT, different_sigint_handler);
    printf("Try pressing ^C twice...\n");
    while(different_count < 2);
    return;
}

int count = 0;
void sigint_handler(int signum)
{
    signal(SIGINT, sigint_handler);
    
    (void)signum;

    count++; // undefined behaviour
    printf(" cnt: %d\n", count); // undefined behaviour

    if(count == 2) {
	printf("Exiting\n"); // undefined behaviour
	exit(0);
    }
}

void do_sigint(void)
{
    signal(SIGINT, sigint_handler);
    printf("Try pressing ^C.\n");
    for(;;);
    return;
}

int main(void)
{
    do_non_undefined_sigint();
    printf("Just Monika.\n");
    return 0;
}
