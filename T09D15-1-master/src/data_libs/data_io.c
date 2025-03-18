#include "data_io.h"
#include <stdio.h>
int input(double *data, int n) {
    int errorFlag = 0;
    char enterLiteral;
        for (int i = 0; i < n; i++) {
            if (!(scanf("%lf%c", &data[i], &enterLiteral) == 2 && (enterLiteral == ' ' || enterLiteral == '\n'))) {
                errorFlag = 1;
                break;
            }
        }
    return errorFlag;
}
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n -1) {
            printf("%lf", data[i]);
        } else {
            printf("%lf ", data[i]);
        }
    }
    printf("\n");
}
