OS := $(shell uname)

CC = gcc
CFLAGS = -Wall -Wextra
SOURCE = trimmy.c

ifeq ($(OS), Linux)
	TARGET = trimmy
else
	TARGET = trimmy.exe
endif

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)

all: $(TARGET)
