#include <string.h>
#include <stdio.h>

#include "table.h"



static int help_message(char* message) {

    if (strlen(message) > 0) {

        printf("\n");
        printf("%s\n", message);
    }

    printf("\n");
    printf("Usage: frequency <encoded>\n");
    printf("\n");
    printf(" where <encoded> is a string of letters\n encoded as numbers of the form:\n");
    printf("\n");
    printf("  a - i  ->   1 - 9\n");
    printf("  j - z  -> 10# - 26#\n");
    printf("\n");
    printf(" and n(c) where n is an encoded letter\n as per the above scheme, and c is the\n multiplicity\n");
    printf("\n");

    return -1;
}



int main(int argc, char *argv[]) {

    if (argc == 1)
        return help_message("");

    if (check(argv[1]) != 0)
        return help_message("!!! Malformed Encoded String - please check for matching parenthesis !!!");

    printf("\n");
    printf("\tencoded string: %s\n", argv[1]);
    printf("\n");

    int* res = table(argv[1]);

    for (int i = 0; i < 26; i++)
        printf("\t%5d -> %5d\n", i + 1, *(res + i));
    printf("\n");

    return 0;
}
