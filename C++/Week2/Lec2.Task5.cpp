#include <iostream>
#include <vector>

// Function to get a vector from the user
std::vector<int> getUserVector() {
    int size;
    std::cout << "Enter the size of the vector: ";
    std::cin >> size;

    std::vector<int> vec(size);
    std::cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> vec[i];
    }
    return vec;
}

// Function to find and print even and odd numbers
void findEvenAndOdd(const std::vector<int>& vec) {
    std::vector<int> evenNumbers;
    std::vector<int> oddNumbers;

    for (int num : vec) {
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        } else {
            oddNumbers.push_back(num);
        }
    }

    std::cout << "Even numbers: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Odd numbers: ";
    for (int num : oddNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Get the vector from the user
    std::vector<int> vec = getUserVector();

    // Find and print even and odd numbers
    findEvenAndOdd(vec);

    return 0;
}
