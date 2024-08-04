#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr={1,23,3,4,5,6};

    // Lambda function to sort in ascending order
    std::sort(arr.begin(), arr.end(), [](int a, int b) 
    {
        return a < b;
    });
    
    std::cout << "Sorted in ascending order: ";
    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });

    std::cout << "Sorted in descending order: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}
