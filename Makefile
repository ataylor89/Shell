clean:
	if [ -d bin ]; then rm bin/*; rmdir bin; fi;
	if [ -d tests ]; then rm tests/*; rmdir tests; fi;

shell_software: clean
	mkdir bin
	gcc src/main/c/ls.c -o bin/ls
	gcc src/main/c/cat.c -o bin/cat
	gcc src/main/c/hexdump.c -o bin/hexdump

tests: shell_software
	mkdir tests
	g++ src/test/Split.cpp src/main/Util.cpp -I src/main -o tests/Split
	g++ src/test/Trim.cpp src/main/Util.cpp -I src/main -o tests/Trim
	g++ src/test/Ls.cpp -o tests/Ls

terminal: shell_software
	g++ src/main/cpp/*.cpp \
		src/main/cpp/util/*.cpp \
		src/main/cpp/gui/*.cpp \
		src/main/cpp/parser/*.cpp \
		src/main/cpp/commands/*.cpp \
		-I src/main/cpp \
		-o bin/Terminal \
		`pkg-config --cflags --libs gtkmm-4.0` \
		--std=c++20