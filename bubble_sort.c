#include <stdio.h>

#define SIZE 6
#define SWAP(a,b) int temp =a; a=b; b=temp

void bubble_sort (int arr[SIZE]);
void efficient_bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main(void )
{
    int arr[SIZE] = { 30, 20, 50, 60, 10, 70};
    printf("\n Before Normal Bubble Sort: \n");
    display(arr);
    printf("\n after normal bubble sort\n");
    bubble_sort(arr);
    display(arr);

    printf("\n before efficient bubble sort\n");
    display(arr);
    printf("\n after efficient bubble sort:\n");
    efficient_bubble_sort(arr);
    display(arr);
    return 0;
}

void bubble_sort(int arr[SIZE])
{
    int iteration=0, comp=0;
    for(int it = 0; it < SIZE-1; it++)
    {
        iteration++;
        for(int pos =0; pos<SIZE-1-it; pos++)
        {
            comp++;
            if(arr[pos] > arr[pos+1])
            {
                SWAP(arr[pos] , arr[pos+1]);
            }
        }
    }
    printf("\niterations = %d, comparisons = %d\n",iteration,comp);
}
void efficient_bubble_sort(int arr[SIZE])
{
    int flag, iteration=0,comp=0;
    for(int it=0; it<SIZE-1; it++)
    {
        flag = 0;
        iteration++;
        for(int pos = 0; pos < SIZE-1-it; pos++)
        {
            comp++;
            if(arr[pos] > arr[pos+1])
            {
                SWAP(arr[pos], arr[pos+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    printf("\n iteration = %d comparisons =%d\n",iteration,comp);
}

void display(int arr[SIZE])
{
    for(int i = 0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}
