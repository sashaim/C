#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 20

typedef struct
{
    char *texto;
    int anio, mes,dia;
} t_dato;

int sacarMes(unsigned int valor)
{
    unsigned int MASK1;
    MASK1 = pow(2, 8) - 1;
    return (valor)&MASK1;
}
int sacarDia(unsigned int valor)
{
    unsigned int MASK1;
    MASK1 = pow(2, 8) - 1;
    return (valor >> 8) & MASK1;
}
int sacarAnio(unsigned int valor)
{
    unsigned int MASK1;
    MASK1 = pow(2, 16) - 1;
    return (valor >> 16) & MASK1;
}

void cargar(t_dato dat[N],char *nombre){
    FILE *arch;
    arch=fopen(nombre,"r");
    char *nom;
    char c;
    int i,k=0,num;
    nom=malloc(sizeof(char));
    c=fgetc(arch);
    while(c!=EOF){
        for(i=0;c!=',';i++){
            *(nom+i)=c;
            nom=realloc(nom,(1+i)*sizeof(char));
            c=fgetc(arch);
        }
        *(nom+i)='\0';
        dat[k].texto=nom;
        fscanf(arch,"%d\n",&num);
        //decod(&dat[k],num);
        dat[k].mes = sacarMes(num);
        dat[k].dia = sacarDia(num);
        dat[k].anio = sacarAnio(num);
        
        c=fgetc(arch);
        k++;
    }
    dat[k].texto=NULL;
    fclose(arch);

}

// void decod(t_dato dat[N],unsigned int numero){
//     int MASK1,MASK2;
//     MASK1=255;
//     MASK2=pow(2,16)-1;
//     dat[N].mes = numero& MASK1;
//     dat[N].dia = numero>>8 & MASK1;
//     dat[N].anio = numero>>16 & MASK1;
// }


int main()
{
    int i;
    t_dato dat[N];

    cargarArreglo(dat, "datos.csv");
    for (i = 0; dat[i].texto != NULL; i++)
        printf("\nLa efemerides es : %s ,el mes es : %d y el anio es %d \n",
               dat[i].texto, dat[i].mes, dat[i].anio);

    return 0;
}