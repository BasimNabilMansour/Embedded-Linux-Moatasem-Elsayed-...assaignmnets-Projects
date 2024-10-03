#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <algorithm>

class command
{
    private:
        std::string buf;
        
    public:
        command();
        std::string open_terminal();
        std::string open_calculator();
        std::string open_firefox();

};


#endif  