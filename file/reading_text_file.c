#include <stdio.h>

int rfilec(void) {
    FILE *fp;
    int c;

    fp = fopen("text.txt", "r");
    if(fp == NULL) {
	printf("File text.txt should be present.");
	return 1;
    }

    while((c = fgetc(fp)) != EOF) {
	printf("%c", c);
    }
    fclose(fp);
    return 0;
}

int rfiles(void) {
    FILE *fp;
    char buffer[255];
    char *line;
    int line_n = 0;

    fp = fopen("text.txt", "r");
    if(fp == NULL) {
	printf("File text.txt should be present.");
	return 1;
    }

    while((line = fgets(buffer, 255, fp)) != NULL) {
	printf("%d: %s", ++line_n, line);
    }
    return 0;
}

int rfilescan(void) {
    FILE *fp;

    fp = fopen("monsters", "r");
    if(fp == NULL) {
	printf("File text.txt should be present.");
	return 1;
    }

    char name[255];
    float danger_percentage;
    int amount;
    while((fscanf(fp, "%s %f %d", name, &danger_percentage, &amount)) != EOF) {
	printf("Enemy type is: `%s`, the danger of it is: `%.2f percent` and the amount of them on the known map are: `%d`\n", name, danger_percentage, amount);
    }
    return 0;
}

int wfile(void) {
    FILE *fp;
    fp = fopen("write_into", "w");
    // fp = stdout; outputs the text into the console.
    if(fp == NULL) {
	printf("file `write_into` should be present.");
	return 1;
    }
    char* text = "is monikawai";
    int num = 100;
    
    fputc('M', fp);
    fputc('o', fp);
    fputs("nika", fp);
    fputc('\n', fp);
    fprintf(fp, "%s\n%d percent love!\n", text, num);

    fclose(fp);

    return 0;
}

int fbinw(void) {
    unsigned char binary[5] = {55, 56, 67, 54, 69};
    FILE *fp;
    if((fp = fopen("text_write.bin", "wb")) == NULL) {
	printf("file `text_write.bin` should be present.");
	return 1;
    }
    fwrite(&binary, sizeof(char), 5, fp);
    return 0;
}

int fbinr(void) {
    unsigned char c;
    FILE *fp;
    if((fp = fopen("text.bin", "rb")) == NULL) {
	printf("file `text.bin` should be present.");
	return 1;
    }
    while((fread(&c, sizeof(char), 1, fp) > 0)) {
	printf("%c", c);
    }

    return 0;
}

int main(void) {
    fbinw();
    return 0;
}
