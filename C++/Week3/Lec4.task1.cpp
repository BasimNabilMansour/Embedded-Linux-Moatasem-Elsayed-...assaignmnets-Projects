#include <iostream>
#include <cctype> 

bool isDigit(char c) 
{
    return std::isdigit(c);
}

int main() 
{
    char testChar;
    std::cout<<"enter any input to see if it is a digit or not: ";
    std::cin>>testChar;
    
    if (isDigit(testChar)) {
        std::cout << testChar << " is a digit." << std::endl;
    } else {
        std::cout << testChar << " is not a digit." << std::endl;
    }

    return 0;
}