#include <stdlib.h>
#include <string.h>

#include "frequency.h"



int update(char* s, int* res, int idx, int val) {

    if (*(s + idx + 2) == '#') {

        int value = ((*(s + idx) - 48) * 10) + (*(s + idx + 1) - 48);
        res[value - 1] += val;

        return 3;

    } else {

        int value = (*(s + idx) - 48);
        res[value - 1] += val;

        return 1;
    }
}



int offset(char* s, int start, int end) {

    int off = 0;

    for (int i = start; i < end; i++) {

        if (*(s + i) != ')') {

            off += 1;

        } else {

            return off;
        }
    }
}



int number(char* s, int start, int off) {

    int cnt = 0;
    int pwr = 1;

    for (int i = off - 1; i >= 1; i--) {

        cnt += (*(s + start + i) - 48) * pwr;
        pwr *= 10;
    }

    return cnt;
}



int* frequency(char* s) {

    int *res = malloc(26 * sizeof(int));

    int len = strlen(s);
    int idx = 0;

    while (idx < len) {

        int par = 0;

        if (*(s + idx + 1) == '(')
            par = 1;

        if (*(s + idx + 2) == '#' && *(s + idx + 3) == '(')
            par = 3;


        if (par != 0) {

            int off = offset(s, idx + par, len);
            int nmb = number(s, idx + par, off);

            idx += update(s, res, idx, nmb);
            idx += off;

        } else {

            idx += update(s, res, idx, 1);
        }
    }

    return res;
}
