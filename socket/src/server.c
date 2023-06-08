// Server side C/C++ program to demonstrate Socket
// programming

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[]) {

    char* hello = "Hello from server";
    char buffer[1024] = { 0 };

    int server_fd;
    int new_socket;
    int opt = 1;

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    int addrlen = sizeof(address);



    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {

        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {

        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {

        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {

        perror("accept");
        exit(EXIT_FAILURE);
    }



    read(new_socket, buffer, 1024);
    printf("Server: message received - %s\n", buffer);

    send(new_socket, hello, strlen(hello), 0);
    printf("Server: Hello message sent\n");

    // closing the connected socket
    close(new_socket);

    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);

    return 0;
}
