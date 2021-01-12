#include<stdio.h>

int move(int size, int arr[])
{
    int temp, left = 0, right = size-1;
    while(right > left)
    {
        while(arr[left] < 0 && right > left)
            left++;
        while(arr[right] >= 0 && right > left)
            right--;
        if(arr[left] >= 0 && arr[right] < 0)
            {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        left++;
        right--;
    }
}

int main()
{
    int sizeofarr=0, rotateby=0, counts[3]={0};
    printf("Program to move all negative numbers left of the array, before all positive numbers!\n");
    printf("Enter size of array: ");
    scanf("%d", &sizeofarr);
    int inputarr[sizeofarr];
    for(int i=0; i< sizeofarr; i++)
    {
        scanf("%d", &inputarr[i]);
    }
    move(sizeofarr, inputarr);
    for(int i=0; i< sizeofarr; i++)
    {
        printf("%d ", inputarr[i]);
    }
    return 0;
}