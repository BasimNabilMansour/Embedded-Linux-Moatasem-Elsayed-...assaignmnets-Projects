#include <iostream>


int main()
{
    char letter;
    std::cout<<"Enter the Letter: ",std::cin>>letter;
    if(letter=='a'||letter=='e'||letter=='i'||letter=='0'||letter=='u')
    {
        std::cout<<"The letter is a Vowel"<<std::endl;
    }
    else 
    {
        std::cout<<"The letter is not a Vowel"<<std::endl;
    }


    return 0;
}