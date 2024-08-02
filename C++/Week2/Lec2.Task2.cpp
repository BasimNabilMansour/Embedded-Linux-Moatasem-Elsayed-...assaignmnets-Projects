#include <iostream>
#include <vector>
#include <algorithm>  

int main() 
{
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    //dynamic array
    std::vector<int> array(size);

    // Get the array elements from the user
    std::cout << "Enter " << size << " elements of the array:\n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    // Output the vector elements to verify
    std::cout << "The array elements are:\n";
    for (int i = 0; i < size; i++) 
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int target;
    // Get the number to search for
    std::cout << "Enter the number you want to search for: ";
    std::cin >> target;

    // Use std::find to search for the number in the vector
    auto it = std::find(array.begin(), array.end(), target);

    // Check if the number was found
    if (it != array.end()) {
        int index = std::distance(array.begin(), it);
        std::cout << "Number "<<target<< " found at index " << index << std::endl;
    } else {
        std::cout << "Number not found in the array." << std::endl;
    }

    return 0;
}
