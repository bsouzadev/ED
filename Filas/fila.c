#include <stdio.h>

//o primeiro item inserido é o primeiro removido. Como se fosse uma fila de caixa loterica.
//First in, first out (FIFO).
//pode ser implementada através de ponteiros ou arranjos. 

#define MAXTAM 1000

typedef int TipoApontador;
typedef int TipoChave;

typedef struct{
    TipoChave Chave;
    //pode ter outros componentes.
}TipoItem; //armazena o item que iremos colocar na fila (int).

typedef struct{
    TipoItem Item[MAXTAM]; //vetor de itens
    TipoApontador Frente, Tras; //apontador para o vetor, que irá representar a parte da frente, e de trás da fila.

}TipoFila;

void FFVazia (TipoFila *Fila){
    Fila->Frente = 1; 
    Fila->Tras = Fila->Frente; //aponta a parte da frente e a parte de trás da fila para o indice 1 do vetor.
}

int Vazia(TipoFila Fila){
    return (Fila.Frente == Fila.Tras); //se frente e trás forem iguais, a fila está vazia.
}

void Enfileira(TipoItem x, TipoFila *Fila){
    if(Fila->Tras % MAXTAM + 1 == Fila->Frente){ //verifica se a lista está cheia.
        printf("Erro, a fila esta cheia\n");
    } else{
        Fila->Item[Fila->Tras-1] = x; //insere o item do parametro, no trás -1, pois trás mostra qual numero está o vetor.
        Fila->Tras = Fila->Tras % MAXTAM + 1; //incrementar o trás, ele vai uma casa para frente.
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    if(Vazia(*Fila)){ //verifica se a fila está vazia.
        printf("Erro fila esta vazia\n");
    } else{
        *Item = Fila->Item[Fila->Frente-1]; //salva o item a ser removido em *Item.
        Fila->Frente = Fila->Frente % MAXTAM + 1; //incrementa a frente++ .
    }
}

void ImprimeLista(TipoFila *Fila){
    if(Vazia(*Fila)){
        printf("Erro, fila vazia\n");
    } else{
        int i = Fila->Frente; // começa da frente da fila
        while (i != Fila->Tras) { // percorre até o final
            printf("%d\n", Fila->Item[i - 1].Chave);
            i = i % MAXTAM + 1; // avança circularmente
        }
    }
}


int main(){
    TipoFila Fila;
    FFVazia(&Fila);

    TipoItem Item;
    for(int i =0; i<5; i++){
        Item.Chave = i + 1;
        Enfileira(Item,&Fila);
    }

    printf("Lista:\n");
    ImprimeLista(&Fila);

    printf("Desenfileirando...\n");
    Desenfileira(&Fila, &Item);
    printf("item desenfileirado = %d\n", Item.Chave);
    printf("Nova lista:\n");
    ImprimeLista(&Fila);
    

    return 0;
}