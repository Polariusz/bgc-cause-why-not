#include <stdio.h>
#include <stdlib.h>

struct Page {
    char *text;
    int chapter;
    int number;
};

struct Book {
    char* title;
    struct Page foreword;
    struct Page* content;
};

int main(void)
{
    struct Book book = {
	.title="C language in Minecraft Redstone.",
	.foreword.text="This is the beginning of the book.",
	.foreword.chapter=0,
	.foreword.number=0,
	.content=malloc(sizeof(struct Page))
    };
    printf("title: %s  foreword: %s at page %d in chapter %d.  Sizeof content: %ld\n", book.title, book.foreword.text, book.foreword.number, book.foreword.chapter, sizeof(book.content));
    printf("Just Monika.\n");
    return 0;
}
