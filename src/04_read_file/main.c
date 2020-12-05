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
    wchar_t text[100];
    size_t size;

    fp = fopen("resource/sample.txt","r");
    if (fp == NULL)
    {
        printf("file not found.\n");
        return ;
    }
    size = fread(text, sizeof(text), 100, fp);

    printf("%ls\n", text);

    return ;
}
