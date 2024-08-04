#include <iostream>

int main() 
{
    // Define the lambda function
    auto square =[](int x)->int
    {
    return x*x;
    };
    

    // Get input from the user
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Calculate the square using the lambda function
    int result = square(number);

    // Output the result
    std::cout << "The square of " << number << " is " << result << std::endl;

    return 0;
}