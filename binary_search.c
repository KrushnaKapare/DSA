#include <stdio.h>

#define SIZE 9

int binary_search(int arr[SIZE], int key);
int rec_binary_search(int arr[SIZE], int key, int left, int right);
int main(void)
{

    int arr[SIZE] = { 11, 22, 33, 44, 55, 66, 44,88,99};
    int key;
    printf("Enter the key to search\n");      // 1. get the key from the user
    scanf("%d",&key);
    int index = binary_search(arr, key);
    if(index == -1)
        printf("key not found\n");
    else
        printf("key found at index %d\n",index);

    // recursive binary search
    printf("\n Recursive Function call :\n ");
    int res = rec_binary_search(arr, key, 0, SIZE-1);
    if(res == -1)
        printf("key not found\n");
    else
        printf("key found at index %d\n",res);
    
    return 0;
}


int binary_search(int arr[SIZE], int key)
{

    
   
    // find left, right and mid index

    int left = 0, right = SIZE-1, mid; 
    while(left <= right)
    {
        mid = (left + right) / 2;       // 2. divide the array
        if(key == arr[mid])             // 3. compare the key with mid element
            return mid;
        if(key < arr[mid])              // 4. check if the key is smaller or greater
        {
            right = mid - 1;            // continue the search in left sub-array

        }
        else 
        {
            left = mid + 1;             // continue the search in Right sub-array
        }
    }
    return -1;                  // key not found
}

int rec_binary_search(int arr[SIZE], int key, int left, int right)
{
    if(left > right)
        return -1;
    
    int res;
    int mid =( left + right) / 2;

    if(key == arr[mid])
        return mid;
    
    if(key == arr[mid])
        return mid;

    if(key < arr[mid])   // consider left sub-array
    {
        res = rec_binary_search(arr,key,left,mid-1);
    }
    else   // consider right sub-array
    {
        res = rec_binary_search(arr, key, mid+1, right);
    }
    return res;
}
