

BUILD_DIR := ./build
SRC_DIR   := ./src


.PHONY: all clean


all: $(BUILD_DIR)/fizzbuzz




$(BUILD_DIR)/fizzbuzz: $(BUILD_DIR)/fizzbuzz.o
	gcc $(BUILD_DIR)/fizzbuzz.o -o $(BUILD_DIR)/fizzbuzz


$(BUILD_DIR)/fizzbuzz.o: $(SRC_DIR)/fizzbuzz.c
	mkdir -p build
	gcc -c $(SRC_DIR)/fizzbuzz.c -o $(BUILD_DIR)/fizzbuzz.o




clean:
	rm -rf build
