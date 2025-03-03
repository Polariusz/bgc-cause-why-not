#include <stdio.h>
#include <stdlib.h>

void print_matrix(int h, int w, int m[h][w])
{
    for(int row = 0; row < h; row++) {
	for(int col = 0; col < w; col++) {
	    if(col == 0) {
		printf("%3d ", row);
	    } else if(row == 0) {
		printf("%3d ", col);
	    }
	    else {
		printf("%3d ", m[row][col]);
	    }
	}
	printf("\n");
    }
}


void vla_2()
{
    int rows = 20;
    int columns = 20;

    int matrix[rows][columns];

    for(int row = 0; row < rows; row++) {
	for(int col = 0; col < columns; col++) {
	    matrix[row][col] = row*col;
	}
    }
    print_matrix(rows, columns, matrix);
}

void vla_1()
{
    int n;
    char buf[32];
    printf("Enter a number: "); fflush(stdout);
    fgets(buf, sizeof buf, stdin);
    n = strtoul(buf, NULL, 10);

    int v[n];

    for(int i = 0; i < n; i++) {
	v[i] = i*10;
    }

    for(int i = 0; i < n; i++) {
	printf("v[%d] = %d ", i, v[i]);
    }
    printf("\n");
}

int main(void)
{
    vla_2();

    printf("Just Monika.\n");
    return 0;
}
