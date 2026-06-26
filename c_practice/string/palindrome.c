#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SZ 1000

int main() {
    char text[MAX_STRING_SZ];
    scanf("%s", text);

    int len = strlen(text);
    int status = 1;
    for (int i = 0; i < len; i++) {
        if (2 * i > len) break;
        if (text[i] != text[len - i - 1]) {
            status = 0;
            break;
        }
    }

    printf("%d", status);
    return 0;
}
