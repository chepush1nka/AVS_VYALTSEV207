#include "timer.h"
#include "stdio.h"

/// Вывод информации о времени работы программы.
void TimePrint() {
    clockEnd = clock();
    float seconds = (float)(clockEnd - clockStart) / CLOCKS_PER_SEC;
    fprintf(stdout, "The program has worked for %.9g seconds\n", seconds);
}
