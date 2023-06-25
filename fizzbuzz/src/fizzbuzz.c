#include <string.h>
#include <stdio.h>
#include <stdlib.h>



static int help_message(char* message) {

    if (strlen(message) > 0) {

        printf("\n");
        printf("%s\n", message);
    }

    printf("\n");
    printf("Usage: fizzbuzz <number>\n");
    printf("\n");
    printf(" where <number> is a number greater than 0\n");
    printf("\n");

    return -1;
}



int main(int argc, char const* argv[]) {

    int n;

    if (argc == 1)
        return help_message("");

    if ((n = strtol(argv[1], NULL, 10)) <= 0)
        return help_message("!!! Invalid Value - please use value greater than zero !!!");

    printf("\n");

    for (int i = 1; i <= n; i++) {

        if (i % 15 == 0)
            printf("\tFizzBuzz!\n");
        else if (i % 3 == 0)
            printf("\tFizz!\n");
        else if (i % 5 == 0)
            printf("\tBuzz!\n");
        else
            printf("\t%d\n", i);
    }

    printf("\n");

    return 0;
}
