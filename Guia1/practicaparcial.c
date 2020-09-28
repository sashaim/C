#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 25
#define C 25
#define N 25

void cargarArchivo(char mat[F][C],char nom[F]);
void imprimirMat(char mat[F][C]);
void aMayus(char mat[F][C]);
void aMinus(char mat[F][C]);
void ordenarText(char mat[][C],int ord);

int main(){
    char mat[F][C]={0};
    char nom[F]="archivo.txt";
    int ord;
    
    cargarArchivo(mat,nom);
    imprimirMat(mat);
    aMayus(mat);
    printf("\n");
    imprimirMat(mat);
    aMinus(mat);
    printf("\n");
    imprimirMat(mat);
    printf("\n");
    printf("ingrese un orden 1|0 :");
    scanf("%d", &ord);
    printf("\n");
    ordenarText(mat,ord);
    imprimirMat(mat);
    printf("\n");
    
    return 0;
}

void cargarArchivo(char mat[F][C],char nom[F]){
    FILE * arch;
    arch=fopen(nom,"r");
    char letra;
    int f, c;

    letra = fgetc(arch);
    for (f=0;f<F && letra != EOF && letra !=10;f++){
        for(c=0;c<C && letra!=10;c++){ 
            while (letra == 32){
                letra = fgetc(arch);
            }
            mat[f][c]=letra;
            letra=fgetc(arch);
        }
        mat[f][c]='\0';
        letra = fgetc(arch);
    }
    mat[f][0]='\0';
    fclose(arch);
}



void imprimirMat(char mat[F][C]){
    int f,c;
    for(f=0;f<F && mat[f][0]!= '\0';f++){
        for(c=0;c<C && mat[f][c]!='\0';c++){
            printf("%c",mat[f][c]);
        }
        printf("\n");
    }
}  

void aMayus(char mat[F][C]){
    int f, c;
    for (f = 0; f < F && mat[f][0] != '\0'; f++)
    {
        for (c = 0; c < C && mat[f][c] != '\0'; c++)
        {
            if(mat[f][c]>= 'a' && mat[f][c] <='z'){

                mat[f][c]=mat[f][c]-32;

            }
            
        }
    }
}

void aMinus(char mat[F][C])
{
    int f, c;
    for (f = 0; f < F && mat[f][0] != '\0'; f++)
    {
        for (c = 0; c < C && mat[f][c] != '\0'; c++)
        {
            if (mat[f][c] >= 'A' && mat[f][c] <= 'Z')
            {

                mat[f][c] = mat[f][c] + 32;
            }
        }
    }
}

void ordenarText(char mat[][N],int ord)
{
    int fila, col;
    char arreglo[N] = {0};
    if (ord == 0){
        for (fila = 0; mat[fila][0] != '\0'; fila++)
        {
            for (col = 0; mat[col][0] != '\0'; col++)
            {
                if (strcmp(mat[fila], mat[col]) < 0)
                {
                    strcpy(arreglo, mat[fila]);
                    strcpy(mat[fila], mat[col]);
                    strcpy(mat[col], arreglo);
                }
            }
        }
    }
    else if (ord ==1){
        for (fila = 0; mat[fila][0] != '\0'; fila++)
        {
            for (col = 0; mat[col][0] != '\0'; col++)
            {
                if (strcmp(mat[fila], mat[col]) > 0)
                {
                    strcpy(arreglo, mat[fila]);
                    strcpy(mat[fila], mat[col]);
                    strcpy(mat[col], arreglo);
                }
            }
        }
    }
}

