#ifndef RACIONAL_H
#define RACIONAL_H

struct racional{
    int numerador;
    int denominador;
};

typedef struct racional Racional;

Racional* cria_racional(int, int);
Racional* soma(Racional* a, Racional* b);
Racional* subtrai(Racional* a, Racional* b);
Racional* divide(Racional* a, Racional* b);
int compara(Racional* a, Racional* b); // 0=diferente e 1=igual
void destroi_racional(Racional* a);


#endif