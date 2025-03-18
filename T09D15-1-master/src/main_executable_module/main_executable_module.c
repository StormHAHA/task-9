#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> 
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"
int main()
{
    double *data;
    int n;
    scanf("%d", &n);
    data = (double*)malloc(n * sizeof(double));
    int errorFlag = 0;

    void *handle = dlopen("../data_module/data_process.so", RTLD_LAZY); 
    if (!handle) {
        errorFlag = 1;
    }

    int (*make_decision)(double*, int) = dlsym(handle, "make_decision");
    if (!make_decision) {
        dlclose(handle);
        errorFlag = 1;
    }
    if (errorFlag == 0) {
        printf("LOAD DATA...\n");
        input(data, n);

        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);
        
        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);
        
        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES"); 
        else
            printf("NO");
    }
     
    free(data);
    
    return 0;
}
