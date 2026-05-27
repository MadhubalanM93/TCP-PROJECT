#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server_addr, client_addr;

    char buffer[100];

    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd,
         (struct sockaddr*)&server_addr,
         sizeof(server_addr));

    printf("UDP Server Waiting...\n");

    len = sizeof(client_addr);

    recvfrom(sockfd,
             buffer,
             sizeof(buffer),
             0,
             (struct sockaddr*)&client_addr,
             &len);

    printf("Received: %s\n", buffer);

    for(int i = 0; buffer[i] != '\0'; i++)
    {
        buffer[i] = toupper(buffer[i]);
    }

    sendto(sockfd,
           buffer,
           strlen(buffer),
           0,
           (struct sockaddr*)&client_addr,
           len);

    close(sockfd);

    return 0;
}
