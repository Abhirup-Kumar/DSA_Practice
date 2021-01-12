#include<stdio.h>

int* count012(int size, int arr[], int *counts)
{
    for(int i=0; i< size; i++)
    {
        if(arr[i] == 0)
            counts[0]++;
        else if(arr[i] == 1)
            counts[1]++;
        else if(arr[i] == 2)
            counts[2]++;
    }
    return counts;
}

void sort(int size, int arr[], int *counts)
{
    int i=0;
    while(counts[0] != 0)
        {
            arr[i] = 0;
            i++;
            counts[0]--;
        }
    while(counts[1] != 0)
        {
            arr[i] = 1;
            i++;
            counts[1]--;
        }
    while(counts[2] != 0)
        {
            arr[i] = 2;
            i++;
            counts[2]--;
        }
}

int main()
{
    int sizeofarr=0, rotateby=0, counts[3]={0};;
    printf("Program to sort 0s 1s and 2s of unsorted array without using sorting algorithm!\n");
    printf("Enter size of array: ");
    scanf("%d", &sizeofarr);
    int inputarr[sizeofarr];
    for(int i=0; i< sizeofarr; i++)
    {
        scanf("%d", &inputarr[i]);
    }
    int *count = count012(sizeofarr, inputarr, counts);
    sort(sizeofarr, inputarr, count);
    for(int i=0; i< sizeofarr; i++)
    {
        printf("%d", inputarr[i]);
    }
    return 0;
}