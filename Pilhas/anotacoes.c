#include <stdio.h>
#define MAXTAM 10

// ---------- Definições de tipos ----------
typedef int TipoApontador;
typedef int TipoChave;

// Cada "TipoItem" é uma struct que representa UM elemento da pilha.
// Ela guarda a informação (nesse caso, um inteiro chamado Chave).
typedef struct {
    TipoChave Chave;
} TipoItem;

// A pilha é uma struct que contém:
// - um VETOR de TipoItem (Item[MAXTAM])
// - e um "Topo" que controla até onde a pilha está ocupada.
typedef struct {
    TipoItem Item[MAXTAM];  // vetor de structs (cada uma tem uma "Chave")
    TipoApontador Topo;     // mostra o índice da próxima posição livre
} TipoPilha;


// ---------- Funções da Pilha ----------

// Inicializa a pilha: quando está vazia, o topo é 0.
void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = 0;
}

// Verifica se a pilha está vazia (Topo == 0 significa que não há elementos).
int VerificaVazia(TipoPilha *Pilha){
    return (Pilha->Topo == 0);
}

// Empilha insere um novo elemento no topo da pilha.
// Ela recebe o item pronto e decide automaticamente onde colocá-lo.
void Empilha(TipoItem x, TipoPilha *Pilha){
    if(Pilha->Topo == MAXTAM){
        printf("Erro, pilha cheia!\n");
    } else {
        // O novo item é colocado na posição apontada por "Topo".
        Pilha->Item[Pilha->Topo] = x;

        // Depois de inserir, incrementa o Topo (agora aponta para a próxima posição livre).
        Pilha->Topo++;
    }
}

// Desempilha remove o elemento do topo e retorna ele em *Item.
void Desempilha(TipoPilha *Pilha, TipoItem *Item){
    if(VerificaVazia(Pilha)){
        printf("Erro, pilha vazia!\n");
    } else {
        // Primeiro decrementa o topo (porque o último elemento será removido).
        Pilha->Topo--;

        // Copia o item removido para a variável passada por referência (*Item).
        *Item = Pilha->Item[Pilha->Topo];
    }
}

// Retorna o número de elementos atualmente na pilha.
int Tamanho(TipoPilha Pilha){
    return Pilha.Topo;
}

// Imprime todos os elementos armazenados (da base até o topo).
void ImprimePilha(TipoPilha Pilha){
    for(int i = 0; i < Pilha.Topo; i++){
        printf("%d ", Pilha.Item[i].Chave);
    }
    printf("\n");
}


// ---------- Função principal ----------
int main(){
    TipoPilha pilha; // Cria a pilha
    FPVazia(&pilha); // Inicializa a pilha como vazia

    TipoItem item;   // Cria um item (caixinha) que será empilhado

    // FOR: aqui vamos empilhar 5 itens, com valores de 1 a 5.
    for(int i = 0; i < 5; i++){
        // Define o valor da "Chave" do item atual.
        // item.Chave acessa o campo "Chave" dentro da struct TipoItem.
        item.Chave = i + 1;

        // Chama a função Empilha para inserir o item na pilha.
        // Note que NÃO usamos pilha.Item[i].Chave aqui, porque quem
        // controla a posição é a função Empilha, via Pilha->Topo.
        Empilha(item, &pilha);
    }

    // Exibe o conteúdo da pilha (vai mostrar: 1 2 3 4 5)
    printf("Conteúdo da pilha: ");
    ImprimePilha(pilha);

    // Agora vamos remover o último elemento empilhado.
    Desempilha(&pilha, &item);

    // Mostra qual foi removido.
    printf("Desempilhei: %d\n", item.Chave);

    // Mostra como ficou a pilha depois da remoção.
    printf("Pilha agora: ");
    ImprimePilha(pilha);

    return 0;
}
