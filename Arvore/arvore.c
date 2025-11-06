#include <stdio.h>
#include <stdlib.h>

struct Registro{
    int chave;

};

struct Arvore{
    struct Arvore *esq;
    struct Arvore *dir;
    struct Registro *reg;

};

struct Arvore *AlocaArvore(int chave){
    struct Arvore *novo = (struct Arvore*)malloc(sizeof(struct Arvore));
    if(novo == NULL) return NULL;
    novo->reg = (struct Registro*)malloc(sizeof(struct Registro));
    if(novo->reg == NULL){
        free(novo);
        return NULL;
    }
    novo->reg->chave = chave;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

struct Arvore *Insere(struct Arvore *f, int chave){
    if(f == NULL){
        return AlocaArvore(chave);
    }

    if(chave < f->reg->chave){
        f->esq = Insere(f->esq, chave);
    } else{
        f->dir = Insere(f->dir, chave);
    }

    return f;
}

void meio(struct Arvore *f){
    if(f == NULL) return;

    meio(f->esq);
    printf("%d\n", f->reg->chave);
    meio(f->dir);
}

void pre(struct Arvore *f){
    if(f == NULL) return;

    printf("%d\n", f->reg->chave);
    pre(f->esq);
    pre(f->dir);
}

void pos(struct Arvore *f){
    if(f == NULL) return;

    pos(f->esq);
    pos(f->dir);
    printf("%d\n", f->reg->chave);
}

void DesalocaArvore(struct Arvore *f){
    if(f == NULL) return;

    DesalocaArvore(f->esq);
    DesalocaArvore(f->dir);
    
    free(f->reg);
    free(f);
}

int main(){
    struct Arvore *raiz = NULL;

    printf("Digite 10 valores:\n");
    for(int i =0; i<10; i++){
        int item;
        scanf("%d", &item);
        raiz = Insere(raiz, item);
    }

    printf("Exibindo esses valores de forma pre:\n");
    pre(raiz);
    DesalocaArvore(raiz);
    return 0;
}