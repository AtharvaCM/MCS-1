#include <stdio.h>
#include <unistd.h> // for fork(),exclp()
#include <fcntl.h>  // O_RDONLY
#include <stdlib.h> //exit()
#include <string.h>
void count(char c, char *fn)
{
    int line_count = 0, word_count = 0, char_count = 0, handle;
    char ch;
    if ((handle = open(fn, O_RDONLY)) == -1)
    {
        printf("File %s not found\n", fn);
        return;
    }
    while (read(handle, &ch, 1) != 0)
    {
        if (ch == ' ' || ch == '\n')
            word_count++;
        else
            char_count++;

        if (ch == '\n')
            line_count++;
    }
    close(handle);
    switch (c)
    {
    case 'c':
        printf("Total No.of Characters = %d\n", char_count);
        break;
    case 'w':
        printf("Total No.of Words = %d\n", word_count);
        break;
    case 'l':
        printf("Total No.of Lines = %d\n", line_count);
        break;
    }
}

int main()
{
    char command[80], t1[20], t2[20], t3[20], t4[20];
    int n;
    system("clear");
    while (1)
    {
        printf("\nmodernShell$ ");
        fflush(stdin);
        fgets(command, 80, stdin);
        n = sscanf(command, "%s %s %s %s", t1, t2, t3, t4);
        switch (n)
        {
        case 1:
            if (strcmp(t1, "exit") == 0)
                exit(1);
            if (!fork())
            {
                execlp(t1, t1, NULL);
                perror(t1);
            }
            break;
        case 2:
            if (!fork())
            {
                execlp(t1, t1, t2, NULL);
                perror(t1);
            }
            break;
        case 3:
            if (strcmp(t1, "count") == 0)
                count(t2[0], t3);
            else
            {
                if (!fork())
                {
                    execlp(t1, t1, t2, t3, NULL);
                    perror(t1);
                }
            }
            break;
        case 4:
            if (!fork())
            {
                execlp(t1, t1, t2, t3, t4, NULL);
                perror(t1);
            }
        }
    }
    return 0;
}