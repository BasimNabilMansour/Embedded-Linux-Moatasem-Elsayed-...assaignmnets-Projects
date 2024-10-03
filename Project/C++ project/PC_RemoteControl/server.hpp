#ifndef   SERVER_HPP
#define   SERVER_HPP


#include <array>
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>


class ServerHandler
{   
    private:
        int socket_fd; 
        int client_socket_fd;
        std::array<char,5000> buffer;


    public:
        ServerHandler();
        ~ServerHandler();
        bool server_init();
        bool server_listen();
        bool server_accept_client();
        bool server_send_msg(const std::string &message);
        void close_listening();
        void close_listening_client();
        std::string server_read();
        void trim_end(std::string& str);
        
        void server_close();

};

















#endif 