#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "cilindro.h"


// OBS: O nome da variável usada para guardar o ponteiro (como 'c' na main)
// não precisa ser o mesmo nome usado dentro da função que faz o malloc.
// O que importa é que ambas sejam do tipo 'Cilindro*' e armazenem o mesmo
// endereço de memória retornado por malloc. Ou seja, o nome pode mudar,
// mas o ponteiro sempre aponta para o mesmo bloco de memória onde a struct
// foi alocada dinamicamente.


//Nas funções, Area e Volume:
// Não é necessário usar &c aqui, pois 'c' já é um ponteiro para a struct.
// O operador '&' só é usado quando queremos pegar o endereço de uma variável comum.
// Como 'c' já guarda o endereço retornado por malloc, basta passar 'c' diretamente.


int main(){
    float r=0,h=0;
    printf("Digite o raio e a altura do cilindro:\n");
    scanf("%f %f", &r,&h);

    Cilindro *c = criaCilindro(r,h); //Está me retornando uma struct alocada dinamicamente. Que tem como variavel C.



    float area = areaCilindro(c); //Passando o nome da minha variavel 'c' que recebeu o malloc.
    float volume = volumeCilindro(c); //Passando o nome da minha variavel 'c' que recebeu o malloc.
    printf("Área total do cilindro: %.2f\n", area);
    printf("Volume do cilindro: %.2f\n", volume);

    liberaCilindro(c); //Chamando a função, e passando como parametro o nome da variavel da main que retornou a struct alocada dinamicamente 'c'.
    
    return 0;
}