#include <stdio.h>
//implementando pilha sozinho.

typedef struct {
    int num;

} TipoItem;

typedef struct {
    TipoItem Item[10];
    int Topo;

} TipoPilha;

void FPilha(TipoPilha *Pilha){
    Pilha->Topo = 0;
}

//verifica 
int VPilha(TipoPilha Pilha){
    return (Pilha.Topo == 0);
}

//empilha
void EmpilhaPilha(TipoItem x, TipoPilha *Pilha){
    if(Pilha->Topo == 10){ //verifica se a pilha está cheia.
        printf("Erro, pilha cheia\n");
        return;
    } else{
        Pilha->Topo++; //incrementa primeiro.
        Pilha->Item[Pilha->Topo - 1] = x; //para depois fazer o topo -1.
    }
}

//tamanho
int TamanhoPilha(TipoPilha *Pilha){
    return (Pilha->Topo);
}

//desempilha
void DesempilhaPilha(TipoItem *Item, TipoPilha *Pilha){
    if(VPilha(*Pilha)){ //verifica se a lista está vazia.
        printf("Erro, Pilha vazia\n");
        return;
    } else{
        *Item = Pilha->Item[Pilha->Topo - 1];
        Pilha->Topo--;
    }
}