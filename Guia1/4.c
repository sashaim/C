#include <stdio.h>
#include <stdlib.h>
#define N 100
void cargarArr(int arr[N]);
void invertirArr(int arr[N]);
void imprimirArr(int arr[N]);
void ordenarArr(int arr[N]);

int main(){
    int arr1[N];
    int arr2[N];
    cargarArr(arr1);
    invertirArr(arr1);
    imprimirArr(arr1);
    printf("\n");
    cargarArr(arr2);
    ordenarArr(arr2);
    imprimirArr(arr2);
    printf("\n");
    
    printf("\n");
    return 0 ;
}
void cargarArr(int arr[N])
{
    int i = 0;
    printf("ingresar numeros a cargar : ");
    scanf("%d",&arr[i]);
    while(arr[i]!= 0){
        i++;
        scanf("%d",&arr[i]);
    }
    arr[i]=0;
}

void imprimirArr(int arr[N]){
    int i;
    for (i=0;arr[i]!=0;i++){
        printf("%d",arr[i]);
    }
}

void invertirArr(int arr[N]){
    int cant;
    int i =0;
    int aux;
    for (cant=0;arr[cant]!=0;cant ++);
    cant = cant -1;
    while (i < cant){
        aux = arr[i];
        arr[i] = arr[cant];
        arr[cant]= aux;
        cant -- ;
        i ++;
    }
}

void ordenarArr(int arr[N]){
    int i,j;
    int aux;
    for (i =0; arr[i]!=0;i++){
        for(j=i+1;arr[j]!=0; j++){
            if (arr[i]>arr[j]){
                aux=arr[i];
                arr[i]=arr[j];
                arr[j]=aux;
            }
        }
    }
}