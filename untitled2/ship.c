#include <stdlib.h>
#include "ship.h"
#include "transport.h"
#include "timer.h"

/// Считывание данных о новом кыруабле.
/// \param ship кыруабль.
/// \param input_stream входной файл.
void To_Ship(structure_s *ship, FILE *ifstream) {
    int *values = LineReader(2, ifstream);
    if (values == NULL) {
        fprintf(stderr, "invalid plane data");
        TimePrint();
        exit(EXIT_FAILURE);
    }
    if (values[0] < 1 || values[0] > 3) {
        fprintf(stderr, "invalid type of the ship");
        TimePrint();
        exit(EXIT_FAILURE);
    }
    ship->type_s = values[0];
    ship->water_displacement = values[1];
}

/// Выводим все, что знаем про кораблик.
/// \param ship кораблик.
/// \param output_stream выходной файл.
void Out_Ship(const structure_s *ship, FILE *ofstream) {
    char* shipType;
    switch (ship->type_s) {
        case liner:
            shipType = "liner";
            break;
        case tugboat:
            shipType = "tugboat";
            break;
        case tanker:
            shipType = "tanker";
            break;
    }
    printf("ship type: %s,\n"
           " water_displacement: %d\n",
           shipType, ship->water_displacement);

    fprintf(ofstream, "ship type: %s,\n"
                      " water_displacement: %d\n",
            shipType, ship->water_displacement);
}

/// Придумываем корабль.
structure_s *ToRand_Ship() {
    structure_s *ship = malloc(sizeof(structure_s));
    ship->type_s = RandInt(1, 3);
    ship->water_displacement = RandInt(20000, 50000);

    return ship;
}