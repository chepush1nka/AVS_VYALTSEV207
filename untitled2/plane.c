#include "plane.h"
#include "transport.h"
#include "timer.h"

/// Считывание данных о новом самолете.
/// \param plane самолет.
/// \param input_stream входной файл.
void To_Plane(structure_p* plane, FILE *input_stream) {
    int *values = LineReader(2, input_stream);
    if (values == NULL) {
        fprintf(stderr, "invalid plane data");
        TimePrint();
        exit(EXIT_FAILURE);
    } else {
        plane->flight_range = values[0];
        plane->load_capacity = values[1];
    }
}

/// Выводим все, что знаем про самолет.
/// \param plane самолет.
/// \aram output_stream выходной файл.
void PlaneOut(const structure_p *plane, FILE *output_stream) {
    printf("flight range: %d,\n"
           " load capacity: %d\n",
           plane->flight_range, plane->load_capacity);

    fprintf(output_stream,
            "flight range: %d,\n"
            " load capacity: %d\n",
            plane->flight_range, plane->load_capacity);
}

/// Придумываем самолет.
structure_p *ToRand_Plane() {
    structure_p *plane = malloc(sizeof(structure_p));

    plane->flight_range = RandInt(800, 5000);
    plane->load_capacity = RandInt(100, 450);

    return plane;
}
