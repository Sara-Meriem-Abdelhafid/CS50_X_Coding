#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool linear_search(int arr[], int size, int target);

int main(int argc, char *argv[])
{   int array[] = {1, 7, 5, 3, 9, 11};
    int size = sizeof(array)/sizeof(array[0]); // sizeof(array) gives total size in bytes and sizeof(array[0]) gives size of one element
    printf("Hello, World!\n");
    printf("Number 2 is in the array ?: %s\n",linear_search(array, size, 2)? "true" : "false");
    return 0;
}

bool linear_search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            printf("Found %d at index %d\n", target, i);
            return true;
        }
    }
    printf("%d not found in the array\n", target);
    return false;
}

bool binary_search(int arr[], int size, int target)
{
    int left =0;
    int right = size -1;
}