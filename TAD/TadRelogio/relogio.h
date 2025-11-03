#ifndef RELOGIO_H
#define RELOGIO_H

//Somente cabeçalho das funções

//Definição dos dados:

typedef struct relogio Relogio;

struct relogio{
    int H;
    int M;
    int S;
};

//Definição das operações:

Relogio *cria_relogio();
void recupera_hora(Relogio*, int*,int*,int*);
void modifica_hora(Relogio*, int, int, int);



#endif