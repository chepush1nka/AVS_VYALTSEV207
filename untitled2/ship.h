#ifndef UNTITLED2_SHIP_H
#define UNTITLED2_SHIP_H

#include <stdio.h>

typedef struct transport struct_transport;

typedef struct {
    enum ship_type {liner = 1, tugboat, tanker} type_s;
    int water_displacement;
} structure_s;

void To_Ship(structure_s *ship, FILE *ifstream);

void Out_Ship(const structure_s *ship, FILE *ofstream);

structure_s *ToRand_Ship();

#endif
