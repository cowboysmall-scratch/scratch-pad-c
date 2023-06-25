#include <stdio.h>
#include <malloc.h>

#include "fib.h"


unsigned long long *fibonacci_numbers(int count) {

    unsigned long long *v = malloc(count * sizeof(unsigned long long));

    *(v + 0) = 0LL;
    *(v + 1) = 1LL;

    for (int i = 2; i < count; i++)
        *(v + i) = *(v + i - 1) + *(v + i - 2);

    return v;
}
