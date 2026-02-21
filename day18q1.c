#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int a[n], b[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    k = k % n;

    int index = 0;

    for(int i = n - k; i < n; i++) {
        b[index++] = a[i];
    }

    for(int i = 0; i < n - k; i++) {
        b[index++] = a[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}