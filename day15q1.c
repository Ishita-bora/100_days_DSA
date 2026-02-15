Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.


#include <stdio.h>

int main() {
    int m, n, i, j;
    int a[100][100];
    int sum = 0;

    scanf("%d %d", &m, &n);

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int limit = (m < n) ? m : n;

    for(i = 0; i < limit; i++) {
        sum = sum + a[i][i];
    }

    printf("%d", sum);

    return 0;
}
