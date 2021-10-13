#ifndef UNTITLED2_TRANSPORT_H
#define UNTITLED2_TRANSPORT_H

#include "plane.h"
#include "ship.h"
#include "train.h"
#include "random.h"
#include "file_work.h"


typedef struct transport {
    enum transport_type_enum {PLANE = 1, SHIP, TRAIN} transport_type;
    int speed;
    double the_road;
    union {
        structure_p p;
        structure_s s;
        structure_t t;
    };
} struct_transport;

double RoadTime(const struct_transport *transport);

struct_transport *To_Transport(FILE *input_stream);

void Out_Transport(const struct_transport *transport, FILE *output_stream);

struct_transport *ToRand_Transport();

#endif
