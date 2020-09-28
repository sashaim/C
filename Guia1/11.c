#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define F 25
#define C 25
#define N 25

void cargarMatTextDeArch(char mat[F][C], char nom[N]);
void imprimirMatText(char mat[F][C]);
void ordenarText(char mat[][N]);

int main()
{
    char mat[F][C] = {0};
    char nom[N] = "equipos.txt";
    cargarMatTextDeArch(mat, nom);
    imprimirMatText(mat);
    ordenarText(mat);
    imprimirMatText(mat);

    return 0;
}

void cargarMatTextDeArch(char mat[F][C], char nom[N])
{
    FILE *arch;
    arch = fopen(nom, "r");
    char letra;
    int f, c;
    letra = fgetc(arch);
    for (f = 0; f < F && letra != 10 && letra != EOF; f++)
    {
        for (c = 0; c < C && letra != 10; c++)
        {
            mat[f][c] = letra;
            letra = fgetc(arch);
        }
        mat[f][c] = '\0';
        letra = fgetc(arch);
    }
    mat[f][0] = '\0';
    fclose(arch);
}
void imprimirMatText(char mat[F][C])
{
    int fila, col;

    for (fila = 0; mat[fila][0] != '\0' && fila < F; fila++)
    {
        for (col = 0; col < C && mat[fila][col] != '\0'; col++)
        {
            printf("%c", mat[fila][col]);
        }
        printf("\n");
    }
    printf("\n");
}
// que significa ORDENARTEXT [][N] ??


void ordenarText(char mat[][N]){
    int fila,col;
    char arreglo[N]={0};
    for (fila=0;mat[fila][0]!= '\0';fila ++){
        for(col=0;mat[col][0]!= '\0'; col ++){
            if (strcmp(mat[fila],mat[col])<0){
                strcpy(arreglo,mat[fila]);
                strcpy(mat[fila],mat[col]);
                strcpy(mat[col],arreglo);
            }
        }
    }

}

