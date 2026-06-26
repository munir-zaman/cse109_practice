#include<stdio.h>
#include<stdlib.h>

// compare must be of type int (const void *, const void *)
// we need to first typecast void pointers to be able to use them
int cmp(const void *a, const void *b) {
    return (*(int *)a > *(int *)b);
}

// Sort the array and ignore consecutive elements
int main() {
    int n;
    printf("Num of elements : \n");
    scanf("%d", &n);

    printf("Elements : \n");
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }
    
    qsort(array, n, sizeof(array[0]), cmp);
    int last = array[0];
    int counter = 1;
    printf("Unique Elements : \n");
    printf("%d, ", array[0]);
    for (int i = 1; i < n; i++) {
        if (last == array[i]) continue;
        else {
            counter++;
            last = array[i];
            if (i != n - 1) printf("%d, ", array[i]);
            else printf("%d", array[i]);
        }
    }
    
    return 0;
}
