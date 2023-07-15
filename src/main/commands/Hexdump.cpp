#include "Hexdump.h"
#include "Util.h"
#include <cstdio>
#include <cstdlib>

#define PARTITION_LENGTH 512

Hexdump::Hexdump(std::string& user_input, Window* window) : Command(user_input, window)
{
    text_view = window->get_text_view();
}

void Hexdump::exec()
{
    std::vector<std::string> args;

    args = split(user_input, " ");
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

void Hexdump::exec(const char* filename)
{
    Hexstring* dump;
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

        text_view->append(dump->buffer, dump->size);

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

Hexstring* Hexdump::hexdump(char* str, int size, int line_pos)
{
    Hexstring *dump;
    char *ptr;
    int i, j, num_spaces;

    dump = (Hexstring *) malloc(sizeof(Hexstring));
    dump->buffer = (char *) malloc(sizeof(char) * size * 10);
    ptr = dump->buffer;

    for (i = 0; i < size;)
    {
        sprintf(ptr, "%08x: ", line_pos);

        ptr += 10;

        for (j = 0; j < 16; j++)
        {
            if (i + j > size - 1)
            {
                num_spaces = (j % 2 == 1) ? 3 : 2;
                sprintf(ptr, "%*c", num_spaces, ' ');
                ptr += num_spaces;
            }
            else if (j % 2 == 1)
            {
                sprintf(ptr, "%02hhx ", str[i + j]);
                ptr += 3;
            }
            else
            {
                sprintf(ptr, "%02hhx", str[i + j]);
                ptr += 2;
            }
        }

        for (j = 0; j < 16 && i + j < size; j++)
        {
            char ch = isprint(str[i + j]) ? str[i + j] : '.';
            if (j == 15 && i + j < size - 1)
            {
                sprintf(ptr, "%c\n", ch);
                ptr += 2;
            }
            else
            {
                sprintf(ptr, "%c", ch);
                ptr++;
            }
        }

        i += j;
        line_pos += 16;
    }

    dump->size = ptr - dump->buffer;
    return dump;
}