#include <stdio.h>
#include <stdlib.h>
#define N 20

int *posicion(int arr[N], int pos);
int main(){
    int arr[N]={0};
    arr[0]=10;
    arr[1]=2;
    arr[2]=4;

    int pos=2;
    
    
    int *direccion = posicion(arr,pos);
    printf("%p \n ",&arr);
    printf("%p \n",direccion);
    printf("%d \n",*direccion);

    return 0;
}

int *posicion(int arr[N], int pos){
    return &arr[pos];
}