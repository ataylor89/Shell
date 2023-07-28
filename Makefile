clean:
	if [ -d bin ]; then rm bin/*; rmdir bin; fi;
	if [ -d tests ]; then rm tests/*; rmdir tests; fi;

shell_software: clean
	mkdir bin
	gcc src/main/c/ls/*.c -o bin/ls
	gcc src/main/c/cat/*.c -o bin/cat
	gcc src/main/c/hexdump/*.c -o bin/hexdump

tests: shell_software
	mkdir tests
	g++ src/test/cpp/Split.cpp src/main/cpp/util/StringUtils.cpp -I src/main/cpp -o tests/Split
	g++ src/test/cpp/Trim.cpp src/main/cpp/util/StringUtils.cpp -I src/main/cpp -o tests/Trim

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
