#include <iostream>


int main() 
{
    int number,n;
    std::cout << "Enter an integer: ";
    std::cin >> number;
    n =number;
    
    int sum_of_digits = 0;

    if (number < 0) 
    {
        number = -number;  
    }

    
    while (number > 0) 
    {
        sum_of_digits = sum_of_digits + number % 10;  
        number =number / 10;                  
    }
    std::cout << "The Sum of digit of: " << n <<" is "<< sum_of_digits << std::endl;

    return 0;
}