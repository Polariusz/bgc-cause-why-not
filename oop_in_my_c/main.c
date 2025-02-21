#include <stdio.h>

struct Animal {
    char* species;
    int life_expentancy;
};

struct Human {
    struct Animal super;
    char *name;
    int fingers;
};

void print_animal(void *arg)
{
    // Note that his works because the struct Human has the Animal type and the type is the first one.
    // The pointer to the struct is the adress of the first type. This is the reason why it works.
    struct Animal *animal = arg; 
    printf("species: %s, life_expentancy: %d\n", animal->species, animal->life_expentancy);
}

void print_human(struct Human *human)
{
    printf("name: %s, fingers: %d\n", human->name, human->fingers);
}

int main(void)
{
    struct Human bob = {.super.species="Human", .super.life_expentancy=80, .name="Bob Baggins", .fingers=10};
    print_animal(&bob);
    print_human(&bob);
    
    printf("Just Monika.\n");
    return 0;
}
