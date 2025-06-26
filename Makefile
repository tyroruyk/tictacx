CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BUILD_DIR = build
SUPPORT_DIR = support
TARGET = $(BUILD_DIR)/tictacx

$(TARGET): $(BUILD_DIR)/main.o $(BUILD_DIR)/board.o $(BUILD_DIR)/game.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/main.o: main.c $(SUPPORT_DIR)/board.h $(SUPPORT_DIR)/game.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/board.o: $(SUPPORT_DIR)/board.c $(SUPPORT_DIR)/board.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/game.o: $(SUPPORT_DIR)/game.c $(SUPPORT_DIR)/game.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/* 2>/dev/null || exit 0

.PHONY: clean
