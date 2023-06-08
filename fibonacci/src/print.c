#include <stdio.h>

#include "print.h"



void print_args(int argc, char *argv[]) {

    printf("\n");
    printf("\targc: %d\n", argc);
    printf("\n");

    for (int i = 0; i < argc; i++) {

        printf("\targv[%d]: %s\n", i, argv[i]);
    }

    printf("\n");
}


void print_unsigned_long_long_array(char *desc, int len, unsigned long long *array) {

    printf("\t%s\n", desc);
    printf("\n");

    for (int i = 0; i < len; i++) {

        printf("\t%5d: %lld\n", i + 1, array[i]);
    }

    printf("\n");
}
