

#include <stdio.h>

#include "constituency.h"

int main()
{
    const int numConstituencies = 5;
    struct Constituency constituencies[numConstituencies];
    constructConstituency(
        &constituencies[0], "Swansea East",
        (unsigned int[]){1, 2, 3, 4}, 4);
    constructConstituency(
        &constituencies[1], "Swansea West",
        (unsigned int[]){0, 2}, 2);
    constructConstituency(
        &constituencies[2], "Gower",
        (unsigned int[]){0, 1, 3}, 3);
    constructConstituency(
        &constituencies[3], "Neath",
        (unsigned int[]){0, 2, 4}, 3);
    constructConstituency(
        &constituencies[4], "Aberavon",
        (unsigned int[]){0, 3}, 2);

    struct Constituency *copy = copyConstituencies(constituencies,
                                                   numConstituencies);
    int i = 0;
    for (i = 0; i < numConstituencies; i++)
    {
        destructConstituency(&constituencies[i]);
    }



    int maxN = copy[0].numNeighbours, minN = copy[0].numNeighbours, maxC = 0, minC = 0;
    
    for (int i = 0; i < numConstituencies; i++) {
        printConstituency(&copy[i]);

        printf("\n");

        if (copy[i].numNeighbours > maxN) {
            maxN = copy[i].numNeighbours;
            maxC = i;
        }

        if (copy[i].numNeighbours < minN) {
            minN = copy[i].numNeighbours;
            minC = i;
        }
    }
    printf("\n");
    printf("\n");


    printf("%s has the most bordering constituencies:\n", copy[maxC].name);
    for (int i = 0; i < maxN; i++) {
        int index = copy[maxC].neighbours[i];
        printf("\t%s\n", copy[index].name);
    }

    printf("\n");

    printf("%s has the most fewest constituencies:\n", copy[minC].name);
    for (int i = 0; i < minN; i++) {
        int index = copy[minC].neighbours[i];
        printf("\t%s\n", copy[index].name);
    }

    printf("\n");
    printf("\n");


    for (int i = 0; i < numConstituencies; i++) {
        destructConstituency(&copy[i]);
    }

    return 0;
}