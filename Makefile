# .PHONY := clean
# CXXFLAGS := -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++17 -Wall -Wextra -pedantic
# CXX := clang++

# UNAME_S := $(shell uname -s)

# TARGET_EXEC ?= a.out

# BUILD_DIR ?= ./build
# SRC_DIRS ?= ./src

# SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
# OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
# DEPS := $(OBJS:.o=.d)

# ifeq ($(UNAME_S),Darwin)
#     CXX := clang++
#     LDFLAGS := -Wl,-dead_strip
#     CXXFLAGS := -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++17 -Weverything -Wno-c++98-compat -Wno-padded
# else ifeq ($(UNAME_S),Linux)
#     LDFLAGS := -Wl,-gc-sections
# else ifeq ($(OS),Windows_NT)
#     LDFLAGS :=
# else
#     LDFLAGS :=
# endif

# OBJECTS := main.o board.o stone.o position.o player.o game.o board_displayer.o player_creator.o human_player.o ai_player.o game_io.o

# all: main

# main: $(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
# 	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# # # c++ source
# # $(BUILD_DIR)/%.cpp.o: %.cpp
# # 	$(MKDIR_P) $(dir $@)
# # 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# # main: $(OBJECTS)
# # 	$(CXX) $(LDFLAGS) -o $@ $^

# clean:
# 	@rm -f main $(OBJECTS) partial1.o partial2.o > /dev/null 2>&1

TARGET ?= AtariGo.exe
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS ?= ./inc
INC_DIRS := $(shell find $(INC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CXX := clang++
CXXFLAGS := $(INC_FLAGS) -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++17 -Wall -Wextra -pedantic

$(TARGET): $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJS) -o $@ 

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
