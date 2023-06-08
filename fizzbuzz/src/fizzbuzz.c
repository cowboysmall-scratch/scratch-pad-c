#include <stdio.h>
#include <stdlib.h>


int help_message();


int main(int argc, char const* argv[]) {

    int n;

    if (argc == 1 || (n = strtol(argv[1], NULL, 10)) <= 0)
        return help_message();

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


int help_message() {

    printf("Usage: fizzbuzz <number>");
    printf("\n");
    printf("\n");
    printf(" where <number> is a number greater than 0");
    printf("\n");
    printf("\n");
    return -1;
}

