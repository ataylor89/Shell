# Shell

## Installing dependencies

This project depends on the gtkmm4 library. I was able to install this dependency with the command

    brew install gtkmm4

## Building the project

I wrote a Makefile to automate the build process. After installing the gtkmm4 dependency, the project can be built with the command

    make install

This tells g++ to compile all of the source files, and link the object files into a binary named "Shell".

As an alternative, the project can be built with the command

    make clean install

This runs the "clean" rule before running the "install" rule.

It is also possible to compile the source files with the clang++ compiler, by editing the Makefile and substituting clang++ for g++. I have tested the build process with both the g++ and clang++ compilers.

## Running the application

The Shell program can be run with the command

    bin/Shell

It can also be run with the commands

    cd bin
    ./Shell

The ./ prefix is Unix syntax for running an executable. This syntax is used on Unix, Linux, and MacOS.