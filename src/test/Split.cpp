/*
 * To compile this file, run the following command in the root directory of the project (where the Makefile resides):
 *
 *      make tests
 * 
 * This command will make all of the tests, and write the binaries to a tests folder.
 * 
 * Now that the tests have been installed, let's try an example.
 * 
 *      tests/Split "Hello world, how are you? What is the weather like today?" ",? "
 * 
 * This will split the string on the delimiters "," and "?" and " ", and output an array of substrings.
 * 
 * We can try another example.
 * 
 *      tests/Split "Hello world, how are you? What is the weather like today?" ",? " 10
 * 
 * This will split the string a maximum of 9 times, and output an array that has a maximum size of 10.
 */

#include "StringUtils.h"
#include <iostream>

void run_test(string& str, const string& delimiters)
{
    cout << "==================================================================" << endl;
    cout << "User inputs:" << endl;
    cout << "==================================================================" << endl;
    cout << "String: " << "\"" + str + "\"" << endl;
    cout << "Delimiters: " << "\"" + delimiters + "\"" << endl;
    cout << "==================================================================" << endl;
    cout << "Testing the StringUtils::split(str, delimiters) function..." << endl;
    cout << "==================================================================" << endl;
    vector<string> buffer = StringUtils::split(str, delimiters);
    for (int i = 0; i < buffer.size(); i++)
    {
        cout << i << ": " << buffer[i] << endl;
    }
}

void run_test(string& str, const string& delimiters, int limit)
{
    cout << "==================================================================" << endl;
    cout << "User inputs:" << endl;
    cout << "==================================================================" << endl;
    cout << "String: " << "\"" + str + "\"" << endl;
    cout << "Delimiters: " << "\"" + delimiters + "\"" << endl;
    cout << "Limit: " << limit << endl;
    cout << "==================================================================" << endl;
    cout << "Testing the StringUtils::split(str, delimiters, limit) function..." << endl;
    cout << "==================================================================" << endl;
    vector<string> buffer = StringUtils::split(str, delimiters, limit);
    for (int i = 0; i < buffer.size(); i++)
    {
        cout << i << ": " << buffer[i] << endl;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
    {
        printf("Usage: %s <string> <delimiters> [<limit>]\n", argv[0]);
        return 0;
    }

    string str = string(argv[1]);
    const string delimiters = string(argv[2]);

    if (argc == 3)
    {
        run_test(str, delimiters);
    }
    else
    {
        int limit = atoi(argv[3]);
        run_test(str, delimiters, limit);
    }

    return 0;
}