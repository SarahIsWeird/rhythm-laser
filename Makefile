SRC = $(shell find src/ -name "*.cpp")

TARGET = game.exe

SFML_LIB = -L\"F:\\Programming\\SFML-2.5.1\\lib\"

SFML_DEBUG_LIBS = -lsfml-system-d -lsfml-window-d -lsfml-graphics-d-2
SFML_RELEASE_LIBS = -lsfml-system -lsfml-window -lsfml-graphics

COMPILER = g++

COMPILER_FLAGS = -std=c++17

.PHONY: clean

debug:
	$(COMPILER) -o $(TARGET) SFML_LIB SFML_DEBUG_LIBS

clean:
	rm game.exe