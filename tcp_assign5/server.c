#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int server_fd, client_socket;

    struct sockaddr_in server_addr;

    char buffer[100];

    int client_no = 1;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd,
         (struct sockaddr*)&server_addr,
         sizeof(server_addr));

    listen(server_fd, 5);

    printf("Server Waiting...\n");

    while(1)
    {
        client_socket = accept(server_fd,
                               NULL,
                               NULL);

        if(fork() == 0)
        {
            recv(client_socket,
                 buffer,
                 sizeof(buffer),
                 0);

            printf("Client %d: %s\n",
                   client_no,
                   buffer);

            close(client_socket);

            return 0;
        }

        client_no++;
    }

    close(server_fd);

    return 0;
}
