#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
void main()
{
    int arrayOfInteger[100000];
    arrayRandomIntegers(arrayOfInteger);
    Output(arrayOfInteger,10);
    Output(arrayOfInteger,100);
    Output(arrayOfInteger,1000);
    Output(arrayOfInteger,10000);
    Output(arrayOfInteger,100000);
}
void Output(int arrayOfInteger[], int arraySize)
{
clock_t t;
    //Start timer
    t = clock();
    Selection(arrayOfInteger, arraySize);
    //End timer
    t = clock() - t;
    //Time in ms
    double time_taken = ((double)t)/(CLOCKS_PER_SEC/1000);
    printf("\n***** %d Elements Computing Time *****\n\n",arraySize);
    printf("Selection Sort: %.3f ms\n",time_taken);
    time_taken=0;
    t = clock();
    Bubble(arrayOfInteger,arraySize);
    t = clock() - t;
    time_taken = ((double)t)/(CLOCKS_PER_SEC/1000);
    printf("Bubble Sort: %.3f ms\n",time_taken);
    time_taken=0;
    t = clock();
    Insertion(arrayOfInteger, arraySize);
    t = clock() - t;
    time_taken = ((double)t)/(CLOCKS_PER_SEC/1000);
    printf("Insertion Sort: %.3f ms\n",time_taken);
    time_taken=0;
    t = clock();
    Merge(arrayOfInteger, 0, arraySize - 1);
    t = clock() - t;
    time_taken = ((double)t)/(CLOCKS_PER_SEC/1000);
    printf("Merge Sort: %.3f ms\n",time_taken);
    time_taken=0;
    t = clock();
    quickSort(arrayOfInteger,0,arraySize-1);
    t = clock() - t;
    time_taken = ((double)t)/(CLOCKS_PER_SEC/1000);
    printf("Quick Sort: %.3f ms\n",time_taken);
    time_taken=0;
    t = clock();
    heapSort(arrayOfInteger,arraySize);
    t = clock() - t;
    time_taken = ((double)t)/(CLOCKS_PER_SEC/1000);
    printf("Heap Sort: %.3f ms\n",time_taken);
    time_taken=0;
}
void heapify(int arrayOfInteger[], int arraySize, int Node)
{
    int temp;
    int largest = Node;
    int left = 2*Node + 1;
    int right = 2*Node + 2;

    if (left < arraySize && arrayOfInteger[left] >arrayOfInteger[largest])
    {
        largest = left;
    }

    if (right < arraySize && arrayOfInteger[right] > arrayOfInteger[largest])
    {
        largest = right;
    }
    if (largest != Node)
    {
        temp = arrayOfInteger[Node];
        arrayOfInteger[Node]= arrayOfInteger[largest];
        arrayOfInteger[largest] = temp;
        heapify(arrayOfInteger, arraySize, largest);
    }
}

void heapSort(int arrayOfInteger[], int arraySize)
{
    int temp;
    int i;
    for (i = arraySize / 2 - 1; i >= 0; i--)
        heapify(arrayOfInteger, arraySize, i);
    for (i=arraySize-1; i>=0; i--)
    {
        temp = arrayOfInteger[0];
        arrayOfInteger[0]= arrayOfInteger[i];
        arrayOfInteger[i] = temp;
        heapify(arrayOfInteger, i, 0);
    }
}
void arrayRandomIntegers(int Array[])
{

    srand((unsigned)time(NULL));
    for(int i=0; i<sizeof(Array); i++)
    {
        Array[i]=rand()%INT_MAX;
    }
}
void Selection(int arrayOfInteger[], int arraySize)
{
    int position, temp;
    for (int i = 0; i < (arraySize - 1); i++)
    {
        //Set the location of index i in array as the minimum element
        position = i;
        //Search for element lower than the position
        for (int j = i + 1; j < arraySize; j++)
        {
            //Get index of the lowest element in the array
            if (arrayOfInteger[position] > arrayOfInteger[j])
            {
                position = j;
            }
        }
        //If first element is not the lowest then swap it with the lowest
        if (position != i)
        {
            temp = arrayOfInteger[i];
            arrayOfInteger[i] = arrayOfInteger[position];
            arrayOfInteger[position] = temp;
        }
        else
        {
            continue;
        }
    }
}
void Bubble(int arrayOfInteger[], int arraySize)
{
    int temp;
    for (int i = 0 ; i < arraySize - 1; i++)
    {
        for (int j = 0 ; j < arraySize - i - 1; j++)
        {
            //Compare each element with the next one
            if (arrayOfInteger[j] > arrayOfInteger[j+1])
            {
                temp       = arrayOfInteger[j];
                arrayOfInteger[j]   = arrayOfInteger[j+1];
                arrayOfInteger[j+1] = temp;
            }
        }
    }
}

