#include <stdio.h>

void copy_file(char src[], char dest[])
{
    FILE *fp1;
    FILE *fp2;

    char ch;

    fp1 = fopen(src, "r");

    if(fp1 == NULL)
    {
        printf("Source file not found\n");
        return;
    }

    fp2 = fopen(dest, "w");

    while((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("File copied successfully\n");
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: ./mycp a.txt b.txt\n");
        return 1;
    }

    copy_file(argv[1], argv[2]);

    return 0;
}
