#include <iostream>


int main()
{
    int number;
    std::cout<<"Enter a number to know its multiplication table: ",std::cin>>number;
    for(int i=0;i<=10;i++)
    {
        std::cout<<number<<" x "<<i<<" = "<<i*number<<std::endl;
    }


    return 0;
}