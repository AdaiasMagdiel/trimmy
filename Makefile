OS := $(shell uname)

CC = gcc
CFLAGS = -Wall -Wextra -I./src
SOURCE = trimmy.c
FILES = src/file_processor.c src/utilities.c

ifeq ($(OS), Linux)
	TARGET = trimmy
else
	TARGET = trimmy.exe
endif

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(FILES)

clean:
	rm -f $(TARGET)

all: $(TARGET)
