#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server_addr;

    char buffer[100] = "Networking Lab";

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET,
              "127.0.0.1",
              &server_addr.sin_addr);

    sendto(sockfd,
           buffer,
           strlen(buffer),
           0,
           (struct sockaddr*)&server_addr,
           sizeof(server_addr));

    printf("Sent: %s\n", buffer);

    recvfrom(sockfd,
             buffer,
             sizeof(buffer),
             0,
             NULL,
             NULL);

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}
