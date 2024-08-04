#include <iostream>
#include <vector>

// Function to merge two vectors
std::vector<int> mergeTwoArrays(const std::vector<int>& vec1, const std::vector<int>& vec2) 
{
    std::vector<int> mergedVec(vec1); // Start with the elements of the first vector
    mergedVec.insert(mergedVec.end(), vec2.begin(), vec2.end()); // Append elements of the second vector
    return mergedVec;
}

int main() 

{
    int size1, size2;

    // Get the size of the first array from the user
    std::cout << "Enter the size of the first array: ";
    std::cin >> size1;

    // Create a vector of the specified size
    std::vector<int> vec1(size1);

    // Get the array elements from the user
    std::cout << "Enter " << size1 << " elements of the first array:\n";
    for (int i = 0; i < size1; i++) {
        std::cin >> vec1[i];
    }

    // Get the size of the second array from the user
    std::cout << "Enter the size of the second array: ";
    std::cin >> size2;

    // Create a vector of the specified size
    std::vector<int> vec2(size2);

    // Get the array elements from the user
    std::cout << "Enter " << size2 << " elements of the second array:\n";
    for (int i = 0; i < size2; i++) {
        std::cin >> vec2[i];
    }

    // Merge the two vectors
    std::vector<int> mergedVec = mergeTwoArrays(vec1, vec2);

    // Output the merged vector elements to verify
    std::cout << "The merged array elements are:\n";
    for (const int& elem : mergedVec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
