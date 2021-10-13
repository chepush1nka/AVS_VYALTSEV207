#include "file_work.h"
#include "timer.h"

void FileCheck(FILE *fileStream, int flag){
    if(!fileStream) {
        if (flag == 0){
            perror("invalid input file");
        } else{
            perror("invalid output file");
        }
        TimePrint();
        exit(EXIT_FAILURE);
    }
}
/// Считывание данных их строки файла.
/// \param arg_count счетчик считываемых аргументов.
/// \param inputStream_Line файл с входными данными.
int *LineReader(int arg_count, FILE *inputStream_Line) {
    int* values = calloc(arg_count, sizeof(int));
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, inputStream_Line) == NULL) {
        values = NULL;
    } else{
        char **sc = calloc(arg_count, sizeof(char*)), *wc, *end;
        wc = strtok(line, " ");
        int index = 0;
        while (wc != NULL) {
            sc[index] = wc;
            wc = strtok(NULL, " ");
            index++;
        }
        if (index != arg_count) {
            fprintf(stderr, "invalid number of arguments in one of the lines");
            TimePrint();
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < index; i++) {
            values[i] = strtol(sc[i], &end, 10);
        }
        free(sc);
    }
    return values;
}
