

BUILD_DIR := ./build
SRC_DIR   := ./src

SRCS      := $(shell find $(SRC_DIR) -name '*.c')
OBJS      := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)



.PHONY: all clean



all: $(BUILD_DIR)/reverse



$(BUILD_DIR)/reverse: $(OBJS)
	gcc $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	gcc -c $< -o $@



clean:
	rm -rf build
