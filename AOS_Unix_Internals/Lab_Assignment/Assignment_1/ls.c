#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int pid = fork();
    int fd = creat("output.txt", S_IRWXU);
    if (pid != 0 && pid != -1)
    {
        close(1); // stdout
        dup(fd);  // replace file descriptor
        execlp("ls", "ls", "-l", NULL);
        close(fd);
    }

    return 0;
}