#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;

    struct sockaddr_in server_addr;

    char buffer[1024];

    FILE *fp;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET,
              "127.0.0.1",
              &server_addr.sin_addr);

    connect(sock,
            (struct sockaddr*)&server_addr,
            sizeof(server_addr));

    fp = fopen("sample.txt", "r");

    int bytes;

    while((bytes = fread(buffer,
                          1,
                          sizeof(buffer),
                          fp)) > 0)
    {
        send(sock,
             buffer,
             bytes,
             0);
    }

    printf("File Transfer Successful\n");

    fclose(fp);

    close(sock);

    return 0;
}
