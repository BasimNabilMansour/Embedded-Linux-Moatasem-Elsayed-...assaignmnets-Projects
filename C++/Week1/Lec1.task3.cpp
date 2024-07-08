#include <iostream>


int main()
{
    while (1)
    {
    int angle1,angle2,angle3;
    std::cout<<"Enter the first angle: ",std::cin>>angle1;
    std::cout<<"Enter the second angle: ",std::cin>>angle2;
    std::cout<<"Enter the third angle: ",std::cin>>angle3;
    if(angle1+angle2+angle3==180)
    {
        if(angle1 ==90 ||angle2==90||angle3 ==90)
        {
            std::cout<<"This is a Right angle triangle"<<std::endl;
        }
        else
        {
            std::cout<<"This is not a Right angle triangle"<<std::endl;
        }
    }
    else 
    {
        std::cout<<"This is not a triangle"<<std::endl;
        
    }
    std::cout<<"Please try again"<<std::endl;

    }
    return 0;
}