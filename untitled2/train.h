#ifndef UNTITLED2_TRAIN_H
#define UNTITLED2_TRAIN_H

#include <stdio.h>

typedef struct transport struct_transport;


typedef struct {
    int number_of_wagons;
} structure_t;


/// Initializes the structure_t object with arguments from input file stream.
/// @param train Pointer to the object being initialized.
/// @param input_stream Input file stream.
void To_Train(structure_t *train, FILE *input_stream);

/// Returns the pointer to structure_t object initialized with random values.
structure_t *ToRand_Train();

/// Prints a description of the structure_t object to output file stream.
/// @param train Pointer to the object being described.
/// @param output_stream Output file stream.
void Out_Train(const structure_t *train, FILE *output_stream);

#endif
