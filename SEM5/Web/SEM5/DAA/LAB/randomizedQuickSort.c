//to implement randomized quick sort
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
int randomized_partition(int arr[], int low, int high)
{
    int random_index = low + rand() % (high - low + 1);
    swap(&arr[random_index], &arr[high]);
    return partition(arr, low, high);
}
void randomizedQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = randomized_partition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elementss of array:");
    scanf("%d", &arr[0]);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    randomizedQuickSort(arr, 0, n - 1);
    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
