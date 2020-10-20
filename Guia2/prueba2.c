#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 20

typedef struct
{
    char *texto;
    int anio, mes, dia;
} t_dato;

int sacarMes(unsigned int valor);
int sacarDia(unsigned int valor);
int sacarAnio(unsigned int valor);
void cargarArr(t_dato arrP[N], char *nomArch);
void imprimir(t_dato datos[N]);

int main()
{
    int j;
    t_dato datos[N];
    cargarArr(datos, "datos.csv");
    imprimir(datos);

    return 0;
}

void cargarArr(t_dato arrP[N], char *nomArch)
{
    int i = 0, j = 0;
    unsigned int num = 0;
    char *nombre = NULL;
    char letra;

    FILE *arch;
    arch = fopen(nomArch, "r");

    letra = fgetc(arch);
    while (letra != EOF)
    {
        nombre = malloc(sizeof(char));
        while (letra != ',')
        {
            *(nombre + i) = letra;
            i++;
            nombre = realloc(nombre, (i + 1) * sizeof(char));
            letra = fgetc(arch);
        }
        *(nombre + i) = '\0';
        arrP[j].texto = nombre;
        fscanf(arch, "%d\n", &num);
        arrP[j].mes = sacarMes(num);
        arrP[j].dia = sacarDia(num);
        arrP[j].anio = sacarAnio(num);
        letra = fgetc(arch);
        i = 0;
        j++;
    }
    arrP[j].texto = NULL;
    fclose(arch);
}

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

void imprimir(t_dato datos[N]){
    int j;
    for (j = 0; datos[j].texto != NULL; j++)  {
        printf("Nombre: %s\nFecha de nacimiento (D/M/A):%d/%d/%d\n\n", datos[j].texto, datos[j].dia, datos[j].mes, datos[j].anio);
    }
}