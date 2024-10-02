#include "server.hpp" 
#include "command.hpp"  

int main() {

    ServerHandler server;  
    command cmd;           
    std::string buffer;   

    if(!server.server_init())
    {
        std::cerr<<"server init failed";
        return -1;  
    }

    if(!server.server_listen())
    {
        std::cerr<<"server listen failed";
        return -2;  
    }

    
    while(true)
    {
        std::cout << "waiting for client connection ....." << std::endl;

        if(server.server_accept_client())
        {
            std::cout <<"client connected" << std::endl;
            
            server.server_send_msg("/.........................../\n");
            server.server_send_msg("menu\n");
            server.server_send_msg("Enter command to Execute or exit: ");

            while(true)
            {
                buffer = server.server_read();
                server.trim_end(buffer);

                if(buffer == "exit")
                {
                    server.server_send_msg("exiting the server..");
                    server.server_close();  
                    server.server_send_msg("program finished...");
                    return 0;
                }

                if(buffer == "terminal")
                {
                    buffer = cmd.open_terminal();  
                    server.server_send_msg(buffer);
                    buffer="nothing";
                    
                }

                if(buffer == "calculator")
                {
                    buffer = cmd.open_calculator();  
                    server.server_send_msg(buffer);
                    buffer="nothing";
                
                }

                if(buffer == "firefox")
                {
                    buffer = cmd.open_firefox();  
                    server.server_send_msg(buffer);
                    buffer="nothing";
                }
                
            }
        }
    }
}