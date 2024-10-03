#include "server.hpp"

ServerHandler::ServerHandler() : socket_fd(-1), client_socket_fd(-1) {}

ServerHandler::~ServerHandler()
{
    if (socket_fd != -1)
    {
        close(socket_fd);
    }
    if (client_socket_fd != -1)
    {
        close(client_socket_fd);
    }
}

bool ServerHandler::server_init()
{
    sockaddr_in sock_add;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        std::cerr << "Cannot create socket" << std::endl;
        return false;
    }
    /* TCP UDP APP ------->  PORT=8000 ...SERVER IP="192.168.100.2"  */
    sock_add.sin_family = AF_INET;
    sock_add.sin_port = htons(8000);
    inet_pton(AF_INET, "192.168.100.2", &sock_add.sin_addr);

    if (bind(socket_fd, (sockaddr *)&sock_add, sizeof(sock_add)) < 0)
    {
        std::cerr << "Cannot bind" << std::endl;
        return false;
    }
    return true;
}

bool ServerHandler::server_listen()
{
    if (listen(socket_fd, 2) < 0)
    {
        std::cerr << "Cannot listen" << std::endl;
        return false;
    }
    return true;
}

bool ServerHandler::server_accept_client()
{
    sockaddr_in client;
    socklen_t client_size = sizeof(client);
    client_socket_fd = accept(socket_fd, (sockaddr*)&client, &client_size);

    if (client_socket_fd < 0)
    {
        std::cerr << "Problem with client connection" << std::endl;
        return false;
    }
    return true;
}

bool ServerHandler::server_send_msg(const std::string &message)
{
    if (send(client_socket_fd, message.c_str(), message.size(), 0) < 0)
    {
        std::cerr << "Error sending message" << std::endl;
        return false;
    }
    return true;
}

std::string ServerHandler::server_read()
{
    ssize_t byteread = recv(client_socket_fd, static_cast<void *>(buffer.data()), buffer.size() - 1, 0);

    if (byteread < 0)
    {
        std::cerr << "Error receiving data" << std::endl;
        return "Error receiving data";
    }
    else if (byteread == 0)
    {
        std::cerr << "Client closed connection" << std::endl;
        return "Client closed connection";
    }
    else
    {
        std::string buffer_str(buffer.data(), byteread);
        std::cout << "Received message: " << buffer_str << std::endl;
        return buffer_str;
    }
}

void ServerHandler::server_close()
{
    if (client_socket_fd != -1)
    {
        close(client_socket_fd);
        client_socket_fd = -1;
    }
}

void ServerHandler::close_listening()
{
    if (socket_fd != -1)
    {
        close(socket_fd);
        socket_fd = -1;
    }
}

void ServerHandler::close_listening_client()
{
    if (client_socket_fd != -1)
    {
        close(client_socket_fd);
        client_socket_fd = -1;
    }
}

void ServerHandler::trim_end(std::string& str)
{
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}