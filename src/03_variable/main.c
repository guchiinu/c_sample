#include <stdio.h>

void variable(void);

int main(void)
{
    variable();
    return 0;
}

void variable(void)
{
    int a;
    int b;

    a = 1;
    b = 2;

    a = a + b;

    printf("%d\n", a);

    return ;
}