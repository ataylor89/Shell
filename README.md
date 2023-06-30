# Shell

## Installing dependencies

This project depends on the gtkmm4 library. I was able to install this dependency with the command

    brew install gtkmm4

## Building the project

I wrote a Makefile to automate the build process. After installing the gtkmm4 dependency, the project can be built with the command

    make install

This tells g++ to compile all of the source files, and link the object files into a binary named "Shell".

## Running the application

The Shell program can be run with the command

    ./Shell

The ./ prefix is Unix syntax for running an executable. This syntax is used on Unix, Linux, and MacOS.