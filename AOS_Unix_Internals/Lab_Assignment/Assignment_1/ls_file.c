#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    { //fail
        printf("\nFork failed\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        char filename[50];
        printf("\nEnter filename: ");
        scanf("%s", filename);                         //child
        execlp("/bin/ls", "ls", "-l", filename, NULL); //execute ls
    }
    else
    {               //parent
        wait(NULL); //wait for child
        printf("\nchild complete\n");
        exit(0);
    }

    return 0;
}