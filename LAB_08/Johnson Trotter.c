#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to print permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Find position of largest mobile element
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {

        // Check LEFT direction
        if (dir[i] == LEFT && i != 0 &&
            perm[i] > perm[i - 1] &&
            perm[i] > mobile) {

            mobile = perm[i];
            mobileIndex = i;
        }

        // Check RIGHT direction
        if (dir[i] == RIGHT && i != n - 1 &&
            perm[i] > perm[i + 1] &&
            perm[i] > mobile) {

            mobile = perm[i];
            mobileIndex = i;
        }
    }

    return mobileIndex;
}

// Johnson-Trotter function
void johnsonTrotter(int n) {

    int perm[n];
    int dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    // Print first permutation
    printPermutation(perm, n);

    while (1) {

        int mobileIndex = getMobile(perm, dir, n);

        // No mobile element
        if (mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + dir[mobileIndex];

        // Swap elements
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        // Swap directions
        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        int movedElement = perm[swapIndex];

        // Reverse direction of elements greater than moved element
        for (int i = 0; i < n; i++) {
            if (perm[i] > movedElement)
                dir[i] = -dir[i];
        }

        // Print permutation
        printPermutation(perm, n);
    }
}

int main() {

    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
