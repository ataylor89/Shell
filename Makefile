clean:
	if [ -d bin ]; then rm bin/*; rmdir bin; fi

install:
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ src/main/*.cpp -o bin/Terminal `pkg-config --cflags --libs gtkmm-4.0` --std=c++20
