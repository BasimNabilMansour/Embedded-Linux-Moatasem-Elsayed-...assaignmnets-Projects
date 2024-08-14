#include <iostream>



bool hasAnyEven(const int arr[], int size) 
{
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) 
        {
            return true;
        }
    }
    return false;
}


int main() {
    int arr1[] = {1, 3, 5, 7, 9};     
    int arr2[] = {1, 2, 5, 7, 9};
    int arr3[] = {0, -3, -5, -7};   

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "Array 1 has any even numbers: " << (hasAnyEven(arr1, size1) ? "true" : "false") << std::endl;
    std::cout << "Array 2 has any even numbers: " << (hasAnyEven(arr2, size2) ? "true" : "false") << std::endl;
    std::cout << "Array 3 has any even numbers: " << (hasAnyEven(arr3, size3) ? "true" : "false") << std::endl;

    return 0;
}
