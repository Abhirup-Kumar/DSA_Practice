#include<iostream>

void RevArr(int [],int);

int main()
{
    int SizeOfArr=0;
    printf("Enter no. of element to be input in the array: ");
    scanf("%d", &SizeOfArr);
    int Array[SizeOfArr];
    for(int i=0; i<SizeOfArr; i++)
    {
        scanf("%d", &Array[i]);
    }
    RevArr(Array,SizeOfArr);
    for(int i=0; i<SizeOfArr; i++)
    {
        printf("%d", Array[i]);
    }
}

void RevArr(int arr[],int SizeOfArr) //int arr[] {is same as} int *arr, both take pointer to the first element only
{
    int low=0, temp=-1;
    int high = SizeOfArr-1;
    while(low < high)
    {
        temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;
        high--;
        low++;
    }
}