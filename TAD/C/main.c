#include "racional.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int a=0,b=0;
    scanf("%d %d", &a,&b);
    Racional *r1 = cria_racional(a,b);
    Racional *r2 = cria_racional(a,b);

    Racional *so = soma(r1, r2);
    Racional *su = subtrai(r1, r2);
    Racional *d = divide(r1, r2); 
    int comparacao = compara(r1, r2);
    printf("%d\n", comparacao);

    destroi_racional(r1);
    destroi_racional(r2);
    destroi_racional(so);
    destroi_racional(su);
    destroi_racional(d);
    return 0;
}