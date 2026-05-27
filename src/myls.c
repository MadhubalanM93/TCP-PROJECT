#include <stdio.h>
#include <dirent.h>

void list_files()
{
    DIR *d;
    struct dirent *dir;

    d = opendir(".");

    while((dir = readdir(d)) != NULL)
    {
        printf("%s\n", dir->d_name);
    }

    closedir(d);
}

int main()
{
    list_files();

    return 0;
}
