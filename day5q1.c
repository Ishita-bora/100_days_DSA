#include <stdio.h>

int main() {
    int p, q;
    printf("Enter the size of the first array: ");
    scanf("%d", &p);

    int A[p];
    for (int i = 0; i < p; i++) {
        printf("Enter element %d of the first array: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &q);

    int B[q];
    for (int i = 0; i < q; i++) {
        printf("Enter element %d of the second array: ", i + 1);
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0;

   
    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }

    
    while (i < p) {
        printf("%d ", A[i]);
        i++;
    }

    
    while (j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}
