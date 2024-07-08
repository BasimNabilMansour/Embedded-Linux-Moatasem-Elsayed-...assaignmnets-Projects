#include <iostream>

void max(int num1,int num2,int num3);

void max(int num1,int num2,int num3)
{
    int max;
    if(num1>num2 && num1>num3)
    {
        max=num1;
    }
    else if (num2>num1 && num2>num3) 
    {
        max=num2;
    }
    else if (num3>num1 && num3>num2) 
    {
        max=num3;
    }
    std::cout<<max<<std::endl;
}

int main()
{
    int num1,num2,num3;
    std::cout<<"Enter the first value : ",std::cin>>num1;
    std::cout<<"Enter the second value : ",std::cin>>num2;
    std::cout<<"Enter the third value : ",std::cin>>num3;
    max(num1,num2,num3);


    return 0;
}