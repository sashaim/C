#include <stdlib.h>
#include <stdio.h>
#define F 3
#define C 3


void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);
int promMat(int mat[F][C]);

int main(){
    int mat[F][C]={0};
    int promedio;
    cargarMat(mat);
    imprimirMat(mat);
    promedio=promMat(mat);
    printf("El promedio de los numeros de la mat es : %d \n",promedio);
    return 0;
}




void cargarMat(int mat[F][C]){
    int f,c;
    int num;
    printf("ingrese numeros a la matriz 3X3: ");
    //scanf("%d",&num);
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            scanf("%d",&num);
            mat[f][c]=num;
        }
    }
    mat[f][0]='\0';     
}
void imprimirMat(int mat[F][C]){
    int f,c;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            printf("%d",mat[f][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int promMat(int mat[F][C]){
    int i=0, total=0;
    int f,c,prom;
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            total=total+mat[f][c];
            i++;
            //printf("%d -- %d",total,i);
        }
    }
    prom=total/i;
    return prom;
}
