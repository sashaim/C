#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int redondeo(double num);
int piso(double num);
int techo(double num);
int main(){
    double num;
    printf("ingrese un numero real = ");
    scanf("%lf", &num);
    printf("Redonde: %d \n",redondeo(num));
    printf("Techo= %d \n",techo(num));
    printf("Piso = %d \n",piso(num));



    return 0;
}

int redondeo(double num){
    int entero;
    entero = num ;
    double decimal;
    decimal = num - entero ;
    if (decimal >= 0.5 ){
        entero = entero +1 ;
        return entero;
    }
    else if (decimal < 0.5)
    {
        entero = entero;
        return entero;

    }
}

int techo(double num){
    int entero;
    entero = num;
    return entero +1;
}

int piso(double num){
    int entero;
    entero = num;
    return entero ;
}