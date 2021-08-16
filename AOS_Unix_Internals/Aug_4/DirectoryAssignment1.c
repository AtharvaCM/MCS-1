// printing file of a specified directory
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    while ((c = getc(stdin)) != EOF)
    {
        putc(c, stdout);
    }
    return 0;
}