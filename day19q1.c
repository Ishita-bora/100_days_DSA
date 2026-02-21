#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int minSum = 1000000000;
    int x = 0, y = 1;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (abs(sum) < abs(minSum)) {
                minSum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}