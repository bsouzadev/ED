#include "funcionario.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Funcionario *criaFuncionario(){
    Funcionario *f = (Funcionario*)malloc(sizeof(Funcionario));
    printf("Digite o nome do Funcionario(a):\n");
    fgets(f->nome, 52, stdin);
    printf("Digite a idade do Funcionario(a):\n");
    scanf("%d", &f->idade);
    getchar();
    printf("Digite o sexo do Funcionario(a):\n");
    scanf("%c", &f->sexo);
    printf("Digite o ano que ele(a) começou a trabalhar:\n");
    scanf("%d", &f->anoT);
    printf("Digite o salario do Funcionario(a):\n");
    scanf("%f", &f->salario);
    printf("Digite quantas faltas esse Funcionario(a) possui:\n");
    scanf("%d", &f->faltasC);
    getchar();

    return f;
}


void desalocaFuncionario(Funcionario *f){
    free(f);
}