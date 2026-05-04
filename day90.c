#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for(int i = 0; i < n; i++) {
        if(currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];

            if(painters > k)
                return 0;
        }
    }
    return 1;
}

int minTime(int boards[], int n, int k) {
    int sum = 0, max = 0;

    for(int i = 0; i < n; i++) {
        sum += boards[i];
        if(boards[i] > max)
            max = boards[i];
    }

    int low = max, high = sum, ans = sum;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &boards[i]);

    int result = minTime(boards, n, k);

    printf("Minimum time required: %d\n", result);

    return 0;
}