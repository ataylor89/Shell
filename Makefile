CPP_FILES = src/Main.cpp src/Shell.cpp src/TextArea.cpp src/Window.cpp
HEADER_FILES = src/Shell.h src/TextArea.h src/Window.h

clean:
	if [ -f bin/Shell ]; then rm bin/Shell; fi;
	if [ -d bin ]; then rmdir bin; fi

install: $(CPP_FILES) $(HEADER_FILES)
	if [ ! -d bin ]; then mkdir bin; fi;
	g++ $(CPP_FILES) -o bin/Shell `pkg-config --cflags --libs gtkmm-4.0` --std=c++17