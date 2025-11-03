//Incluir todas as bibliotecas nescessarias. Incluindo a .h

#include <stdio.h>
#include <stdlib.h>
#include "relogio.h"


//Implementar a main.

int main(){

    int h, m, s;
    Relogio *r = cria_relogio();

    modifica_hora(r, 00, 18, 20);
    recupera_hora(r, &h,&m,&s);

    printf("%d %d %d\n", r->H, r->M, r->S);

    free(r);
    return 0;
}