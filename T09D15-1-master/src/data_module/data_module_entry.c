#include "data_process.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double *data;
    int n;
    scanf("%d", &n);
    data = (double*)malloc(n * sizeof(double));

    input(data, n);

    if (normalization(data, n)) {
        output(data, n);

    }
    else {
        printf("ERROR");  
    }
    free(data);
    return 0;
}
