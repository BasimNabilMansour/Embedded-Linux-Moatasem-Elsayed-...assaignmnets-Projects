#include <iostream>
#include <string>
#include <cstring>      // For memset
#include <unistd.h>     // For close()
#include <arpa/inet.h>  // For socket functions
#include <cstdlib>      // For system()

void handleCommand(const std::string &command) {
    if (command.find("SEARCH_YOUTUBE:") == 0) {
        std::string query = command.substr(14);  // Extract search query
        std::string url = "https://www.youtube.com/results?search_query=" + query;

        // Replace spaces with + for URL compatibility
        for (size_t i = 0; i < url.size(); i++) {
            if (url[i] == ' ') url[i] = '+';
        }

        // Execute system command to open browser with YouTube search
        std::string sys_command = "xdg-open " + url; // Linux
        // std::string sys_command = "start " + url; // Windows
        // std::string sys_command = "open " + url; // macOS
        system(sys_command.c_str());
    } else {
        std::cout << "Unknown command received: " << command << "\n";
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Error creating server socket\n";
        return -1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Port number
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Error binding socket\n";
        return -1;
    }

    if (listen(server_socket, 5) == -1) {
        std::cerr << "Error in listen\n";
        return -1;
    }
    std::cout << "Server is listening on port 8080\n";

    sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);
    int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size);

    if (client_socket == -1) {
        std::cerr << "Error accepting client\n";
        return -1;
    }
    std::cout << "Client connected!\n";

    char buffer[1024];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        std::string received_command = buffer;
        std::cout << "Received command: " << received_command << "\n";
        handleCommand(received_command);
    }

    close(client_socket);
    close(server_socket);
    return 0;
}














