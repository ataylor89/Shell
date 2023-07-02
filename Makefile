clean:
	if [ -f bin/Shell ]; then rm bin/Shell; fi;
	if [ -d bin ]; then rmdir bin; fi

install:
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ src/*.cpp -o bin/Shell `pkg-config --cflags --libs gtkmm-4.0` --std=c++17
