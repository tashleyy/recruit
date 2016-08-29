CC = g++
CPP_FLAGS = -std=c++11 -Wall
BIN_DIR = bin
SRC_DIR = src
LIB_DIR = lib
DS_DIR = ds
SORT_DIR = sort
DS_CPP_FILES = $(wildcard $(SRC_DIR)/$(DS_DIR)/*.cpp)
DS_H_FILES = $(wildcard $(LIB_DIR)/$(DS_DIR)/*.h)
SORT_CPP_FILES = $(wildcard $(SRC_DIR)/$(SORT_DIR)/*.cpp)
SORT_H_FILES = $(wildcard $(LIB_DIR)/$(SORT_DIR)/*.h)

all: datastructures sorts

datastructures: $(BIN_DIR)/datastructures

sorts: $(BIN_DIR)/sorts

$(BIN_DIR)/datastructures: $(DS_CPP_FILES) $(DS_H_FILES) $(BIN_DIR)/.dirstamp
	$(CC) src/datastructures.cpp -o $@ $(CPP_FLAGS)

$(BIN_DIR)/sorts: $(SORT_CPP_FILES) $(SORT_H_FILES) $(BIN_DIR)/.dirstamp
	$(CC) src/sorts.cpp -o $@ $(CPP_FLAGS)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)