//to perform sequential search using iterartive method

#include<stdio.h>
int sequential_search(int arr[],int n,int key)
{
    for (int i=0;i<n;i++)
    {
        if (arr[i] == key)
            return i; 
    }
    return -1;

}
int main()
{
    int n,key;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to search:");
    scanf("%d",&key);
    int result=sequential_search(arr,n,key);
    if(result != -1)
        printf("Element found at index: %d",result);
    else
        printf("Element not found in the array.");
    return 0;

}