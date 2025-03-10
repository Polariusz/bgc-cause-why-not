#include <stdio.h>

struct Point {
    int x;
    int y;
};

void printPoint(struct Point p)
{
    printf("x:%d y: %d\n", p.x, p.y);
}

void printPointPointer(struct Point *p)
{
    printf("x:%d y: %d\n", p->x, p->y);
}

int main(void)
{
    printf("Named:\n  ");
    struct Point p = {10, 20};
    printPoint(p);

    printf("Now unnamed:\n  ");
    printPoint((struct Point){420, 69});

    printf("Now unnamed pointer:\n  ");
    printPointPointer(&(struct Point){33, 0});

    printf("Just Monika.\n");
    return 0;
}
