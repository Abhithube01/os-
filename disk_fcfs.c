#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, n, req[50], mov = 0, cp;

    printf("Enter the current position of the head: ");
    scanf("%d", &cp);

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request order:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("%d -> %d", cp, req[0]);
    mov = mov + abs(cp - req[0]);

    for(i = 1; i < n; i++) {
        mov = mov + abs(req[i] - req[i - 1]);
        printf(" -> %d", req[i]);
    }

    printf("\n");
    printf("Total head movement = %d\n", mov);

    return 0;
}
