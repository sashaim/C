#include <stdlib.h>
#include <stdio.h>
#define F 10
#define C 10

void cargarMatText(char mat[F][C]);
void imprimirMatText(char mat[F][C]);
void ordenarMatText(char mat[F][C]);

int main(){
    char mat[F][C]={0};
    cargarMatText(mat);
    imprimirMatText(mat);
    ordenarMatText(mat);
    imprimirMatText(mat);
    return 0;
}

void cargarMatText(char mat[F][C]){
    int fila ,col ;
    char c;
    printf("Agregue texto a la matriz ; ");
    c=getchar();
    for(fila=0;fila<F && c!= 10;fila++){   // el "\r"
        for(col=0;col<C && c!= 10 ;col ++){
            mat[fila][col]=c;
            c=getchar();
        }
        mat[fila][col]='\0';
        c=getchar();
    }
    mat[fila][0]='\0';
}

void imprimirMatText(char mat[F][C]){
    int fila,col;
    
    for (fila = 0; mat[fila][0] != '\0' && fila<F; fila++){
        for (col = 0; col < C && mat[fila][col]!= '\0'; col++){
            printf("%c",mat[fila][col]);
        }
        printf("\n");

    }
    printf("\n");
}

void ordenarMatText(char mat[F][C]){
    int fila ,col, col2;
    char aux;
    for (fila = 0; mat[fila][0] != '\0' && fila < F; fila++)
    {
        for (col = 0; col < C && mat[fila][col] != '\0'; col++)
        {
            if (mat[fila][col]>='A' && mat[fila][col] <= 'Z'){
                mat[fila][col]=mat[fila][col]+32;
            }
            else if(mat[fila][col]>=mat[fila][col+1]){
                aux=mat[fila][col];
                mat[fila][col]=mat[fila][col+1];
                mat[fila][col+1]=aux;

            }
            for (col2=col+1;col2<C && mat[fila][col]!= '\0';col++)


        }
        
    }
}
// como ordenar bien esto