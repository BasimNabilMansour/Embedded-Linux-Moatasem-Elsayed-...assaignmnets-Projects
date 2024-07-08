#include <iostream>


int main()
{
    int num;
    std::cout<<"ASCII Code Table :"<<std::endl;
    std::cout<<"+-------+-------+"<<std::endl;
    std::cout<<"| Char  | ASCII |"<<std::endl;
    std::cout<<"+-------+-------+"<<std::endl;
    for(num=33;num<=99;num++)
    {
        std::cout<<"|  " << num <<"   |   "<< (char)num <<"   |"<<std::endl;
    }
    for(num=100;num<127;num++)
    {
        std::cout<<"|  " << num <<"  |   "<< (char)num <<"   |"<<std::endl;
    }
    return 0;

}