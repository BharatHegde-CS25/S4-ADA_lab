#include <stdio.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort (with partition inside)
void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pivot = A[high];
        int i = low - 1;
        int j;

        for (j = low; j < high; j++) {
            if (A[j] < pivot) {
                i++;
                swap(&A[i], &A[j]);
            }
        }

        swap(&A[i + 1], &A[high]);
        int pi = i + 1;

        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int n, i;
    int A[10000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    clock_t start, end;

    start = clock();   // Start timer

    quickSort(A, 0, n - 1);

    end = clock();     // End timer

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime Taken: %f seconds\n", time_taken);

    return 0;
}
