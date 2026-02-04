//Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

//Input:
//- First line: integer n
//- Second line: n space-separated integers
//- Third line: integer pos (1-based position to delete)

//Output:
//- Print the updated array with (n-1) elements, space-separated

//Example:
//Input:
//5
//10 20 30 40 50
//2

//Output:
//10 30 40 50

//Explanation: Delete position 2 (element 20), remaining elements shift left




#include <stdio.h>

int main() {
    int n, pos;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);

    
    if(pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }

    
    for(int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;  

    printf("Updated array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}