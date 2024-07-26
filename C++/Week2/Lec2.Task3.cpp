#include <iostream>
using namespace std;

void deleteNumber(int arr[], int &size, int num) {
    int position = -1;
    
    // Find the position of the number to delete
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            position = i;
            break;
        }
    }
    
    // If the number is found, shift elements to the left
    if (position != -1) {
        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;  // Decrease the size of the array
    } else {
        cout << "Number not found in the array." << endl;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int* arr = new int[size];  // Dynamically allocate array

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, size);

    int num;
    cout << "Enter the number to delete: ";
    cin >> num;

    deleteNumber(arr, size, num);

    cout << "Array after deletion: ";
    printArray(arr, size);

    delete[] arr;  // Free dynamically allocated memory

    return 0;
}

