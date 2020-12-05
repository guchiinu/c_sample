#include <stdio.h>
#include <stdlib.h>

void read_file();

int main()
{
    read_file();

    return 0;
}

void read_file()
{
    FILE *fp;
    char text[100];
    char rev_text[100];
    size_t size;

    fp = fopen("resource/sample.txt","r");
    if (fp == NULL)
    {
        printf("file not found.\n");
        return ;
    }
    size = fread(text, 1, 100, fp);
    text[size] = '\0';

    printf("size: %d\n", size);
    printf("%s\n", text);

    return ;
}
