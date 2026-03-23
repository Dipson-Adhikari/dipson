//to implement selection sort
#include<stdio.h>
int selectionSort(int arr[],int n)
{
    int i,j,min_idx,temp;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }
}
int main()
{
    int n;
    printf("Enter the number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elementss of array:");
    scanf("%d",&arr[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    printf("Sorted array:");
    for(int i=0;i<n;i++)    {
        printf("%d ",arr[i]);
    }
    return 0;
}