#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "table.h"

#define FIND(str, idx, chr) (*(str + idx) == chr)


int locate(char* str, int idx, int len);

int decode(char* str, int idx);

int offset(char* str, int start);

int multip(char* str, int start, int off);

int update(int* res, int dec, int mlt);



int check(char* str) {

    int len = strlen(str);
    int idx = 0;
    int ctr = 0;

    while (idx < len) {

        if (FIND(str,  idx, '('))
            ctr++;

        if (FIND(str,  idx, ')'))
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

        int par = locate(str, idx, len);

        if (par == 0) {

            int dec = decode(str, idx);

            idx += update(res, dec, 1);

        } else {

            int dec = decode(str, idx);
            int off = offset(str, idx + par);
            int mlt = multip(str, idx + par, off);

            idx += update(res, dec, mlt);
            idx += off + 1;
        }
    }

    return res;
}



int locate(char* str, int idx, int len) {

    if (idx + 2 < len && FIND(str, idx + 1, '('))
        return 1;
    else if (idx + 4 < len && FIND(str, idx + 2, '#') && FIND(str, idx + 3, '('))
        return 3;
    else
        return 0;
}


int decode(char* str, int idx) {

    if (FIND(str, idx + 2, '#'))
        return ((*(str + idx) - 48) * 10) + (*(str + idx + 1) - 48);
    else
        return (*(str + idx) - 48);
}


int offset(char* str, int start) {

    int off = 0;
    int ptr = start;

    while (*(str + ptr++) != ')')
        off++;

    return off;
}


int multip(char* str, int start, int off) {

    int mlt = 0;
    int pwr = 1;

    for (int i = off - 1; i >= 1; i--) {

        mlt += (*(str + start + i) - 48) * pwr;
        pwr *= 10;
    }

    return mlt;
}


int update(int* res, int dec, int mlt) {

    if (1 <= dec && dec <= 26)
        *(res + dec - 1) += mlt;

    return (dec < 10) ? 1 : 3;
}
