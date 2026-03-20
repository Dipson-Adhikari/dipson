//to implement fractional knapsack problem
#include <stdio.h>
void fractionalKnapSack(int n, float capacity, float weight[], float profit[])
{
    float ratio[n], x[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
        x[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
        }
    }
    float total_profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            x[i] = 1;
            total_profit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            x[i] = capacity / weight[i];
            total_profit += profit[i] * x[i];
            break;
        }
    }
    printf("Selected items:\n");
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0)
            printf("Item %d: %.2f\n", i + 1, x[i]);
    }
    printf("Total profit: %.2f\n", total_profit);
}
int main()
{
    int n;
    float capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    float weight[n], profit[n];
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &weight[i]);
    }
    printf("Enter the profits of the items: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &profit[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);
    fractionalKnapSack(n, capacity, weight, profit);
    return 0;
}