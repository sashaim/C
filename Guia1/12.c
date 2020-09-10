#include <stdlib.h>
#include <stdio.h>
#define F 20
#define C 20
#define DATOS 8

void cargarMatNumDeArch(int mat[F][C],char nom[F]);
void imprimirMat(int mat[F][C]);

    int main()
{
    int mat[F][C]={0};
    char nom[F]="puntos.txt";
    cargarMatNumDeArch(mat,nom);
    imprimirMat(mat);


    return 0;
}

void cargarMatNumDeArch(int mat[F][C], char nom[F]){
    FILE *arch;
    arch=fopen(nom,"r");
    int num=0;

    int f,n1,n2,n3,n4,n5,n6,n7,n8,n9;
   // duda como hacerlo generico
    for(f=0;fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9)!=EOF && f<F ;f++){
       mat[f][0]=n1;
       mat[f][1] = n2;
       mat[f][2] = n3;
       mat[f][3] = n4;
       mat[f][4] = n5;
       mat[f][5] = n6;
       mat[f][6] = n7;
       mat[f][7] = n8;
       mat[f][8]=100; //terminador 100;;
    }
    mat[f][0]=EOF;
    fclose(arch);
}


void imprimirMat(int mat[F][C])
{
    int f, c;
    for (f = 0; f < F && mat[f][0]!= EOF; f++)
    {
        for (c = 0; c < C && mat[f][c]!=100 ; c++)
        {
            if(mat[f][c]>0 && c==DATOS-1){
                printf("+%d\t", mat[f][c]);
            }
            else{
                printf("%d\t", mat[f][c]);
            }
            
        }
        printf("\n");
    }
    printf("\n");
}