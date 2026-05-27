#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, client_socket;

    struct sockaddr_in server_addr, client_addr;

    char buffer[100];

    socklen_t addr_len;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd,
         (struct sockaddr*)&server_addr,
         sizeof(server_addr));

    listen(server_fd, 5);

    printf("Waiting for client...\n");

    addr_len = sizeof(client_addr);

    client_socket = accept(server_fd,
                           (struct sockaddr*)&client_addr,
                           &addr_len);

    printf("Client Connected: %s\n",
           inet_ntoa(client_addr.sin_addr));

    recv(client_socket,
         buffer,
         sizeof(buffer),
         0);

    printf("Received: %s\n", buffer);

    send(client_socket,
         "Hello Client",
         strlen("Hello Client"),
         0);

    close(client_socket);
    close(server_fd);

    return 0;
}
