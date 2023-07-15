#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char** argv)
{
    char buffer[128];
    pid_t pid;
    size_t n;
    int fds[2];
    
    pipe(fds);
    pid = fork();

    if (pid == 0)
    {
        close(fds[0]);
        dup2(fds[1], STDOUT_FILENO);
        close(fds[1]);
        execvp("echo", argv);
        return 1;
    }

    memset(buffer, 0, 128);
    n = read(fds[0], buffer, 128);

    fwrite(buffer, 1, strlen(buffer), stdout);

    return 0;
}