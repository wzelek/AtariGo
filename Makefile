.PHONY := clean
CXXFLAGS := -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++17 -Wall -Wextra -pedantic
CXX := clang++

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CXX := clang++
    LDFLAGS := -Wl,-dead_strip
    CXXFLAGS := -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++17 -Weverything -Wno-c++98-compat -Wno-padded
else ifeq ($(UNAME_S),Linux)
    LDFLAGS := -Wl,-gc-sections
else ifeq ($(OS),Windows_NT)
    LDFLAGS :=
else
    LDFLAGS :=
endif

OBJECTS := main.o board.o stone.o position.o player.o game.o board_displayer.o player_creator.o human_player.o ai_player.o game_io.o

all: main

main: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) partial1.o partial2.o > /dev/null 2>&1
