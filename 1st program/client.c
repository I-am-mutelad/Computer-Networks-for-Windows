#include <stdio.h>
#include <winsock2.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int recv_size;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed: %d\n", WSAGetLastError());
        return 1;
    }

    // Prepare the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    // Connect
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Connection failed with error: %d\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    printf("\n\n##---Connected to server---##\n");

    // Send data to server
    char *message = "Hello from client--->";
    send(client_socket, message, strlen(message), 0);
    printf("Message sent to server--->\n");

    // Receive response from server
    recv_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (recv_size > 0) {
        buffer[recv_size] = '\0'; // Null-terminate the received data
        printf("---> Response from server: %s\n", buffer);
    } else if (recv_size == 0) {
        printf("\n\nConnection closed by server\n");
    } else {
        printf("Receive failed with error: %d\n", WSAGetLastError());
    }

    // Close socket and cleanup
    closesocket(client_socket);
    WSACleanup();

    return 0;
}
