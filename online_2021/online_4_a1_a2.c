#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STR_SIZE 1000

struct student {
    char *name;
    int student_id;
    int mark;
};

int main() {
    int n;
    scanf("%d", &n);

    struct student *students = malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++) {
        (students + i)->name = (char *)malloc(MAX_STR_SIZE * sizeof(char));
        scanf("%s", (students + i)->name);
        scanf("%d %d", &((students + i)->student_id), &((students + i)->mark));
    }

    int lowest = 100;
    int highest = 0;
    for (int i = 0; i < n; i++) {
        int mark = ((students + i)->mark);
        if (lowest > mark) lowest = mark;
        if (highest < mark) highest = mark;
    }
    
    int *l; int *h;
    int l_count = 0; int h_count = 0;
    l = (int *) malloc(sizeof(int) * n);
    h = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        int mark = (students + i)->mark;
        if (lowest == mark) {
            *(l + l_count) = i;
            l_count++;
        }
        if (highest == mark) {
            *(h + h_count) = i;
            h_count++;
        }
    }

    printf("Lowest scorer : ");
    for (int i = 0; i < l_count; i++) {
        char *name = (students + *(l + i))->name;
        printf("%s", name);
        if (i != l_count - 1) printf(", ");
        else printf("\n");
    }

    printf("Highest scorer : ");
    for (int i = 0; i < h_count; i++) {
        char *name = (students + *(h + i))->name;
        printf("%s", name);
        if (i != h_count - 1) printf(", ");
        else printf("\n");
    }

    int val = (lowest & ((1 << 0) | (1 << 2) | (1 << 4) | (1 << 6))) | (highest & ((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7)));
    for (int i = 7; i >= 0; i--) {
        printf("%d", ((val & (1 << i)) > 0));
    }
    printf("\n");

    // free the string in students
    for (int i = 0; i < n; i++) free((students + i)->name);
    free(students);
    free(l); free(h);
}
