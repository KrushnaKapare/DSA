#include<stdio.h>
#define SIZE 9

int comparisons;

int linear_search(int arr[SIZE], int key);

int main()
{
    int arr[SIZE] = { 33,55,88,77,44,11,66,22,99};

    // 1. Get the key from user 
    int key;
    printf("Enter the key to search: \n");
    scanf("%d",&key);

    int index = linear_search(arr, key);

    if(index == -1)
        printf("Key Not Found\n");
    else
        printf("Key Found at index %d\n",index);
    
    printf("Comaprisons = %d\n",comparisons);
    return 0;
}

int linear_search(int arr[SIZE], int key)
{
    // 2. Start the traversal from the 1st element of the array
    for(int index = 0; index < SIZE; index++)
    {
        // 3. compare the key to search with each element of the array
        comparisons++;
        if(key == arr[index])
        {
            return index;       //If the Match is found , return the corresponding index

        }

        // Else, continue the search till the last index of the array
    }
    return -1;

}