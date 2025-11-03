#include <stdio.h>

//uma pilha é bem similar a uma lista, ela é um tipo para armazenar um conjunto de itens.
//porém a pilha tem operações diferentes.
//IMPORTANTE: O ultimo elemento a ser inserido, é o primeiro a ser removido. (É como se fosse um pilha de pratos).
//Last in, first out (LIFO).
//podemos implementar uma pilha com arranjos ou ponteiros. Aqui será implementado com arranjos.

#define MAXTAM 10

typedef int TipoApontador;
typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    //pode ter outros componentes...
}TipoItem; //struct chamada tipo item, porque ela armazena o item que iremos colocar na pilha (int).

typedef struct { //definição da pilha.
    TipoItem Item[MAXTAM]; //vetor
    TipoApontador Topo; //apontador para o topo da pilha (int). Aponta para a posição do vetor que representa o topo da pilha.

}TipoPilha;

void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = 0; //topo igual a 0, não tem nada na pilha. Cria pilha vazia.
}

int VerificaVazia(TipoPilha *Pilha){
    return (Pilha->Topo == 0);
    //para verificar se a pilha está vazia, basta verificar se o topo está igual (posição) a 0.
}

void Empilha(TipoItem x, TipoPilha *Pilha){
    if(Pilha->Topo == MAXTAM){ //verifica se a pilha está cheia.
        //se entrar no if, siginifica que a pilha está cheia.
        printf("Erro, a pilha está cheia\n");
    } else{
        Pilha->Topo++; //move o topo em uma posição. Passa para a posição seguinte.
        Pilha->Item[Pilha->Topo-1] = x; //posição a qual o topo estava irá receber o item x.
    }
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item){
    if(VerificaVazia(Pilha)){ //verifica se a lista está vazia.
        printf("Erro, pilha vazia\n");
    }else{
        *Item = Pilha->Item[Pilha->Topo-1]; //salva em *Item o item que está sendo desempilhado.
        Pilha->Topo--; //e decrementar o valor do topo.
    }
}

int Tamanho(TipoPilha Pilha){ //verificar o tamanho da pilha
    return (Pilha.Topo); //o tamanho da pilha é a posição em que o topo está apontando (isso porque ele está apontado para o vetor). 
}

void ImprimePilha(TipoPilha Pilha){
    for(int i = 0; i < Pilha.Topo; i++){
        printf("%d ", Pilha.Item[i].Chave);
    }
    printf("\n");
}

int main(){
    TipoPilha Pilha;
    FPVazia(&Pilha);
    
    TipoItem Item;

    printf("Verificando se a pilha esta vazia\n");
    int RPilha = VerificaVazia(&Pilha);
    printf("%d\n", RPilha);
    
    for(int i = 0; i < 5; i++){
        Item.Chave = i + 1;
        Empilha(Item, &Pilha);
    }

    printf("Conteudo da pilha (como vetor): ");
    ImprimePilha(Pilha);

    Desempilha(&Pilha, &Item);
    printf("Desempilhei: %d\n", Item.Chave);

    printf("Pilha agora: ");
    ImprimePilha(Pilha);
    return 0;
}