#include <iostream>


bool searchNumber(int arr[], int size, int num) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == num) 
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    int arr[] = {1, 3, 5, 7, 2, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num;

    std::cout << "Enter the number to search: ";
    std::cin >> num;

    if (searchNumber(arr, size, num)) 
    {
        std::cout << "The number " << num << " is found in the array." << std::endl;
    } 
    else 
    {
        std::cout << "The number " << num << " is not found in the array." << std::endl;
    }

    return 0;
}