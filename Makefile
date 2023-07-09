clean:
	if [ -d bin ]; then rm bin/*; rmdir bin; fi;
	if [ -d tests ]; then rm tests/*; rmdir tests; fi

install:
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ src/main/*.cpp -o bin/Terminal `pkg-config --cflags --libs gtkmm-4.0` --std=c++20

tests:
	if [ ! -d tests ]; then mkdir tests; fi;
	g++ src/test/Hexdump.cpp src/main/Hexdump.cpp -I src/main -o tests/Hexdump
	g++ src/test/Split.cpp src/main/StringUtils.cpp src/main/Hexdump.cpp -I src/main -o tests/Split
	g++ src/test/Trim.cpp src/main/StringUtils.cpp src/main/Hexdump.cpp -I src/main -o tests/Trim
	g++ src/test/Echo.cpp src/main/Hexdump.cpp -I src/main -o tests/Echo
	g++ src/test/Tee.cpp src/main/Hexdump.cpp -I src/main -o tests/Tee