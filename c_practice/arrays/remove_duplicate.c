#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }

    int *unique_array;
    unique_array = (int *) malloc(sizeof(array) / sizeof(array[0]));
    int used = 0;

    qsort(array, n, sizeof(int), cmp);
    int last = array[0];
    unique_array[used] = array[0];
    used++;
    for (int i = 1; i < n; i++) {
        if (last == array[i]) continue;
        else {
            unique_array[used] = array[i];
            last = array[i];
            used++;
        }
    }
    
    free(unique_array);
    for (int j = 0; j < used; j++) {
        printf("%d", unique_array[j]);
    }

}
