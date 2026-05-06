#include <stdio.h>



int knapsack(int n, int weight[], int profit[], int capacity)
{
    int dp[n+1][capacity+1];
    int i, w;

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i-1] <= w)
                dp[i][w] = max(
                    profit[i-1] + dp[i-1][w - weight[i-1]],
                    dp[i-1][w]
                );

            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, i, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(n, weight, profit, capacity);

    printf("Maximum Profit = %d\n", result);

    return 0;
}
