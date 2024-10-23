#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "constituency.h"



void constructConstituency(struct Constituency * const obj, char const *name, unsigned int* const neigbhours, unsigned int const numNeighbours) {
        obj->name = NULL;
        obj->neighbours = NULL;
        obj->numNeighbours = 0;

        int len = strlen(name) + 1;
        obj->name = (char*) malloc(len);
        memcpy(obj->name, name, len * sizeof(char));


        obj->neighbours = (int*) malloc(sizeof(unsigned int) * numNeighbours);
        obj->numNeighbours = numNeighbours;

        if (numNeighbours > 0 ) {
            memcpy((*obj).neighbours, neigbhours, numNeighbours * sizeof(unsigned int));
        }

    }
void printConstituency(struct Constituency * const obj) {

    printf("%s | %d neighbours | [ ", (obj->name), obj->numNeighbours);


    for (int i = 0; i < obj->numNeighbours; i++) {
        printf("%d ", obj->neighbours[i]);
    }

    printf("]");



}
void destructConstituency(struct Constituency * const obj) {
    obj->name = NULL;
    obj->numNeighbours = 0;
    obj->neighbours = NULL;

    free(obj->name);
    free(obj->neighbours);
    

}


struct Constituency* copyConstituencies(struct Constituency constituencies[], const unsigned int numConstituencies) {

    
    struct Constituency* newConstituencies = (struct Constituency*) malloc(sizeof(struct Constituency) * numConstituencies);
    for (int i = 0; i  < numConstituencies; i++) {
        constructConstituency(&newConstituencies[i], constituencies[i].name, constituencies[i].neighbours, constituencies[i].numNeighbours);
    }
    return newConstituencies;
}

