//to find minimum and maximum of a list using min-max algorithm
#include <stdio.h>
void minMax(int arr[], int n, int *min, int *max)
{
    if (n == 1)
    {
        *min = arr[0];
        *max = arr[0];
        return;
    }
    if (arr[0] < arr[1])
    {
        *min = arr[0];
        *max = arr[1];
    }
    else
    {
        *min = arr[1];
        *max = arr[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] < *min)
            *min = arr[i];
        else if (arr[i] > *max)
            *max = arr[i];
    }
}
int mainm()
{
    int n, min, max;
    printf("Enter the number of elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    minMax(arr, n, &min, &max);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    return 0;
}