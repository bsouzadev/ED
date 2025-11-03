//Incluir todas as bibliotecas nescessarias. Incluindo a .h

#include "relogio.h" 
#include <stdlib.h>
#include <stdio.h>

//Implementação das funções.


Relogio *cria_relogio(){
    Relogio *r = (Relogio*)malloc(sizeof(Relogio));
    r->H = 0;
    r->M = 0;
    r->S = 0;

    return r;
}


void recupera_hora(Relogio *r, int *h, int *m, int *s){
    *h = r->H;
    *m = r->M;
    *s = r->S;
}


void modifica_hora(Relogio *r, int h, int m, int s){
    r->H = h;
    r->M = m;
    r->S = s;
}