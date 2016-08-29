CC = g++
CPP_FLAGS = -std=c++11 -Wall
BIN_DIR = bin
SRC_DIR = src
LIB_DIR = lib
CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)
H_FILES = $(wildcard $(LIB_DIR)/*.h)

all: $(BIN_DIR)/datastructures

datastructures: $(BIN_DIR)/datastructures

$(BIN_DIR)/datastructures: $(CPP_FILES) $(H_FILES) $(BIN_DIR)/.dirstamp
	$(CC) src/datastructures.cpp -o $@ $(CPP_FLAGS)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)