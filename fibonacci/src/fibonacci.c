#include <stdio.h>
#include <stdlib.h>

#include "fib.h"
#include "print.h"


int main(int argc, char *argv[]) {

    print_args(argc, argv);

    int n = strtol(argv[1], NULL, 10);

    printf("\n");
    printf("\tPrint the first %d Fibonacci numbers:\n", n);
    printf("\n");

    print_unsigned_long_long_array("Fibonacci numbers", n, fibonacci_numbers(n));

    return 0;
}
