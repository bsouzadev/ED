#include <stdio.h>

//incrementação feita no final.
//espaço continuo na memoria.
//lista com arranjo (vetores).

#define INICIOARRANJO 1
#define MAXTAM 1000

typedef int TipoApontador;
typedef int TipoChave;

typedef struct {
    //tipo de elemento que vai estar dentro da minha lista.
    TipoChave Chave; //inteiro para a chave (indice).
} TipoItem; // struct renomeada.

typedef struct {
    TipoItem Item[MAXTAM]; //uma variavel para a minha struct tipoitem, (vetor). Aqui é aonde eu vou armazenar os elementos da struct TipoItem. Cada posição é um elemento.
    TipoApontador Primeiro, Ultimo; //indica pra qual posição do vetor está apontado.
} TipoLista; // struct renomeada.


void FlVazia(TipoLista *Lista){ //inicia e modifica a propia lista
    Lista->Primeiro = INICIOARRANJO; //primeira elemento da lista = 1.
    Lista->Ultimo = Lista->Primeiro; //ultimo elemento da lista = 1.
    //ambos estão "apontando" para o primeiro elemento do vetor.
}


int Vazia(TipoLista Lista){ //copia da lista para vez se ela está vazia.
    return (Lista.Primeiro == Lista.Ultimo); //se as duas variaveis estão apontando para a mesma posição, lista vazia.
}

void Insere(TipoItem x, TipoLista *Lista){ //é O(1), constante, porque não precisa mover nada no vetor.
    if(Lista->Ultimo > MAXTAM){ //verifica se tem espaço para inserir o item x.
        printf("Lista cheia\n");
    } else{
        //se houver espaço, será pegado o meu vetor de itens na posição ultimo - 1 (isso porque o meu ultimo está apontando para uma posição a mais que o item) e será adicionado x.
        Lista->Item[Lista->Ultimo - 1] = x; 
        Lista->Ultimo++; //incrementando o ultimo, e mudando a posição que ele estará apontando.
    }

    //insere no final da lista.
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){ //parametros: recebe uma posição do item que vai ser removido (TipoApontador p), tem a lista, e o vetor.
    int aux;
    if(Vazia(*Lista) || p >= Lista->Ultimo){ //verifica se a poisção é valida, chamando a função vazia. Ou irá ver se a posição é >= ao ultimo elemento da lista. 
        printf("A posicao nao existe\n");
        return;
    }
    
    //caso a posição existir... custo O(n).
    *Item = Lista->Item[p - 1];
    Lista->Ultimo--; //tirando um item da lista, decrementando no ultimo.
    for(aux = p; aux < Lista->Ultimo; aux++){ //pega a posição que está removendo o elemento, e todas as posições posteriores são arredadas para trás. Isso é feito até o ultimo elemento valido da lista.
        Lista->Item[aux-1] = Lista->Item[aux];
    }

    //retira
}

void Imprime(TipoLista Lista){
    int aux;
    for(aux = Lista.Primeiro - 1; aux <= (Lista.Ultimo - 2); aux++){ //lista.primeiro - 1 representa o vetor na posição 0.
        printf("%d\n", Lista.Item[aux].Chave);
    }

    //imprime.
}

int main() {
    TipoLista lista;
    TipoItem item;
    TipoItem retirado;
    int i;

    // Inicializa a lista
    FlVazia(&lista);

    // Inserindo alguns elementos na lista
    for(i = 1; i <= 5; i++) {
        item.Chave = i * 10; // valores: 10, 20, 30, 40, 50
        Insere(item, &lista);
    }

    // Imprime a lista
    printf("Lista depois de inserir elementos:\n");
    Imprime(lista);

    // Retira o 3º elemento (posição 3)
    Retira(3, &lista, &retirado);
    printf("\nElemento retirado: %d\n", retirado.Chave);

    // Imprime a lista depois da retirada
    printf("Lista depois de retirar o elemento da posicao 3:\n");
    Imprime(lista);

    // Verifica se a lista está vazia
    if(Vazia(lista)) {
        printf("\nA lista esta vazia.\n");
    } else {
        printf("\nA lista nao esta vazia.\n");
    }

    return 0;
}
