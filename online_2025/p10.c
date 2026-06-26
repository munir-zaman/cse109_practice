#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* Modify_Matrix(int **arr, int row, int column, int check) {
    int *all_row_sizes = malloc(row * sizeof(int));
    for (int i = 0; i < row; i++) {
        int sum = 0;
        int size = 0;
        for (int j = 0; j < column; j++) {
            int val = *(*(arr + i) + j);
            if (val < 0) break;
            sum += val;
            if (sum < check) {
                size++;
            }
            else {
                // need to remove current element
                sum -= val; // fix the sum
                for (int k = j; k + 1 < column; k++) {
                    // shift elements
                    *(*(arr + i) + k) = *(*(arr + i) + k + 1);
                }
                *(*(arr + i) + column - 1) = -1;
                j--; // cant skip the current element after shifting
                // column--; // skip the -1 at the end
            }
        }
        
        *(arr + i) = realloc(*(arr + i), size * sizeof(int));
        *(all_row_sizes + i) = size;
    }

    return all_row_sizes;
}

int main() {
    int check, row, column;
    // [[], [cols], ..., rows]
    scanf("%d %d %d", &check, &row, &column);

    int **arr = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        *(arr + i) = malloc(column * sizeof(int));
        for (int j = 0; j < column; j++) {
            scanf("%d", (*(arr + i) + j));
        }
    }

    int *all_row_sizes = Modify_Matrix(arr, row, column, check);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < *(all_row_sizes + i); j++) {
            printf("%d,", *(*(arr + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++) free(*(arr + i));
    free(arr);
    return 0;
}
