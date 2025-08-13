CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRCDIR = support
BUILDDIR = build
SOURCES = main.c $(SRCDIR)/game.c $(SRCDIR)/board.c $(SRCDIR)/GameAI.c
TARGET = $(BUILDDIR)/tictacx

$(TARGET): $(SOURCES) | $(BUILDDIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
