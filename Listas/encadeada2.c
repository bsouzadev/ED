#include <stdio.h>
#include <stdlib.h>

//segunda maneira de implementar a lista encadeada.

typedef struct no No;

struct no{
    int num;
    struct no *prox; //aponta para um proximo elemento, e tem que ser do tipo struct no.
}; 

No* criaNo(){
    No* novoNo = (No*)malloc(sizeof(No));
    
    return novoNo; //retorna um ponteiro para o novo nó (struct acima).
}

No* insereInicio(No *Lista, int dado){
    No* novo_No = criaNo();

    novo_No->num = dado;


    //lista criada e com um elemento. Se a lista estiver vazia.
    if(Lista == NULL){  //lista vazia
        Lista = novo_No; //lista aponta para o novoNo que foi criado acima.
        novo_No->prox = NULL; //proximo campo vai apontar para nulo.
    }else { //se a lista não estiver vazia.
        novo_No->prox = Lista; //aponta para aonde a lista estava apontando.
        Lista = novo_No; //lista aponta para esse novo nó.
    }

    return Lista;
}


void ImprimeLista(No* Lista){
    //não podemos mexer (incrementar) com a lista, pois ela já está apontado para os nós, então criaremos uma variavél auxiliar.

    No* Aux = Lista; //aux apontando para onde a lista está apontado.
    while(Aux != NULL){
        printf("%d\n", Aux->num);
        Aux = Aux->prox; //incremento.
    }
}


int main(){
    No* Lista = NULL; //declarando lista vazia. E apontando ela para NULL.
    Lista = insereInicio(Lista, 10);
    ImprimeLista(Lista);


    return 0;
}