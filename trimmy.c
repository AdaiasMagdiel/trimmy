#include <stdio.h>
#include <stdlib.h>
#include "src/file_processor.h"

void printUsage() {
    printf("Usage: trimmy [file...]\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printUsage();
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        int contains = processFile(argv[i]);
        if (contains) {
            printf("\n\n");
        }
    }

    return 0;
}