#include "transport.h"
#include "timer.h"
#include "train.h"

/// Считывание данных о новом кыруабле.
/// \param train кыруабль.
/// \param input_stream входной файл.
void To_Train(structure_t* train, FILE *input_stream) {
    int *values = LineReader(1, input_stream);
    if (values == NULL) {
        fprintf(stderr, "invalid train data");
        TimePrint();
        exit(EXIT_FAILURE);
    }
    train->number_of_wagons = values[0];
}

/// Выводим все, что знаем про поезд.
/// \param train поезд.
/// \param output_stream выходной файл.
void Out_Train(const structure_t *train, FILE *output_stream) {
    printf("number of wagons: %d\n", train->number_of_wagons);
    fprintf(output_stream, "number of wagons: %d\n", train->number_of_wagons);
}

/// Придумываем поезд.
structure_t *ToRand_Train() {
    structure_t *train = malloc(sizeof(structure_t));
    train->number_of_wagons = RandInt(1, 20);
    return train;
}
