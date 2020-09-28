//01H-Matriz-int
#include <stdio.h>

#define F 3 // Tamaño del arreglo
#define C 3 // Tamaño del arreglo

int ingresarIM(int f, int c)
{
    int x;
    printf("[%d][%d]: ", f, c);
    scanf("%d", &x);
    return x;
}

void cargarMatI(int mat[F][C])
{
    int f = 0, c = 0; // inicializar indice f y c en 0

    for (f = 0; f < F; f++)
    {
        for (c = 0; c < C; c++)
        {
            mat[f][c] = ingresarIM(f, c);
        }
    }
}

void imprimirMatI(int mat[F][C])
{
    int f = 0, c = 0; // inicializar indice f y c en 0

    for (f = 0; f < F; f++)
    {
        for (c = 0; c < C; c++)
        {
            printf("%4d", mat[f][c]);
        }
        printf("\n");
    }

    /*	for (f=0; f<F && mat[f][0]!=0; f++){*/
    /*		for(c=0;c<C&&mat[f][c]!=0;c++){*/
    /*			printf("%4d",mat[f][c]);*/
    /*		}*/
    /*		printf("\n");*/
    /*	}*/
}

int main()
{

    int mat[F][C] = {0};
    cargarMatI(mat);
    printf("\n");
    imprimirMatI(mat);
    //printf("El promedio es: %.2lf",promMat(mat));

    return 0;
}
