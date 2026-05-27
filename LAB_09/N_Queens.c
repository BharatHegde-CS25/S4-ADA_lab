#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", i, board[i]);
    }
    printf("\n");
}

void solveNQueens(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid input\n");
        return 0;
    }
    solveNQueens(0, n);
    return 0;
}
