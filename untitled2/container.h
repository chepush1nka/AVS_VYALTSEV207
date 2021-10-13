#ifndef UNTITLED2_CONTAINER_H
#define UNTITLED2_CONTAINER_H

#include "transport.h"

typedef struct {
    struct_transport *data[10000];
    int count;
} struct_cont;

void Initialize_cont(struct_cont *container);

int Add_cont(struct_cont *container, struct_transport* transport);


void Clear_cont(struct_cont *container);

void Fill_cont(struct_cont *container, FILE *input_stream);

void Fill_cont_Rand(struct_cont *container, unsigned int count);

void Out_cont(struct_cont *container, FILE *output_stream);

void Straight_Merge(int i, int j, struct_cont container[], struct_cont help_container[]);

#endif
