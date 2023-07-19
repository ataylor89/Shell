#include "Util.h"
#include "commands/UserProgram.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UserProgram::UserProgram(std::string& user_input, Window* window) 
: Command(user_input, window)
{
    text_view = window->get_text_view();
    settings = window->get_settings();
}

void UserProgram::exec()
{
    string path;
    std::vector<std::string> args;
    int count;

    args = split(user_input, " ");
    preprocess(args);

    path = settings->get_program_directory() + "/" + args[0];
    count = args.size();

    char* argv[count + 1];

    for (int i = 0; i < count; i++)
    {
        argv[i] = strdup(args[i].c_str());
    }

    argv[count] = NULL;

    text_view->append("\n");

    exec(path.c_str(), argv);

    auto buffer = text_view->get_buffer();
    auto cursor = buffer->get_insert();
    auto iter = buffer->get_iter_at_mark(cursor);
    iter.backward_char();

    if (iter.get_char() != '\n')
    {
        text_view->append("\n");
    }

    text_view->append_prefix();
}

void UserProgram::exec(const char* path, char** argv)
{
    int fds[2];

    pipe(fds);

    if (fork() == 0)
    {
        dup2(fds[1], fileno(stdout));
        close(fds[0]);
        execv(path, argv);
    }

    close(fds[1]);

    char program_output[256];
    int length;

    while (true)
    {
        length = read(fds[0], program_output, 256);

        if (program_output[length - 1] == EOF)
        {
            text_view->append(program_output, length - 2);
            break;
        }

        else
        {
            text_view->append(program_output, length);
        }
    }
}