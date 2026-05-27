#include <stdio.h>

void display_file(char filename[])
{
    FILE *fp;
    char ch;

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./mycat file.txt\n");
        return 1;
    }

    display_file(argv[1]);

    return 0;
}
