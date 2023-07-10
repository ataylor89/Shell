#include "StringUtils.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int pipe1[2], pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0)
    {
        dup2(pipe1[0], fileno(stdin));
        dup2(pipe2[1], fileno(stdout));
        close(pipe1[1]);
        close(pipe2[0]);
        execlp("tee", "tee", NULL);
        return 1;
    }

    char keyboard_input[128], program_output[128];

    close(pipe1[0]);
    close(pipe2[1]);

    while (true)
    {
        memset(keyboard_input, 0, 128);
        memset(program_output, 0, 128);

        fgets(keyboard_input, 128, stdin);

        if (strncmp(keyboard_input, "exit", 4) == 0)
        {
            break;
        }

        write(pipe1[1], keyboard_input, strlen(keyboard_input));
        read(pipe2[0], program_output, 128);
        
        print_hexdump(program_output, strlen(program_output));
        printf("\n");
    }
    
    return 0;
}