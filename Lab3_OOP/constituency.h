#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H

#include <stdio.h>

#pragma pack(1)
struct Constituency {
    char *name;
    unsigned int *neighbours;
    int numNeighbours;
};

void constructConstituency(struct Constituency * const obj, char const *name, unsigned int* const neigbhours, unsigned int const numNeighbours);

void printConstituency(struct Constituency * const obj);
void destructConstituency(struct Constituency * const obj);

struct Constituency* copyConstituencies(struct Constituency constituencies[], const unsigned int numConstituencies);

// constituency* constituency_new(char const *name, unsigned int* const neighbours, unsigned int const numNeighbours);

#endif