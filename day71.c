#include <stdio.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            int h = key % m;
            int j = 0;

            while (j < m) {
                int idx = (h + j * j) % m;
                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                j++;
            }
        } else if (op[0] == 'S') {
            int h = key % m;
            int j = 0;
            int found = 0;

            while (j < m) {
                int idx = (h + j * j) % m;
                if (table[idx] == EMPTY)
                    break;
                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                j++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}