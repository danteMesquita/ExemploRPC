#include <stdio.h>
#include "calculadora.h"

int * soma_1_svc(int *n, struct svc_req *attr) {
    printf("Função SOMA - Recebido número: %d\n", *n);
    *n = *n + 1;
    return(n);
}

int * subtrai_1_svc(int *n, struct svc_req *attr) {
    printf("Função SUBTRAÇÃO - Recebido número: %d\n", *n);
    *n = *n - 1;
    return(n);
}
