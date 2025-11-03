#include "racional.h"
#include <stdio.h>
#include <stdlib.h>

Racional* cria_racional(int n, int d){
    Racional *r = (Racional*)malloc(sizeof(Racional));
    r->denominador = n;
    r->numerador = d;
    return r;
}

Racional* subtrai(Racional* a, Racional* b){
    Racional *su = (Racional*)malloc(sizeof(Racional));
    su->denominador = a->denominador * b->numerador;
    su->numerador = (a->numerador * b->numerador) - (b->numerador * a->numerador);

    return su;
}

Racional* soma(Racional* a, Racional* b){
    Racional *so = (Racional*)malloc(sizeof(Racional));
    so->numerador = (a->numerador * b->denominador) + (b->numerador * a->denominador);
    so->denominador = a->denominador * b->denominador;

    // Retorna o ponteiro para o novo racional
    return so;
}

Racional* subtrai(Racional* a, Racional* b){
    Racional* r = (Racional*) malloc(sizeof(Racional));
    // Calcula o numerador e o denominador
    r->numerador = (a->numerador * b->denominador) - (b->numerador * a->denominador);
    r->denominador = a->denominador * b->denominador;

    // Retorna o resultado
    return r;
}

Racional* divide(Racional* a, Racional* b) {
    // Verifica se o divisor é zero (numerador zero implica divisão inválida)
    if (b->numerador == 0) {
        printf("Erro: divisao por zero!\n");
        exit(1);
    }

    // Aloca memória para o resultado
    Racional* r = (Racional*) malloc(sizeof(Racional));

    // Fórmula da divisão de frações
    r->numerador = a->numerador * b->denominador;
    r->denominador = a->denominador * b->numerador;

    // Retorna o resultado
    return r;
}

int compara(Racional* a, Racional* b){
    if(a->denominador == b->denominador && a->numerador == b->numerador) return 1;

    return 0;
}


void destroi_racional(Racional* a){
    free(a);
}