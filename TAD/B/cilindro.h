#ifndef CILINDRO_H
#define CILINDRO_H

typedef struct cilindro{ //Struct cilindro.
    float raio;
    float altura;
} Cilindro;

Cilindro *criaCilindro(float raio, float altura);   //Cilindro *criaCilindro = Variavel para a minha struct Cilindro do tipo ponteiro.
void liberaCilindro(Cilindro *c); //Cilindro *c é o nome da minha variavel que eu fiz o malloc dentro da função acima.
float areaCilindro(Cilindro *c); //Cilindro *c é o nome da variavel do malloc.
float volumeCilindro(Cilindro *c); //Cilidro *c é o nome da variavel do malloc.


#endif