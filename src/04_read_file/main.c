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

    for (i = size - 3, j = 0; i >= 0; )
    {
	printf("%x\n", text[i]);
	if ( 0xFFFFFF00 <= text[i] && text[i] <= 0xFFFFFF7F )
	{
		printf("1バイト\n");
		i-=1;
		j+=1;
	}
	else if ( 0xFFFFFFC0 <= text[i] && text[i] <= 0xFFFFFFDF )
        {
                printf("2バイト\n");
		i-=2;
		j+=2;
        }
	else if ( 0xFFFFFFE0 <= text[i] && text[i] <= 0xFFFFFFFFEF )
        {
                printf("3バイト\n");
		i-=3;
		j+=3;
        }
	else
	{
		printf("?バイト\n");
		// とりあえず１バイト進める
		i-=1;
		j+=1;
	}

        rev_text[j] = text[i];
        rev_text[j+1] = text[i+1];
	rev_text[j+2] = text[i+2];
    }
    rev_text[size] = '\0';

    printf("%s\n", rev_text);
    return ;
}
