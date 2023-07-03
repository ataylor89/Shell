/*
 * To compile this file, enter the following command in the root directory of the project 
 * (where the Makefile and Readme files both reside):
 * 
 *      g++ test/TestSplit.cpp src/StringUtils.cpp -I src -o test/TestSplit
 * 
 * This should create the binary TestSplit in the test folder.
 * 
 * The binary can be run with a command of the form
 * 
 *      test/TestSplit "<string>" "<delimiters>" <limit>
 * 
 * where <string> and <delimiters> are both strings enclosed in double quotes, and <limit> is an integer.
 * 
 * For example,
 * 
 *      test/TestSplit "Hello world, hello solar system, hello Milky Way, hello universe." ",. " 10
 * 
 * This will split the string on the three delimiters ',' and '.' and ' ', a maximum of 9 times,
 * resulting in a vector that has a maximum size of 10.
 * 
 * The contents of the vector are printed at the end of each test.
 */

#include "StringUtils.h"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Usage: %s \"<string>\" \"<delimiters>\" <limit>\n", argv[0]);
        return 0;
    }   

    string str = string(argv[1]);
    const string delimiters = string(argv[2]);
    int limit = atoi(argv[3]);

    cout << "==================================================================" << endl;
    cout << "User inputs" << endl;
    cout << "==================================================================" << endl;

    cout << "String: " << "\"" + str + "\"" << endl;
    cout << "Delimiters: " << "\"" + delimiters + "\"" << endl;
    cout << "Limit: " << limit << endl;

    vector<string> buffer;

    cout << "==================================================================" << endl;
    cout << "Testing the StringUtils::split(str, delimiters) function..." << endl;
    cout << "==================================================================" << endl;

    buffer = StringUtils::split(str, delimiters);

    for (int i = 0; i < buffer.size(); i++)
    {
        cout << i << ": " << buffer[i] << endl;
    }

    cout << "==================================================================" << endl;
    cout << "Testing the StringUtils::split(str, delimiters, limit) function..." << endl;
    cout << "==================================================================" << endl;

    buffer = StringUtils::split(str, delimiters, limit);

    for (int i = 0; i < buffer.size(); i++)
    {
        cout << i << ": " << buffer[i] << endl;
    }

    return 0;
}