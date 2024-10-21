#include <iostream>
#include <string>
#include <cstring>      // For memset
#include <arpa/inet.h>  // For socket functions
#include <unistd.h>     // For close()

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Server port
    inet_pton(AF_INET, "192.168.100.11", &server_addr.sin_addr); // Connect to localhost

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Error connecting to server\n";
        return -1;
    }

    // Command format: "SEARCH_YOUTUBE:<query>"
    std::string command = "SEARCH_YOUTUBE:top gear";
    send(client_socket, command.c_str(), command.size(), 0);
    std::cout << "Command sent to server: " << command << "\n";

    close(client_socket);
    return 0;
}