#include <iostream>


void SearchNumber(int arr[], int size, int search) 
{
    int flag=0;
    
        for (int i = 0; i <= size; i++) 
        {
            if (arr[i] == search) 
            {
                std::cout << "The number " << search << " is found in the array in index."<<i << std::endl;
                flag=1;
            }
            
        }
        if (flag==0)
        {
            std::cout << "The number " << search << " is not found in the array." << std::endl;
            
        }

    
}

int main() 
{
    while (1)
    {
        
    
    int arr[] = {1, 3, 5, 7, 2, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num;

    std::cout << "Enter the number to search: ";
    std::cin >> num;

    SearchNumber(arr,size,num);
    }
    return 0;
}

