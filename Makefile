CPP_FILES = src/Main.cpp src/Shell.cpp src/TextArea.cpp src/Window.cpp
HEADER_FILES = src/Shell.h src/TextArea.h src/Window.h

install: $(CPP_FILES) $(HEADER_FILES)
	g++ $(CPP_FILES) -o Shell `pkg-config --cflags --libs gtkmm-4.0` --std=c++17

clean:
	if [ -f "Shell" ]; then rm Shell; fi