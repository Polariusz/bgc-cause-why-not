#include <stdio.h>
#include <string.h>

struct Common {
    int type;
    char* name;
};

struct Dog {
    int type;
    char* name;

    int hair;
};

struct Cat {
    int type;
    char* name;

    float speed;
};

union Animal {
    struct Common common;
    struct Dog dog; 
    struct Cat cat;
};


void print_animal(union Animal *animal) {
    switch(animal->common.type) {
	case 1:
	    printf("Cat: name: %s speed: %f", animal->common.name, animal->cat.speed);
	    break;
	case 2:
	    printf("Dog: name: %s hair: %d", animal->common.name, animal->dog.hair);
	    break;
    }
}

int main(void)
{
    union Animal cat = {.cat.type=1, .cat.name="Kitty", .cat.speed=130};
    union Animal dog = {.dog.type=2, .dog.name="Dog", .dog.hair=978129};

    print_animal(&cat);
    print_animal(&dog);

    return 0;
}
