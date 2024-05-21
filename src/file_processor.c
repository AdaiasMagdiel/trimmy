#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_processor.h"
#include "utilities.h"

FILE* openFile(const char* filepath) {
    FILE* fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'.\n", filepath);
        exit(1);
    }
    return fp;
}

int processFile(const char* filepath) {
    FILE* fp = openFile(filepath);

    char line[MAX_LINE_LENGTH];
    char formattedLine[MAX_LINE_LENGTH];

    int lineNumber = 1;
    int lineContainsWhitespace = 0;
    int fileContainsWhitespace = 0;
    int shouldPrintFileHeader = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = strlen(line);
        int lineContainsNonWhitespace = 0;
        int formattedLinePos = 0;

        for (int i = 0; i < len; i++) {
            char c = line[i];
            char nextC = line[i + 1];

            if (c == '\n') continue;
            if (!isWhitespace(c)) lineContainsNonWhitespace = 1;

            if (lineContainsNonWhitespace &&
                isWhitespace(c) &&
                isWhitespace(nextC) &&
                checkRemainingWhitespace(i, line)) {
                strcpy(&formattedLine[formattedLinePos], "\x1b[32m•\x1b[0m");
                formattedLinePos += strlen("\x1b[32m•\x1b[0m");
                
                lineContainsWhitespace = 1;
                fileContainsWhitespace = 1;
            } else {
                formattedLine[formattedLinePos++] = c;
            }
        }

        formattedLine[formattedLinePos] = '\0';

        if (lineContainsWhitespace) {
            if (!shouldPrintFileHeader) {
                printf("\x1b[37mFILE:\x1b[0m \x1b[33m%s\x1b[0m\n\n", filepath);
                shouldPrintFileHeader = 1;
            }
            printf("\x1b[37m%d\x1b[0m | %s\n", lineNumber, formattedLine);
        }

        lineNumber++;
        lineContainsWhitespace = 0;
    }

    fclose(fp);
    return fileContainsWhitespace;
}
