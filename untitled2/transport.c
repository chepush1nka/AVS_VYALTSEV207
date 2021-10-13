#include <stdlib.h>
#include "transport.h"
#include "timer.h"

/// Получаем время пути.
/// \param transport транспорт.
double RoadTime(const struct_transport *transport) {
    return transport->the_road / transport->speed;
}

/// Считывание данных о новом транспорте.
/// \param input_stream входной файл.
struct_transport *To_Transport(FILE *input_stream) {
    struct_transport *transport;
    transport = malloc(sizeof(struct_transport));
    int *values = LineReader(3, input_stream);
    if(values == NULL) {
        return NULL;
    }
    if (values[0] < 1 || values[0] > 3) {
        fprintf(stderr, "invalid transport type");
        TimePrint();
        exit(EXIT_FAILURE);
    }
    transport->transport_type = values[0];
    transport->speed = values[1];
    transport->the_road = values[2];
    switch (transport->transport_type) {
        case PLANE:{
            To_Plane(&transport->p, input_stream);
            break;
        }
        case TRAIN: {
            To_Train(&transport->t, input_stream);
            break;
        }
        case SHIP: {
            To_Ship(&transport->s, input_stream);
            break;
        }
        default:
            free(transport);
            fprintf(stderr, "invalid transport type");
            TimePrint();
            exit(EXIT_FAILURE);
    }
    return transport;
}

/// Выводим данные о транспортном средстве в консоль и в файл.
/// \param transport транспортное средство.
/// \param output_stream выходной файл.
void Out_Transport(const struct_transport *transport, FILE *output_stream) {
    double roadTime = RoadTime(transport);
    switch (transport->transport_type) {
        case PLANE:
            printf("PLANE. Speed: %d, "
                   "distance: %f, "
                   "road time: %f, ",
                   transport->speed, transport->the_road,
                   roadTime);

            fprintf(output_stream, "PLANE. Speed: %d, "
                                   "distance: %f, "
                                   "road time: %f, ",
                    transport->speed, transport->the_road,
                    roadTime);
            PlaneOut(&transport->p, output_stream);
            break;
        case SHIP:
            printf("SHIP. Speed: %d, "
                   "distance: %f, "
                   "road time: %f, ",
                   transport->speed, transport->the_road,
                   roadTime);

            fprintf(output_stream, "SHIP. Speed: %d, "
                              "distance: %f, "
                              "road time: %f, ",
                    transport->speed, transport->the_road,
                    roadTime);
            Out_Ship(&transport->s, output_stream);
            break;
        case TRAIN:
            printf("TRAIN. Speed: %d, "
                   "distance: %f, "
                   "road time: %f, ",
                   transport->speed, transport->the_road,
                   roadTime);

            fprintf(output_stream, "TRAIN. Speed: %d, "
                                   "distance: %f, "
                                   "road time: %f, ",
                    transport->speed, transport->the_road,
                    roadTime);
            Out_Train(&transport->t, output_stream);
            break;
    }
}

//-------------------------------------------------------------------------
/// Рандомно генерируем данные о транспортных средствах.
struct_transport *ToRand_Transport() {
    struct_transport *transport = malloc(sizeof(struct_transport));
    transport->speed = RandInt(1, 200);
    transport->the_road = RandInt(5, 2000);
    transport->transport_type = RandInt(1, 3);

    switch (transport->transport_type) {
        case PLANE:
            transport->p = *ToRand_Plane();
            break;
        case TRAIN:
            transport->t = *ToRand_Train();
            break;
        case SHIP:
            transport->s = *ToRand_Ship();
            break;
    }

    return transport;
}
