#include<stdio.h>


void MinHeapify(int size, int arr[], int i)
{
    int index = i;
    int left = 2*index +1;
    int right = 2*index +2;

    if(left < size && arr[index] > arr[left])
        index = left;
    
    if(right < size && arr[index] > arr[right])
        index = right;
    
    if(index != i)
    {
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        MinHeapify(size, arr, index);
    }
}

void MaxHeapify(int size, int arr[], int i)
{
    int index = i;
    int left = 2*index +1;
    int right = 2*index +2;

    if(left < size && arr[index] < arr[left])
        index = left;
    
    if(right < size && arr[index] < arr[right])
        index = right;
    
    if(index != i)
    {
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        MaxHeapify(size, arr, index);
    }
}

void BuildMinHeap(int size, int arr[])
{
    int n = size/2 - 1;
    for(int i=n; i >= 0 ; i--)
    {
        MinHeapify(size, arr, i);
    }
}

void BuildMaxHeap(int size, int arr[])
{
    int n = size/2 - 1;
    for(int i=n; i >= 0 ; i--)
    {
        MaxHeapify(size, arr, i);
    }
}

int extractmax(int size, int arr[])
{
    int extracted;
    if(size <= 0)
        {
            printf("Cannot extract max, array already empty");
            return -1;
        }
    else if(size == 1)
        {
            size--;
            extracted = arr[0];
            return size;
        }
    extracted = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = extracted;
    size--;
    MaxHeapify(size,arr,0);
    //printf("\nSmallest %d", extracted);
    return size;
}

int extractmin(int size, int arr[])
{
    int extracted;
    if(size <= 0)
        {
            printf("Cannot extract min, array already empty");
            return -1;
        }
    else if(size == 1)
        {
            size--;
            extracted = arr[0];
            return size;
        }
    extracted = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = extracted;
    size--;
    MinHeapify(size,arr,0);
    //printf("\nSmallest %d", extracted);
    return size;
}


int main()
{
    int NumOfEle;
    printf("Enter the array size: ");
    scanf("%d",&NumOfEle);
    int InputArr[NumOfEle];
    for (int i=0; i<NumOfEle; i++)
    {
        scanf("%d", &InputArr[i]);
    }

    printf("\n Enter the value of k: ");
    int k, newsize = NumOfEle;
    scanf("%d", &k);


    BuildMaxHeap(NumOfEle, InputArr);    
    for(int i=0; i < k; i++)
       newsize = extractmax(newsize, InputArr);
    printf("\n %dth largest element is: %d\n", k, InputArr[newsize]); 

    /* here arr we using is different from input acc to seq of ele, but kth smallest will be same*/ 
    newsize = NumOfEle;
    BuildMinHeap(NumOfEle, InputArr);
    for(int i=0; i < k; i++)
       newsize = extractmin(newsize, InputArr);
    printf("\n %dth smallest element is: %d\n", k, InputArr[newsize]);
    
    return 0;
}