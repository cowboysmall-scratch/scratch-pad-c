#include <stdio.h>

#include "frequency.h"


int main(int argc, char *argv[]) {

    int result_cnt;
    int* result = frequency(argv[1], &result_cnt);

    for (int i = 0; i < result_cnt; i++)
        printf("%d\n", *(result + i));
    printf("\n");

    return 0;
}
