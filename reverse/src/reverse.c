#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {

    char reversed[100];

    int length = strlen(argv[1]);

    for (int i = 0; i < length; i++)
        reversed[i] = argv[1][length - i - 1];

    printf("\n");
    printf("\tString reversed: %s\n", reversed);
    printf("\n");

    return 0;
}
