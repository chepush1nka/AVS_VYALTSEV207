#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "container.h"
#include "timer.h"
#include "exceptions.h"


int main(int argc, char* argv[]) {
    clockStart = clock();
    struct_cont container;
    if(argc != 4) {
        WrongArguments();
        TimePrint();
        exit(EXIT_FAILURE);
    }
    Initialize_cont(&container);
    if (strcmp(argv[1], "-f") == 0) {
        FILE *input_stream = fopen(argv[2], "r");
        FileCheck(input_stream, 0);
        Fill_cont(&container, input_stream);
    }
    else if(strcmp(argv[1], "-n") == 0) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            fprintf(stderr, "the program was waiting for a positive number less than 10000"
                            "as the third argument\n", size);

            TimePrint();
            exit(EXIT_FAILURE);
        }

        srand(time(0));
        Fill_cont_Rand(&container, (int) size);
    }
    else {
        WrongMode();
        TimePrint();
        exit(EXIT_FAILURE);
    }
    FILE *output_stream = fopen(argv[3], "w");
    FileCheck(output_stream, 1);
    Out_cont(&container, output_stream);
    struct_cont help_container;
    Straight_Merge(0, -1, &container, &help_container);
    printf("\nBest time:\n");
    fprintf(output_stream, "\nBest time:\n");
    Out_cont(&container, output_stream);
    Clear_cont(&container);
    TimePrint();
    return 0;
}