void Insertion(int arrayOfInteger[], int arraySize)
{
    bool flag;
    int position;
    int j;
    for (int i = 1 ; i <= arraySize - 1; i++)
    {
        position = arrayOfInteger[i];
        for (j = i - 1 ; j >= 0; j--)
        {
            if (arrayOfInteger[j] > position)
            {
                arrayOfInteger[j+1] = arrayOfInteger[j];
                flag = true;
            }
            else
            {
                break;
            }
        }
        if (flag)
        {
            arrayOfInteger[j+1] = position;
        }
    }
}
/*
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/
void Merge(int arrayOfInteger[], int startElement, int lastElement)
{
    if (startElement < lastElement)
    {
// Finding mid element
        int midElement = startElement+(lastElement-startElement)/2;
// Recursively sorting both the halves
        Merge(arrayOfInteger, startElement, midElement);
        Merge(arrayOfInteger, midElement+1, lastElement);

// Merge the array
        mergeArrays(arrayOfInteger, startElement, midElement, lastElement);
    }
}
void mergeArrays(int arrayOfInteger[], int startElement, int midElement, int lastElement)
{
    int i, j, k;
    int firstPart = midElement - startElement + 1;
    int secondPart = lastElement - midElement;
// Create temp arrays
    int firstSubArray[firstPart], secondSubArray[secondPart];
// Copy data to temp array
    for (i = 0; i < firstPart; i++)
    {
        firstSubArray[i] = arrayOfInteger[startElement + i];
    }
    for (j = 0; j < secondPart; j++)
    {
        secondSubArray[j] = arrayOfInteger[midElement + 1+ j];
    }
// Merge the temp arrays
    i = 0;
    j = 0;
    k = startElement;
    while (i < firstPart && j < secondPart)
    {
        if (firstSubArray[i] <= secondSubArray[j])
        {
            arrayOfInteger[k] = firstSubArray[i];
            i++;
        }
        else
        {
            arrayOfInteger[k] = secondSubArray[j];
            j++;
        }
        k++;
    }
// Copy the remaining elements of firstSubArray[]
    while (i < firstPart)
    {
        arrayOfInteger[k] = firstSubArray[i];
        i++;
        k++;
    }
// Copy the remaining elements of secondSubArray[]
    while (j < secondPart)
    {
        arrayOfInteger[k] = secondSubArray[j];
        j++;
        k++;
    }
}
void quickSort(int arrayOfInteger[],int startElement,int lastElement)
{
    int i, j, pivot, temp;
    if(startElement<lastElement)
    {
        pivot=startElement;
        i=startElement;
        j=lastElement;

        while(i<j)
        {
            while(arrayOfInteger[i]<=arrayOfInteger[pivot]&&i<lastElement)
                i++;
            while(arrayOfInteger[j]>arrayOfInteger[pivot])
                j--;
            if(i<j)
            {
                temp=arrayOfInteger[i];
                arrayOfInteger[i]=arrayOfInteger[j];
                arrayOfInteger[j]=temp;
            }
        }

        temp=arrayOfInteger[pivot];
        arrayOfInteger[pivot]=arrayOfInteger[j];
        arrayOfInteger[j]=temp;
        quickSort(arrayOfInteger,startElement,j-1);
        quickSort(arrayOfInteger,j+1,lastElement);

    }
}
