#include <stdio.h>

#include "frequency.h"


int main(int argc, char *argv[]) {

    int* res = frequency(argv[1]);

    for (int i = 0; i < 26; i++)
        printf("%d\n", *(res + i));
    printf("\n");

    return 0;
}
