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


int* frequency(char* s, int* res_cnt) {

    *res_cnt = 26;
    int *res = malloc(26 * sizeof(int));

    int len = strlen(s);
    int idx = 0;

    while (idx < len) {

        int par = 0;

        if (*(s + idx + 1) == '(')
            par = 1;

        if (*(s + idx + 2) == '#' && *(s + idx + 3) == '(')
            par = 3;


        if (par == 0) {

            idx += update(s, res, idx, 1);

        } else {

            int cnt = 0;
            int off = 0;

            for (int j = idx + par; j < len; j++) {

                if (*(s + j) != ')') {

                    off++;

                } else {

                    int pwr = 1;

                    for (int k = 1; k < off; k++) {

                        cnt += (*(s + j - k) - 48) * pwr;
                        pwr *= 10;
                    }

                    break;
                }
            }

            idx += update(s, res, idx, cnt);
            idx += off;
        }

    }

    return res;
}

