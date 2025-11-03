#include <stdio.h>
//implementando fila sozinho.

typedef struct {
    int num;

} TipoItem;

typedef struct{
    TipoItem Item[10];
    int Frente, Tras;

} TipoFila;

void FFVazia(TipoFila *Fila){
    Fila->Frente = 1;
    Fila->Tras = 1;
}

int VFVazia(TipoFila Fila){
    return (Fila.Frente == Fila.Tras);
}

void IncrementaFila(TipoItem x, TipoFila *Fila){
    if(Fila->Tras % 10 + 1 == Fila->Frente){ //verifica se ela esta cheia.
        printf("Erro\n");
        return;

    } else{
        Fila->Item[Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % 10 + 1;
    } 
}

void DesenfileiraFila(TipoItem *Item, TipoFila *Fila){
    if(VFVazia(*Fila)){ //verifica se a lista está vazia.
        printf("Erro, Fila vazia\n");
        return;
    } else {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % 10 + 1;
    }
}