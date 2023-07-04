clean:
	if [ -d bin ]; then rm bin/*; rmdir bin; fi

install:
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ src/main/*.cpp -o bin/Terminal `pkg-config --cflags --libs gtkmm-4.0` --std=c++20

tests:
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ src/test/TestSplit.cpp src/main/StringUtils.cpp -I src/main -o bin/TestSplit