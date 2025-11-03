#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcionario.h"

int main(){
    
    char r;
    Funcionario *f = criaFuncionario();
    system("clear");

    printf("---------- Informacoes do Funcionario(a) ----------\n");
    printf("%s", f->nome);
    printf("%d anos\n", f->idade);
    printf("Salario %.2f\n", f->salario);
    printf("Sexo: %c\n", f->sexo);
    printf("Faltas %d\n", f->faltasC);
    printf("Ano que comecou a trabalhar: %d\n", f->anoT);
    printf("\n");

    printf("Voce dejesa cadastrar outro Funcionario(a)? [Y/N]\n");
    scanf(" %c", &r);
    getchar();
    if(r == 'y' || r == 'Y'){
        desalocaFuncionario(f);
        f = criaFuncionario();
    } else {
        desalocaFuncionario(f);
    }

    return 0;
}



