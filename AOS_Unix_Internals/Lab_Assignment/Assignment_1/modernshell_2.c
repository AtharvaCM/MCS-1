#include <stdio.h>
#include <unistd.h> //execlp()
#include <fcntl.h>  //O_RDONLY
#include <stdlib.h> //exit()
#include <string.h>
#include <dirent.h>

void list(char op, char *dn)
{
    DIR *dirp;
    struct dirent *entry;
    int dc = 0, fc = 0;
    dirp = opendir(dn);
    if (dirp == NULL)
    {
        printf("Directory %s not found\n", dn);
        return;
    }
    switch (op)
    {
    case 'F':
    case 'f':
        while (entry = readdir(dirp))
        {
            printf("%s\n", entry->d_name);
        }
        break;
    case 'N':
    case 'n':
        while (entry = readdir(dirp))
        {
            if (entry->d_type == DT_REG)
                fc++;
            if (entry->d_type == DT_DIR)
                dc++;
        }
        printf("%d File(s)\t %d Dir(s)\n", fc, dc);
        break;
    case 'I':
    case 'i':
        while (entry = readdir(dirp))
        {
            printf("%s\t%lu\n", entry->d_name, entry->d_fileno);
        }
        break;
    default:
        printf("Invalid parameter!\n");
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
            if (strcmp(t1, "list") == 0)
                list(t2[0], t3);
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