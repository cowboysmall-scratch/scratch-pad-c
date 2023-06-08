

BUILD_DIR := ./build
SRC_DIR   := ./src


.PHONY: all clean


all: $(BUILD_DIR)/client $(BUILD_DIR)/server




$(BUILD_DIR)/client: $(BUILD_DIR)/client.o
	gcc $(BUILD_DIR)/client.o -o $(BUILD_DIR)/client


$(BUILD_DIR)/client.o: $(SRC_DIR)/client.c
	mkdir -p build
	gcc -c $(SRC_DIR)/client.c -o $(BUILD_DIR)/client.o




$(BUILD_DIR)/server: $(BUILD_DIR)/server.o
	gcc $(BUILD_DIR)/server.o -o $(BUILD_DIR)/server


$(BUILD_DIR)/server.o: $(SRC_DIR)/server.c
	mkdir -p build
	gcc -c $(SRC_DIR)/server.c -o $(BUILD_DIR)/server.o




clean:
	rm -rf build
