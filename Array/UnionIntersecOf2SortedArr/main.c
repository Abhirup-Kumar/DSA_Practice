#include<stdio.h>
 //  empty arr
int Union(int size1, int size2, int arr1[], int arr2[], int finalarr[]) //url is the reason, in case of one of empty array, I cannot print finalarr in main as that arr is not changed in this union function.
{   //https://stackoverflow.com/questions/34844003/changing-array-inside-function-in-c#:~:text=you%20can%20change%20the%20integers,actually%20change%20the%20original%20array.
    int ptr1=0, ptr2=0, finalptr=0, NumOfSameElements=0;
    
    if(size1 ==0 && size2 ==0)
    {
        printf("Both arrays empty!\n");
        return -1;
    }

    else if(size1 == 0)
    {
        printf("Array 1 is empty!\n");
        finalarr = arr2;
        for(int i=0; i<size2; i++)
            printf("%d ", finalarr[i]);
        return -1;
    }

    else if(size2 == 0)
    {
        printf("Array 2 is empty!\n");
        finalarr = arr1;
        for(int i=0; i<size1; i++)
            printf("%d ", finalarr[i]);
        return -1;
    }

    while(ptr1 < size1 && ptr2 < size2)
    {   //could have used if condition for check all 3 cases but that might cause to run ptrs many time before while condition is checked and might go out of bound
        if(arr1[ptr1] == arr2[ptr2])
        {
            finalarr[finalptr] = arr1[ptr1];
            finalptr++;
            ptr1++;
            ptr2++; 
            NumOfSameElements++;
        }
        
        else if(arr1[ptr1] < arr2[ptr2])
        {
            finalarr[finalptr] = arr1[ptr1];
            finalptr++;
            ptr1++;
        }

        else if(arr1[ptr1] > arr2[ptr2])
        {
            finalarr[finalptr] = arr2[ptr2];
            finalptr++;
            ptr2++;
        }
    }
    int k;
    if(ptr1 == size1 && ptr2 == size2) // both arr completely checked 
    {
        k = ((size1+size2) - NumOfSameElements);
        return k;
    }

    if(ptr1 == size1)
    {
        while(ptr2 != size2)
        {
            finalarr[finalptr] = arr2[ptr2];
            finalptr++;
            ptr2++;
        }
        k = ((size1+size2) - NumOfSameElements);
        return k;
    }

    if(ptr2 == size2)
    {
        while(ptr1 != size1)
        {
            finalarr[finalptr] = arr1[ptr1];
            finalptr++;
            ptr1++;
        }
        k = ((size1+size2) - NumOfSameElements);
        return k;
    }

}

void Intersection(int size1, int size2, int arr1[], int arr2[])
{
    if(size1 ==0 || size2 ==0)
    {
        printf("One of the array empty, so no intersection!");
        return;
    }
    int ptr1=0, ptr2=0, finalptr=0, NumOfSameElements=0;
    int smaller = (size1 < size2) ? size1 : size2;
    int finalarr[smaller];
    while(ptr1 < size1 && ptr2 < size2)
    {
        if(arr1[ptr1] == arr2[ptr2])
        {
            finalarr[finalptr] = arr1[ptr1];
            finalptr++;
            ptr1++;
            ptr2++; 
            NumOfSameElements++;
        }
        
        else if(arr1[ptr1] < arr2[ptr2])
        {
            ptr1++;
        }

        else if(arr1[ptr1] > arr2[ptr2])
        {
            ptr2++;
        }
    }

    printf("Intersection of array: ");
    for(int i=0; i<NumOfSameElements; i++)
    printf("%d ", finalarr[i]);
}

int main()
{
    int SizeOfArr1=0, SizeOfArr2 =0;
    printf("Enter no. of element to be input in the array1: ");
    scanf("%d", &SizeOfArr1);
    int Array1[SizeOfArr1];
    for(int i=0; i<SizeOfArr1; i++)
    {
        scanf("%d", &Array1[i]);
    }
    
    printf("Enter no. of element to be input in the array2: ");
    scanf("%d", &SizeOfArr2);
    int Array2[SizeOfArr2];
    for(int i=0; i<SizeOfArr2; i++)
    {
        scanf("%d", &Array2[i]);
    }
    int finalarr[SizeOfArr1 + SizeOfArr2];
    int newsize = Union(SizeOfArr1, SizeOfArr2, Array1, Array2, finalarr);

    if(newsize != -1)
    {
        printf("Union of the arrays!");
        for(int i=0; i<newsize; i++)
        {
        printf("%d ", finalarr[i]);
        }
    }

    printf("\n");
    Intersection(SizeOfArr1, SizeOfArr2, Array1, Array2);
    
    return 0;
}