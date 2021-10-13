#ifndef UNTITLED2_FILE_WORK_H
#define UNTITLED2_FILE_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum {MAX_LINE_LENGTH = 256};

void FileCheck(FILE *fileStream,int flag);

int *LineReader(int arg_count, FILE *inputStream_Line);

#endif
