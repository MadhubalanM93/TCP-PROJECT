#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;

    struct sockaddr_in server_addr;

    char buffer[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET,
              "127.0.0.1",
              &server_addr.sin_addr);

    connect(sock,
            (struct sockaddr*)&server_addr,
            sizeof(server_addr));

    printf("Connected to Server\n");

    while(1)
    {
        printf("[Client]: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(sock, buffer, strlen(buffer), 0);

        if(strncmp(buffer, "exit", 4) == 0)
        {
            break;
        }

        recv(sock, buffer, sizeof(buffer), 0);

        printf("[Server]: %s", buffer);

        if(strncmp(buffer, "exit", 4) == 0)
        {
            break;
        }
    }

    close(sock);

    return 0;
}
