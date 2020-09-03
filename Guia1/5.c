#include <stdlib.h>
#include <stdio.h>
#define N 100

int estaEnArr(int arr[N], int x);
int esPos(int x);
void cargarArrPNR(int arr[N]);

int main(){
    int arr[N]={0};
    int i = 0;
    cargarArrPNR(arr);
    
    return 0;
}

void cargarArrPNR(int arr[N]){
    int i=0 ;
    int num;
    printf("ingrese numeros: ");
    scanf("%d",&num);
    
    while (num!=0 && i<N-1)
    {
        if ((esPos(num))==0){
            printf("Error! Solo numero positivos");
        }
        else if((estaEnArr(arr,num)) == 1){
            printf("Error! numero ya ingresado");
        }
        else{
            arr[i]= num;
            i++;
        }
        scanf("%d",&num);
    }
    arr[i]=0;
} 

int estaEnArr(int arr[N], int x){
    int i=0;
    while (arr[i]!= 0 && i<N-1){
        if (arr[i] == x){
            return 1 ; // TRUE == 1
        } 

        i ++;

    }
    return 0;
}

int esPos(int x){
    if (x >= 0){
        return 1;
    }
    else{
        return 0;
    }
}   