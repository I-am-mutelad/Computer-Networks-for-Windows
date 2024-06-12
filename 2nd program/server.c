#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in server, client;
    int addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server --->";

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("socket creation failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to localhost port 8080
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("bind failed with error code : %d", WSAGetLastError());
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, SOMAXCONN) == SOCKET_ERROR) {
        printf("listen failed with error code : %d", WSAGetLastError());
        return 1;
    }

    printf("\n\nServer listening on port %d...\n", PORT);

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&client, &addrlen)) == INVALID_SOCKET) {
        printf("accept failed with error code : %d", WSAGetLastError());
        return 1;
    }

    printf("\n##---Connection accepted from %s:%d---##\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // Read data from client
    int valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
    printf("---> Received: %s\n", buffer);

    // Send response to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent --->\n");

    closesocket(server_fd);
    WSACleanup();
    return 0;
}
