#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, client_socket;

    struct sockaddr_in server_addr;

    char buffer[100];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Server details
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(server_fd,
         (struct sockaddr*)&server_addr,
         sizeof(server_addr));

    // Listen
    listen(server_fd, 5);

    printf("Waiting for client...\n");

    // Accept client
    client_socket = accept(server_fd, NULL, NULL);

    printf("Client Connected\n");

    while(1)
    {
        // Receive message
        recv(client_socket, buffer, sizeof(buffer), 0);

        printf("[Client]: %s", buffer);

        // Exit condition
        if(strncmp(buffer, "exit", 4) == 0)
        {
            break;
        }

        // Server reply
        printf("[Server]: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(client_socket, buffer, strlen(buffer), 0);

        // Exit condition
        if(strncmp(buffer, "exit", 4) == 0)
        {
            break;
        }
    }

    close(client_socket);
    close(server_fd);

    return 0;
}
