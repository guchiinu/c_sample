#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file();

typedef unsigned int utf8;

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
    int k;
    utf8 utf8_text[100];
    int text_count;

    fp = fopen("resource/sample.txt","r");
    if (fp == NULL)
    {
        printf("file not found.\n");
        return ;
    }
    size = fread(text, 1, 100, fp);
    text[size] = '\0';

    printf("%s\n", text);

    // 初期化
    memset(utf8_text, 0, sizeof(utf8_text));
    text_count = 0;

    // 文字毎に分解し、文字数をカウントする
    for ( i = 0, j = 0; i < size; j++)
    {
        // 1バイト
        if ( (char)0x00 <= text[i] && text[i] <= (char)0x7F )
        {
            utf8_text[j] = 0xFF & text[i];
            i+=1;
        }
        // 2バイト
        else if ( (char)0xC0 <= text[i] && text[i] <= (char)0xDF )
        {
            utf8_text[j] = 0xFF & text[i];
            utf8_text[j] <<= 8;
            utf8_text[j] += 0xFF & text[i+1];
            i+=2;
        }
        // 3バイト
        else if ( (char)0xE0 <= text[i] && text[i] <= (char)0xEF )
        {
	        utf8_text[j] = 0xFF & text[i];
            utf8_text[j] <<= 8;
            utf8_text[j] += 0xFF & text[i+1];
            utf8_text[j] <<= 8;
            utf8_text[j] += 0xFF & text[i+2];
            i+=3;
        }
        // 4バイト
        else if ( (char)0xF0 <= text[i] && text[i] <= (char)0xF7 )
        {
            utf8_text[j] = 0xFF & text[i];
            utf8_text[j] <<= 8;
            utf8_text[j] += 0xFF & text[i+1];
            utf8_text[j] <<= 8;
            utf8_text[j] += 0xFF & text[i+2];
            utf8_text[j] <<= 8;
            utf8_text[j] += 0xFF & text[i+3];
            i+=4;
        }
        text_count++;
    }


    for ( i = text_count - 1, j = 0; 0 <= i; i-- )
    {
        for ( k = 0; k < 4; k++ )
        {
            if ( 0 != (0xFF000000 & utf8_text[i]) )
            {
                rev_text[j] = (utf8_text[i] >> 8 * 7);
                utf8_text[i] <<= 8;
                j++;
            }
            else
            {
                utf8_text[i] <<= 8;
            }
            
        }
        
    }

    rev_text[size] = '\0';

    printf("%s\n", rev_text);

    return ;
}
