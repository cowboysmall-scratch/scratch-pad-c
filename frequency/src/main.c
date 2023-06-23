#include <stdio.h>

#include "frequency.h"


int main(int argc, char *argv[]) {

    printf("\n");
    printf("\tstring: %s\n", argv[1]);
    printf("\n");

    int* res = frequency(argv[1]);

    for (int i = 0; i < 26; i++)
        printf("\t%5d -> %5d\n", i + 1, *(res + i));
    printf("\n");

    return 0;
}
