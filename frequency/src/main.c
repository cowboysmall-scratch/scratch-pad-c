#include <stdio.h>

#include "frequency.h"



int help_message();



int main(int argc, char *argv[]) {

    if (argc == 1)
        return help_message();

    printf("\n");
    printf("\tEncoded String: %s\n", argv[1]);
    printf("\n");

    int* res = frequency(argv[1]);

    for (int i = 0; i < 26; i++)
        printf("\t%5d -> %5d\n", i + 1, *(res + i));
    printf("\n");

    return 0;
}



int help_message() {

    printf("Usage: build/main <encoded>");
    printf("\n");
    printf("\n");
    printf(" where <encoded> is a string of letters encoded as numbers of the form:");
    printf("\n");
    printf("  a - i  ->   1 - 9");
    printf("\n");
    printf("  j - z  -> 10# - 26#");
    printf("\n");
    printf(" and n(c) where n is an encoded letter as per the above scheme, and c is the multiplicity");
    printf("\n");
    printf("\n");
    return -1;
}
