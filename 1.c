#include <stdio.h>
#include <unistd.h>

int main()
{
    int pipefd[2];
    int pid;
    float temp;
    float set_temp = 25.0;
    pipe(pipefd);     
    pid = fork();     

    if (pid == 0)   
    {
        close(pipefd[0]);  
        printf("Enter temperature value: ");
        scanf("%f", &temp);
        write(pipefd[1], &temp, sizeof(temp)); 
        close(pipefd[1]);
    }
    else
    {
        close(pipefd[1]);  
        read(pipefd[0], &temp, sizeof(temp)); 

        if (temp > set_temp)
            printf("Compressor Motor ON\n");
        else
            printf("Compressor Motor OFF\n");

        close(pipefd[0]);
    }
    return 0;
}
