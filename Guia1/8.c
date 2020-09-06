#include <stdio.h>
#include <stdlib.h>
#define F 3
#define C 3

void transponer(int mat[F][C]);
void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);

int main(){
    int mat[F][C]={0};
    cargarMat(mat);
    imprimirMat(mat);
    printf("La transpuesta es :\n");
    transponer(mat);
    imprimirMat(mat);
    return 0;
}

void transponer(int mat[F][C]){
    int f,c;
    int aux;
    for(f=0;f<F;f++){
        for(c=f;c<C;c++){
            if (f!=c){
                aux=mat[f][c];
                mat[f][c]=mat[c][f];
                mat[c][f]=aux;
            }
            

        }
    }
}
void cargarMat(int mat[F][C])
{
    int f, c;
    int num;
    printf("ingrese numeros a la matriz 3X3: ");
    //scanf("%d",&num);
    for (f = 0; f < F; f++)
    {
        for (c = 0; c < C; c++)
        {
            scanf("%d", &num);
            mat[f][c] = num;
        }
    }
    mat[f][0] = '\0';
}
void imprimirMat(int mat[F][C])
{
    int f, c;
    for (f = 0; f < F; f++)
    {
        for (c = 0; c < C; c++)
        {
            printf("%d", mat[f][c]);
        }
        printf("\n");
    }
    printf("\n");
}