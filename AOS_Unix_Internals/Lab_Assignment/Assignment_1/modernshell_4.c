#include <stdio.h>
#include <unistd.h> //execlp()
#include <fcntl.h>  //O_RDONLY
#include <stdlib.h> //exit()
#include <string.h> //strstr()
void search(char c, char *s, char *filename)
{
    int handle, i = 1, count = 0, j = 0;
    char ch, buff[80], *p;
    if ((handle = open(filename, O_RDONLY)) == -1)
    {
        printf("\nFile %s not found\n", filename);
        return;
    }
    switch (c)
    {
    case 'f':
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                if (strstr(buff, s) != NULL)
                {
                    printf("%d : %s\n", i, buff);
                    break;
                }
                i++;
            }
            else
                buff[j++] = ch;
        }
        break;
    case 'c':
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                if (strstr(buff, s) != NULL)
                {
                    p = buff;
                    while ((p = strstr(p, s)) != NULL)
                    {
                        count++;
                        p++;
                    }
                }
            }
            else
                buff[j++] = ch;
        }
        printf("Total No. of Occurrences = %d\n", count);
        break;
    case 'a':
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
            {
                buff[j] = '\0';
                j = 0;
                if (strstr(buff, s) != NULL)
                    printf("%d : %s\n", i, buff);
                i++;
            }
            else
                buff[j++] = ch;
        }
    }
    close(handle);
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
            if (!fork())
            {
                execlp(t1, t1, t2, t3, NULL);
                perror(t1);
            }
            break;
        case 4:
            if (strcmp(t1, "search") == 0)
                search(t2[0], t3, t4);
            else
            {
                if (!fork())
                {
                    execlp(t1, t1, t2, t3, t4, NULL);
                    perror(t1);
                }
            }
        }
    }
    return 0;
}