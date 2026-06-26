#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void Unique_Rows(int **arr, int row, int col, int *new_row_size) {
    int row_sz = row;

    for (int i = 0; i < row; i++) {
        if (*(arr + i) == NULL) break;
        for (int k = i + 1; k < row; k++) {
            if (*(arr + k) == NULL) break;
            int status = 1;
            for (int j = 0; j < col; j++) {
                if (*(*(arr + i) + j) != *(*(arr + k) + j)) {
                    status = 0;
                    break;
                }
            }

            if (status) {
                // remove this row
                row_sz--;
                free(*(arr + k));
                for (int l = k; l + 1 < row; l++) {
                    *(arr + l) = *(arr + l + 1);
                }
                *(arr + row - 1) = NULL; 
                k--; // cant skip current row after shifting
            }
        }
    }

    *new_row_size = row_sz;
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    int **arr = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        *(arr + i) = malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            scanf("%d", (*(arr + i) + j));
        }
    }
    
    int new_row_size;
    Unique_Rows(arr, row, col, &new_row_size);
    arr = realloc(arr, new_row_size * sizeof(int *));

    for (int i = 0; i < new_row_size; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < new_row_size; i++) {
        free(*(arr + i));
    }
    free(arr);
    return 0;
}
