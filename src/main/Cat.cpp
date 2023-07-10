#include "Cat.h"
#include "StringUtils.h"
#include <cstdio>
#include <cstdlib>

#define PARTITION_LENGTH 4096

Cat::Cat(std::string& cmd, Window* window) : Command(cmd, window)
{
    text_view = window->get_text_view();
}

void Cat::exec(const char* filename)
{
    FILE* file;
    int offset, filesize, n;
    char *buffer;

    if ((file = fopen(filename, "r")) == NULL)
    {
        text_view->append("Error opening file");
        return;
    }

    offset = 0;

    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char *) malloc(PARTITION_LENGTH);

    while (offset < filesize)
    {
        n = (filesize - offset) < PARTITION_LENGTH ? filesize - offset : PARTITION_LENGTH;
         
        if (fread(buffer, 1, n, file) != n)
        {
            text_view->append("Error reading from file");
            return;
        }

        text_view->append(buffer, n);

        offset += n;
    }

    fclose(file);
    free(buffer);
}

void Cat::exec()
{
    std::vector<std::string> args;

    args = split(cmd, " ");
    text_view->append("\n");

    if (args.size() == 2)
    {
        exec(args[1].c_str());
    }

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