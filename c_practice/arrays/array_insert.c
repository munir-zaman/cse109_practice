#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n; // initial size
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    int used = 0; // current available position
    int size = n; // allocated size 
    for (int i = 0; i < n; i++) {
        // input initial elements
        scanf("%d", array + i);
    }
    used += n;

    int val;
    while (1) {
        // only takes non-negative integers
        scanf("%d", &val);
        if (val < 0) break;
        // increase size if necessary
        if (used >= size) {
            size *= 2; 
            // reallocate memory and increase size 
            int* new_array = realloc(array, size * sizeof(int));
            if (new_array == NULL) {
                free(array);
                printf("realloc returned null\n");
                return -1;
            }
            else array = new_array;
            printf("increased size to %d\n", size);
            printf("address %p\n", (void *)array);
        }
        *(array + used) = val;
        used++;
    }

    for (int i = 0; i < used; i++) printf("%d ", *(array + i));
    free(array);
    return 0;
}
