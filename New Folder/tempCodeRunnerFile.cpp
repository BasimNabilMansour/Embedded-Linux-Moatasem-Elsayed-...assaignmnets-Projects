#include <iostream>
#include <vector>

void printMessage(std::string message="Hello World!",
           std::string country ="India")
           {
            std::cout <<message.substr() <<std::endl;
            std::cout <<country <<std::endl;
           }

int main()
{
printMessage();
printMessage("welcome","Egypt");

return 0;
}           