#include <stdio.h>
#include <stdlib.h>
#include "expressao.h"
#include <math.h>

int main() {

    char expr[] = "3 4 + 5 *";

    char *infixa = getFormaInFixa(expr);
    float valor  = getValorPosFixa(expr);

    printf("Posfixa: %s\n", expr);
    printf("Infixa : %s\n", infixa ? infixa : "(erro)");
    printf("Valor  : %f\n", valor);

    free(infixa); // IMPORTANTE
    return 0;
}
