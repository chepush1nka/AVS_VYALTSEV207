#include "random.h"
#include <stdlib.h>
#include <assert.h>

/// Рандом делает рандом.
/// \param lowerBound нижняя граница генерации числа.
/// \param upperBound верхняя граница генерации числа.
int RandInt(const int lowerBound, const int upperBound) {
    assert(lowerBound <= upperBound);
    return (rand() % (upperBound - lowerBound + 1)) + lowerBound;
}