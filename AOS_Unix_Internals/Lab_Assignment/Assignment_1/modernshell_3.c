#include <stdio.h>
#include <unistd.h> //execlp()
#include <fcntl.h>  //O_RDONLY
#include <stdlib.h> //exit()
#include <string.h>

void typeline(char *s, char *filename)
{
    int handle, i = 0, count = 0, n;
    char ch;

    if ((handle = open(filename, O_RDONLY)) == -1)
    {
        printf("File %s not found\n", filename);
        return;
    }

    // if a argument is passed
    if (strcmp(s, "a") == 0)
    {
        while (read(handle, &ch, 1) != 0)
            printf("%c", ch);
        close(handle);
        return;
    }

    // convert the number passed from str to int
    n = atoi(s);
    // print first n lines
    if (n > 0)
    {
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
                i++;
            if (i == n)
                break;
            printf("%c", ch);
        }
        printf("\n");
        close(handle);
        return;
    }
    // print last n lines
    if (n < 0)
    {
        // count number of lines
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
                count++;
        }
        lseek(handle, 0, SEEK_SET); // lseek moves the read/write pointer
        // set the control to correct position
        while (read(handle, &ch, 1) != 0)
        {
            if (ch == '\n')
                i++;
            if (i == count + n + 1)
                break;
        }
        // print the lines
        while (read(handle, &ch, 1) != 0)
            printf("%c", ch);
        printf("\n");
        close(handle);
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
            if (strcmp(t1, "typeline") == 0)
                typeline(t2, t3);
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