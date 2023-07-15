clean:
	if [ -d bin ]; then rm bin/*; rmdir bin; fi;
	if [ -d tests ]; then rm tests/*; rmdir tests; fi

tests:
	if [ ! -d tests ]; then mkdir tests; fi;
	g++ src/test/Split.cpp src/main/Util.cpp -I src/main -o tests/Split
	g++ src/test/Trim.cpp src/main/Util.cpp -I src/main -o tests/Trim
	g++ src/test/Echo.cpp src/main/Util.cpp -I src/main -o tests/Echo
	g++ src/test/Tee.cpp src/main/Util.cpp -I src/main -o tests/Tee

install:
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ src/main/*.cpp \
		src/main/gui/*.cpp \
		src/main/parser/*.cpp \
		src/main/commands/*.cpp \
		-I src/main \
		-I src/main/gui \
		-I src/main/parser \
		-I src/main/commands \
		-o bin/Terminal \
		`pkg-config --cflags --libs gtkmm-4.0` \
		--std=c++20