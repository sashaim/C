#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *nom1,int *nom2);

int main(){
    int nom1,nom2;
    printf("ingrese el primer numero :");
    scanf("%d",&nom1);
    printf("ingrese el segundo numero : ");
    scanf("%d",&nom2);
    intercambiar(&nom1,&nom2);
    printf("los numero intercambiados son %d %d \n",nom1,nom2);

    return 0;
}

void intercambiar(int *nom1, int *nom2){
    int aux;
    aux=*nom1;
    *nom1=*nom2;
    *nom2=aux;

}