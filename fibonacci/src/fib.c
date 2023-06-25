#include <stdio.h>
#include <malloc.h>

#include "fib.h"


unsigned long long *fibonacci_numbers(int count) {

    long long *v = malloc(count * sizeof(long long));

    *(v + 0) = 0;
    *(v + 1) = 1;

    for (int i = 2; i < count; i++)
        *(v + i) = *(v + i - 1) + *(v + i - 2);

    return v;
}
