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
    int i;
    int j;

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

    for (i = size, j = 0; i >= 0; i--)
    {
        printf("%02x%02x%02x\n", 0xff & text[i], 0xff & text[i+1], 0xff & text[i+2]);
        if ( (char)0x00 <= text[i] && text[i] <= (char)0x7F )
        {
            printf("1バイト\n");
            rev_text[j] = text[i];
            i-=1;
            j+=1;
        }
        else if ( (char)0xC0 <= text[i] && text[i] <= (char)0xDF )
        {
            printf("2バイト\n");
            rev_text[j] = text[i];
            rev_text[j+1] = text[i+1];
            i-=2;
            j+=2;
        }
        else if ( (char)0xE0 <= text[i] && text[i] <= (char)0xEF )
        {
            printf("3バイト\n");
            rev_text[j] = text[i];
            rev_text[j+1] = text[i+1];
            rev_text[j+2] = text[i+2];
            i-=3;
            j+=3;
        }
	else if ( (char)0xF0 <= text[i] && text[i] <= (char)0xF7 )
	{
	    i-=4;
	    j+=4;
	}
	else if ( (char)0xF8 <= text[i] && text[i] <= (char)0xFB )
	{
	    i-=5;
	    j+=5;
	}
	else if ( (char)0xFC <= text[i] && text[i] <= (char)0xFD )
	{
	    i-=6;
	    j+=6;
	}
        else 
        {
            printf("?バイト\n");
	    i-=1;
	    j+=1;
        }
    }
    rev_text[size] = '\0';

    printf("%s\n", rev_text);
    return ;
}
