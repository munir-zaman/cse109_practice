#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int adj(int **mat, int i, int j) {
    return -1;
}

int main() {
    // shape of matrix
    int n;
    scanf("%d", &n);
    

    // allocate memory for each row
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) *(mat + i) = (int *)malloc(n * sizeof(int));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", (*(mat + y) + x));
        }
    }

    for (int i = 0; i < n; i++) free(*(mat + i));
    free(mat);
    return 0;
}
