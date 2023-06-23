#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "table.h"



int offset(char* str, int start);

int number(char* str, int start, int off);

int update(char* str, int idx, int val, int* res);



int check(char* str) {

    int len = strlen(str);
    int idx = 0;
    int ctr = 0;

    while (idx < len) {

        if (*(str + idx) == '(')
            ctr++;

        if (*(str + idx) == ')')
            ctr--;

        if (ctr > 1 || ctr < 0)
            break;

        idx++;
    }
    return ctr;
}



int* table(char* str) {

    int *res = malloc(26 * sizeof(int));

    int len = strlen(str);
    int idx = 0;

    while (idx < len) {

        int par = 0;

        if (len - idx > 2 && *(str + idx + 1) == '(')
            par = 1;

        if (len - idx > 4 && *(str + idx + 2) == '#' && *(str + idx + 3) == '(')
            par = 3;

        if (par != 0) {

            int off = offset(str, idx + par);
            int nmb = number(str, idx + par, off);

            idx += update(str, idx, nmb, res);
            idx += off + 1;

        } else {

            idx += update(str, idx, 1, res);
        }
    }

    return res;
}





int offset(char* str, int start) {

    int off = 0;
    int ptr = start;

    while (*(str + ptr++) != ')')
        off++;

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



int update(char* str, int idx, int val, int* res) {

    if (*(str + idx + 2) == '#') {

        int dec = ((*(str + idx) - 48) * 10) + (*(str + idx + 1) - 48);
        if (1 <= dec && dec <= 26)
            *(res + dec - 1) += val;
        return 3;

    } else {

        int dec = (*(str + idx) - 48);
        if (1 <= dec && dec <= 26)
            *(res + dec - 1) += val;
        return 1;
    }
}
