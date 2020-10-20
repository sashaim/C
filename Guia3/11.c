#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a,b;
}t_dosint;



void intercambiar(int *puntero1,int *puntero2){
    int aux;
    aux=*puntero1;
    *puntero1=*puntero2;
    *puntero2=aux;
}


int main(){
    t_dosint datos;
    datos.a=10,datos.b=20;
    printf("Numero 1: %d\n", datos.a);
    printf("Numero 2: %d\n\n", datos.b);
    
    printf("Intercambio:\n");

    intercambiar(&datos.a, &datos.b);

    printf("Numero 1: %d\n", datos.a);
    printf("Numero 2: %d\n", datos.b);

    return 0;
}