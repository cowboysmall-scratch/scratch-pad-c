#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {

    int len = argc - 1;
    int tmp;
    int cnt = 0;

    int *srt = malloc((argc - 1) * sizeof(int));

    for (int i = 0; i < len; i++)
        *(srt + i) = atoi(argv[i + 1]);

    // for (int i = 0; i < len - 1; i++) {

    //     for (int j = len - 1; j > i; j--) {

    //         if (*(srt + j - 1) < *(srt + j)) {

    //             tmp = *(srt + j - 1);
    //             *(srt + j - 1) = *(srt + j);
    //             *(srt + j) = tmp;

    //             printf("swap %5d: %5d -> %5d [", ++cnt, *(srt + j - 1), *(srt + j));
    //             for (int k = 0; k < len; k++) {

    //                 printf("%d", *(srt + k));
    //                 if (k < len - 1)
    //                     printf(" ");
    //             }
    //             printf("]\n");
    //         }
    //     }
    // }

    for (int i = 0; i < len - 1; i++) {

        for (int j = 0; j < len - 1 - i; j++) {

            if (*(srt + j) < *(srt + j + 1)) {

                tmp = *(srt + j);
                *(srt + j) = *(srt + j + 1);
                *(srt + j + 1) = tmp;

                printf("swap %5d: %5d -> %5d [", ++cnt, *(srt + j + 1), *(srt + j));
                for (int k = 0; k < len; k++) {

                    printf("%d", *(srt + k));
                    if (k < len - 1)
                        printf(" ");
                }
                printf("]\n");
            }
        }
    }

    printf("\n");

    for (int i = 0; i < argc - 1; i++)
        printf("\t%5d -> %5d\n", i + 1, *(srt + i));
    printf("\n");

    return 0;
}
