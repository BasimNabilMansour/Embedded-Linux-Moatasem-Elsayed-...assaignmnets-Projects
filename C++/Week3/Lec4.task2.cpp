#include <iostream>


bool areAllEven(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {2, 4, 6, 8, 10};
    int arr2[] = {2, 3, 6, 8, 10};
    int arr3[] = {0, -2, -4, -6};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "Array 1 is all even: " << (areAllEven(arr1, size1) ? "true" : "false") << std::endl;
    std::cout << "Array 2 is all even: " << (areAllEven(arr2, size2) ? "true" : "false") << std::endl;
    std::cout << "Array 3 is all even: " << (areAllEven(arr3, size3) ? "true" : "false") << std::endl;

    return 0;
}
