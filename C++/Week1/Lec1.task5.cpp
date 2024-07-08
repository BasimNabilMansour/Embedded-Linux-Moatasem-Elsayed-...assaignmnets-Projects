#include <iostream>


int main()
{
    int number;
    std::cout<<"Enter a number to know its multiplication table: ",std::cin>>number;
    for(int i=0;i<=number;i++)
    {
        std::cout<<i<<" x "<<number<<" = "<<i*number<<std::endl;
    }


    return 0;
}