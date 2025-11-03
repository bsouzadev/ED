#include <stdio.h>
#include "cilindro.h"
#include <stdlib.h>
#include <math.h>

//Implementação das funções...

Cilindro *criaCilindro(float raio, float altura){
    Cilindro *c = (Cilindro*)malloc(sizeof(Cilindro)); //Alocação dinamica da minha struct.
    if(c == NULL){  //Verifica se deu erro na alocação.
        printf("Erro de alocacao\n");
        exit(1);
    }

    c->altura = altura;
    c->raio = raio;

    return c; //Retornando a minha struct alocada dinamicamente.
}

void liberaCilindro(Cilindro *c){  //Cilindro *c como parametro, pois é o nome da variavel 'c' que eu fiz o malloc.
    free(c); //Liberando o espaço alocado.
}

float areaCilindro(Cilindro *c){  //Cilindro *c como parametro, pois é o nome da variavel 'c' que eu fiz o malloc.
    float area_base = 3.14 * pow(c->raio, 2);
    float area_lateral = 2 * 3.14 * c->raio * c->altura;
    float area_total = 2 * area_base + area_lateral;
    return area_total;
}

float volumeCilindro(Cilindro *c){  //Cilindro *c como parametro, pois é o nome da variavel 'c' que eu fiz o malloc.
    float volume = 3.14 * pow(c->raio, 2) * c->altura;
    return volume;
}