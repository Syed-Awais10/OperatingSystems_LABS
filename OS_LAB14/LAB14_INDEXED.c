#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    int f[50], i, k, j, inde[50], n, c, p;

    // Initialize all blocks to 0 (free)
    for(i = 0; i < 50; i++)
        f[i] = 0;

    while (1) {
        printf("\nEnter index block: ");
        scanf("%d", &p);

        if (p < 0 || p >= 50) {
            printf("Invalid block index! Try again.\n");
            continue;
        }

        if(f[p] == 0) {
            f[p] = 1;
            printf("Enter number of files on index: ");
            scanf("%d", &n);

            if (n > 50) {
                printf("Too many files! Try again.\n");
                f[p] = 0;
                continue;
            }

            printf("Enter the block numbers:\n");
            int valid = 1;
            for(i = 0; i < n; i++) {
                scanf("%d", &inde[i]);
                if(inde[i] < 0 || inde[i] >= 50 || f[inde[i]] == 1) {
                    valid = 0;
                }
            }

            if (!valid) {
                printf("One or more blocks are already allocated or invalid. Try again.\n");
                f[p] = 0;
                continue;
            }

            for(j = 0; j < n; j++)
                f[inde[j]] = 1;

            printf("\nFile allocated successfully.\nIndexed block: %d\n", p);
            for(k = 0; k < n; k++)
                printf("%d -> %d : Allocated\n", p, inde[k]);
        }
        else {
            printf("Block already allocated. Try a different index.\n");
            continue;
        }

        printf("Enter 1 to enter more files, or 0 to exit: ");
        scanf("%d", &c);
        if (c != 1)
            break;
    }

    return 0;
}

