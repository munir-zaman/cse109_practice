#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) printf(" ");
        for (int k = 1; k <= 2 * n - 1; k++) printf("*");
        printf("\n");
    }
    return 0;
}
