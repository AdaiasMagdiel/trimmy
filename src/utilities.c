#include "utilities.h"
#include <string.h>

int isWhitespace(char c) {
    return (c == ' '  ||
            c == '\r' ||
            c == '\t' ||
            c == '\f' ||
            c == '\v' ||
            c == '\n' );
}

int checkRemainingWhitespace(int start, const char* line) {
    int len = strlen(line);

    for (int i = start; i < len; i++) {
        if (!isWhitespace(line[i])) {
            return 0;
        }
    }
    
    return 1;
}
