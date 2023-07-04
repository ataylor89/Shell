clean:
	if [ -d bin ]; then rm bin/*; rmdir bin; fi

install:
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ src/*.cpp -o bin/Shell `pkg-config --cflags --libs gtkmm-4.0` --std=c++20
