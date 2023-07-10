#include "Hexdump.h"
#include "StringUtils.h"
#include <cstdio>
#include <cstdlib>

#define PARTITION_LENGTH 512

Hexdump::Hexdump(std::string& cmd, Window* window) : Command(cmd, window)
{
    text_view = window->get_text_view();
}

void Hexdump::_exec(const char* filename)
{
    HEXDUMP* dump;
    FILE* file;
    int offset, filesize, n;
    char *buffer;

    if ((file = fopen(filename, "r")) == NULL)
    {
        text_view->append("Error opening file.");
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
            text_view->append("Error reading from file.");
            return;
        }

        dump = hexdump(buffer, n, offset);
        string str(dump->buffer, dump->size);

        text_view->append(str);

        offset += n;

        if (offset < filesize)
        {
            text_view->append("\n*\n");
        }
    }

    fclose(file);
    free(dump);
    free(buffer);
}

void Hexdump::exec()
{
    std::vector<std::string> args;

    args = split(cmd, " ", 2);
    text_view->append("\n");

    if (args.size() == 2)
    {
        _exec(args[1].c_str());
    }

    auto buffer = text_view->get_buffer();
    auto cursor = buffer->get_insert();
    auto iter = buffer->get_iter_at_mark(cursor);

    if (iter.get_char() != '\n')
    {
        text_view->append("\n");
    }

    text_view->append_prefix();
}