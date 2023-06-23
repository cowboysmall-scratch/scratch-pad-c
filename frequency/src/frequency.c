#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "frequency.h"



int update(char* str, int* res, int idx, int val) {

    if (*(str + idx + 2) == '#') {

        int dec = ((*(str + idx) - 48) * 10) + (*(str + idx + 1) - 48);
        *(res + dec - 1) += val;
        return 3;

    } else {

        int dec = (*(str + idx) - 48);
        *(res + dec - 1) += val;
        return 1;
    }
}



int offset(char* str, int start, int end) {

    int off = 0;

    for (int i = start; i < end; i++)
        if (*(str + i) != ')')
            off += 1;
        else
            break;

    return off;
}



int number(char* str, int start, int off) {

    int cnt = 0;
    int pwr = 1;

    for (int i = off - 1; i >= 1; i--) {

        cnt += (*(str + start + i) - 48) * pwr;
        pwr *= 10;
    }

    return cnt;
}



int* frequency(char* str) {

    int *res = malloc(26 * sizeof(int));

    int len = strlen(str);
    int idx = 0;

    while (idx < len) {

        int par = 0;

        if (len - idx > 1 && *(str + idx + 1) == '(')
            par = 1;

        if (len - idx > 3 && *(str + idx + 2) == '#' && *(str + idx + 3) == '(')
            par = 3;

        if (par != 0) {

            int off = offset(str, idx + par, len);
            int nmb = number(str, idx + par, off);

            idx += update(str, res, idx, nmb);
            idx += off;

        } else {

            idx += update(str, res, idx, 1);
        }
    }

    return res;
}
