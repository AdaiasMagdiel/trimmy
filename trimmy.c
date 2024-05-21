#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

FILE* openFile(char filepath[]);
int isWhitespace(char c);
int verifyFile(char filepath[]);
int noMoreChar(int start, char line[]);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ctrimmy [file].\n");
        exit(1);
    }

    int contains = verifyFile(argv[1]);
    if (contains) printf("\n\n");

    return 0;
}

int noMoreChar(int start, char line[]) {
    int len = strlen(line);
    int verify = 1;

    for (int i=start; i<len; i++) {
        if (!isWhitespace(line[i])) {
            verify = 0;
            break;
        }   
    }

    return verify;
}

int verifyFile(char filepath[]) {
    FILE* fp = openFile(filepath);

    char line[MAX_LINE_LENGTH];
    char lineSeg[MAX_LINE_LENGTH];

    int lineNum = 1;
    int lineContains = 0;
    int printFile = 0;
    int fileContains = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = strlen(line);
        int lineContainsChar = 0;
        int linePos = 0;

        for (int i=0; i<len; i++) {
            char c = line[i];
            char nextC = line[i+1];

            if (c == '\n') continue;
            if (!isWhitespace(c)) lineContainsChar = 1;

            if (lineContainsChar && isWhitespace(c) && isWhitespace(nextC) && noMoreChar(i, line)) {
                strcpy(&lineSeg[linePos], "\x1b[32m•\x1b[0m");
                linePos += strlen("\x1b[32m•\x1b[0m");

                lineContains = 1;
                fileContains = 1;
            } else {
                lineSeg[linePos++] = c;
            }
        }

        lineSeg[linePos] = '\0';

        if (lineContains) {
            if (!printFile) {
                printf("\x1b[37mFILE:\x1b[0m \x1b[33m%s\x1b[0m\n\n", filepath);
                printFile = 1;
            }
            printf("\x1b[37m%d\x1b[0m | %s\n", lineNum, lineSeg);
        }

        lineNum++;
        lineContains = 0;
    }

    fclose(fp);
    return fileContains;
}

FILE* openFile(char filepath[]) {
    FILE* fp = fopen(filepath, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    return fp;
}

int isWhitespace(char c) {
    return (c == ' '  ||
            c == '\r' ||
            c == '\t' ||
            c == '\f' ||
            c == '\v' ||
            c == '\n' );
}