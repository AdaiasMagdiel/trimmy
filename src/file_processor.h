#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#define MAX_LINE_LENGTH 1024

FILE* openFile(const char* filepath);
int processFile(const char* filepath);

#endif // FILE_PROCESSOR_H
