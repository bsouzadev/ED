#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

//Implementação das funções.

struct funcionario{
    char nome[52];
    int idade;
    char sexo;
    int anoT;
    float salario;
    int faltasC;
};

typedef struct funcionario Funcionario;

//Funções para alocar e desalocar o funcionario.
Funcionario *criaFuncionario();
void desalocaFuncionario(Funcionario *fun);



#endif