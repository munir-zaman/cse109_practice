#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        // n - i spaces
        for (int j = 0; j <= n - i - 1; j++) printf(" ");
        // 2 * i - 1 stars
        for (int k = 1; k <= 2 * i - 1; k++) printf("*");
        printf("\n");
    }
    return 0;
}
