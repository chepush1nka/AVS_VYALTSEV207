#include <stdio.h>

void WrongArguments() {
    fprintf(stderr, "The program expects 4 arguments\n");
    fprintf(stderr, "Example:\n"
                    "command -f input.txt output.txt\n");
}

void WrongMode() {
    fprintf(stderr, "invalid mod specified\n"
                    "Expected:\n"
                    "1) command -f input.txt output.txt\n"
                    "2) command -n number output.txt\n");
}