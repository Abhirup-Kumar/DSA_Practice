#include<stdio.h>

void rotate(int arr[], int size)
{
    int temp = arr[size-1];
    for(int i=size-1; i>0; i--)
        arr[i] = arr[i-1];
    arr[0] = temp;
}

int main()
{
    int sizeofarr=0;
    printf("Enter size of array: ");
    scanf("%d", &sizeofarr);
    int inputarr[sizeofarr];
    for(int i=0; i< sizeofarr; i++)
    {
        scanf("%d", &inputarr[i]);
    }
    rotate(inputarr,sizeofarr);
    for(int i=0; i< sizeofarr; i++)
    {
        printf("%d ", inputarr[i]);
    }
    return 0;
}