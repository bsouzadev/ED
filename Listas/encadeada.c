#include <stdio.h>
#include <stdlib.h>
 
//espaço não é continuo na memoria, e sim um item apontador para o proximo.
//lista com ponteiros.

typedef int TipoChave; //renomeando o inteiro.

//strcut que armazena o meu dado.
typedef struct{
    //tipo de elemento que vai estar dentro da minha lista.
    TipoChave Chave; //um inteiro para chave.

} TipoItem; //struct renomeada.

typedef struct TipoCelula *TipoApontador; //um ponteiro para a celula da lista (TipoCelula) ou seja, uma celula apontando para a outra.

typedef struct TipoCelula{
    TipoItem Item; //variavel da minha struct (guarda o dado).
    TipoApontador Prox; //uma ponteiro para a minha proxima celula.

} TipoCelula;

typedef struct{
    TipoApontador Primeiro, Ultimo; //aponta para a primeira celula (inicio da lista), e para a ultima (final da lista).

} TipoLista;


void FLVazia(TipoLista *Lista){ //cria a lista.
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula)); //cria uma celula em branco, e faz o primeiro elemento apontar para ela.
    Lista->Ultimo = Lista->Primeiro; //ultimo elemento da lista irá apontar para o primeiro elemento, que é a lista em branco a cima.
    Lista->Primeiro->Prox = NULL; //pega o lista primeiro, e atualiza o proximo elemento da celula para NULL. Ela não está apontado para nada.
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo); //verifica se a lista primeiro é igual a lista ultimo.
}

void Insere(TipoItem x, TipoLista *Lista){ //insere um elemento no final da lista.
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula)); //cria uma nova celula para a lista e atualiza o ultimo ponteiro para essa nova celula.
    Lista->Ultimo = Lista->Ultimo->Prox; //atualiza, e o ultimo aponta para a nova celula que criamos a cima.
    Lista->Ultimo->Item = x; //lista ultimo item recebe x, que é o elemento que vamos adicionar. Atualiza o item da celula que foi criada com os valores do parametro da função (x).
    Lista->Ultimo->Prox = NULL; //atualiza o proximo valor da celula para NULL. Indica que a celula está vazia.
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){ //parametros: recebe um ponteiro para uma celula (TipoApontador p), recebemos a lista, e um ponteiro para o item que vai retornar os itens removidos.

    //o item a ser retirado é o seguinte a ser apontado por P.
    TipoApontador q;
    if(Vazia(*Lista) || p == NULL || p->Prox == NULL){ //verifica se a lista está vazia, ou se p é nulo, ou se nenhum elemento após a celula que passamos no parametro.
        printf("Lista vazia ou posicao nao existe\n");
        return;
    }

    q = p->Prox; //salvamos a proxima celula em q.
    *Item = q->Item; //atualiza item com os parametros da celula que iremos remover.
    p->Prox = q->Prox; //p não vai passar a apontar para a celula que iremos remover, ela irá passar a apontar para a celula que q está apontado.
    if(p->Prox == NULL){ //verifica se o item que a gente removeu foi o ultimo elemento. Se sim atualiza o lista ultimo. 
        Lista->Ultimo = p; //ultimo estará apontado para a ultima celula.
    }

    free(q); //libera celula q, que foi retirada o numero.

}

void Imprime(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox; //aponta para a primeira celula que tem um tipo chave (valor). Aponta para o primeiro elemento da lista.
    while (Aux != NULL){ //percorre celula após celula até o prox de uma celula apontar para NULL, indicando que ela acabou.
        printf("%d\n", Aux->Item.Chave);
        Aux = Aux->Prox; //atualiza
    }
}

int main() {
    TipoLista lista;
    TipoItem item, retirado;

    // Inicializa a lista
    FLVazia(&lista);

    // Insere alguns elementos
    item.Chave = 10;
    Insere(item, &lista);

    item.Chave = 20;
    Insere(item, &lista);

    item.Chave = 30;
    Insere(item, &lista);

    printf("Lista original:\n");
    Imprime(lista);

    // Retira o segundo elemento (10 -> 20 -> 30)
    // O primeiro elemento da lista é lista.Primeiro->Prox
    // Então o p que aponta pro elemento antes do 20 é lista.Primeiro
    Retira(lista.Primeiro, &lista, &retirado);
    printf("\nElemento removido: %d\n", retirado.Chave);

    printf("\nLista apos remocao:\n");
    Imprime(lista);

    // Liberar a memória (opcional, mas boa prática)
    TipoApontador aux = lista.Primeiro;
    while (aux != NULL) {
        TipoApontador temp = aux;
        aux = aux->Prox;
        free(temp);
    }

    return 0;
}
