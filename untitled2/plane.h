#ifndef UNTITLED2_PLANE_H
#define UNTITLED2_PLANE_H

#include <stdio.h>

typedef struct transport struct_transport;

typedef struct {
    int flight_range;
    int load_capacity;
} structure_p;

void To_Plane(structure_p *plane, FILE *input_stream);


void PlaneOut(const structure_p *plane, FILE *output_stream);

structure_p *ToRand_Plane();

#endif
