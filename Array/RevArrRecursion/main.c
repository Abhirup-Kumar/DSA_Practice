#include<stdio.h>

void revarr(int *arr,int low, int high)
{
    int tempforswap;
    if(low>=high)
        return;
    tempforswap = arr[low];
    arr[low] = arr[high];
    arr[high] = tempforswap;
    revarr(arr, low+1, high-1); /* V.V.IMP. do not use increment/decrement operator in function call...*/
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    revarr(arr,0,size-1);
    for(int i=0; i<size; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}