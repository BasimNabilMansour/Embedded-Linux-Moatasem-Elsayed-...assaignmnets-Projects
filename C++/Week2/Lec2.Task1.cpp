#include <iostream>


int Max(int arr[], int size) 
{
    int max = arr[0];
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

int main() 
{
    int arr[] = {15, 3, 5, 7, 2, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maximum=Max(arr,size);
    std::cout << "The maximum value in the array is : " << maximum << std::endl;
    return 0;
}
