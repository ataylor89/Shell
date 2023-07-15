#include "Util.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 0;
    }

    std::string input(argv[1]);

    cout << "User input: " << input << endl;

    trim(input);

    cout << "After trim: " << input << endl;
    
    return 0;
}