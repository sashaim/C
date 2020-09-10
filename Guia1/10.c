#include <stdio.h>
#include <stdlib.h>
#define F 20
#define C 20
#define N 20


void cargarMatTextDeArch(char mat[F][C],char nom[N]);
void imprimirMatText(char mat[F][C]);

    int main(){
    char mat[F][C]={0};
    char nom[N]="equipos.txt";
    cargarMatTextDeArch(mat,nom);
    imprimirMatText(mat);

    return 0;
}

void cargarMatTextDeArch(char mat[F][C], char nom[N]){
    FILE *arch;
    arch=fopen(nom,"r");
    char letra;
    int f,c;
    letra=fgetc(arch);
    for(f=0;f<F && letra!= 10 && letra!=EOF;f++){
        for(c=0;c<C && letra!=10 ;c++){
            mat[f][c]=letra;
            letra=fgetc(arch);
        }
        mat[f][c]='\0';
        letra=fgetc(arch);
    } 
    mat[f][0]='\0';
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
