#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define C 20
#define F 20
#define N 20
// void intercambiar(int matI[F][C],int x,int y);
void intercambiar(int fila1[F],int fila2[C]);
void ordenarTabla(char matC[F][C],int matI[F][C],int col,int ord){
    int x ,y;
    int len;
    char aux[N]={0};
    int auxI[N]={0};
    printf("%d\n",len);
    //for(len=0;matI[0][len]!=100;len++);
    len=5;
    if(ord==0){
        for(x=0;x<len-1;x++){
            for(y=x;y<len;y++){
                if(matI[x][col]>matI[y][col]){
                    //que pasa si pongo mat[x]=mat[y];
                    strcpy(aux,matC[x]);
                    strcpy(matC[x],matC[y]);
                    strcpy(matC[y],aux);
                    intercambiar(matI[x],matI[y]);
                }
            }
        }
    }
    else if (ord == 1){
        for (x = 0; x < len - 1; x++){
            for (y = x; y < len ; y++){
                if (matI[x][col] < matI[y][col]){
                    //que pasa si pongo mat[x]=mat[y];
                    strcpy(aux, matC[x]);
                    strcpy(matC[x], matC[y]);
                    strcpy(matC[y], aux);
                    intercambiar(matI[x], matI[y]);
                }
            }
        }
    }
}

// void intercambiar(int matI[F][C], int x, int y){
//     int aux[N]={0};
//     int len,i;

//     for(len=0;matI[0][len]!= 10; len++);
//     for(i=0;i<len-1;i++){
//         aux[i]=matI[x][i];
//         matI[x][i]=matI[y][i];
//         matI[y][i]=aux[i]
//     }
//     //cant de columaas? ??


// }
void intercambiar(int fila1[F],int fila2[C]){
    int aux[F]={0};
    int i,len;
    len=8;
    printf("%d",len);
    for(i=0;i<len-1;i++){
        aux[i]=fila1[i];
        printf("%d",aux[i]);
        fila1[i]=fila2[i];
        fila2[i]=aux[i];
    }
}

// int main(){
//     int ord;

//     return 0;
// }

void imprimirTabla(int datos[][N], char cabeceras[][N], char items[][N], int fil, int col)
{
    int x;
    int y;

    printf("\n");

    //Imprimimos las cabeceras
    for (y = 0; y < col + 1; y++)
    {
        printf("%-20s", cabeceras[y]);
    }

    printf("\n");

    for (y = 0; y < col + 1; y++)
    {
        if (y == 0)
        {
            printf("-----------------");
        }
        else
        {
            printf("----------------");
        }
    }

    printf("\n");

    //Imprimimos los items a medida que pasan los datos
    for (y = 0; y < fil; y++)
    {
        printf("%-20s", items[y]);
        for (x = 0; x < col; x++)
        {
            if (datos[y][x] > 0 && x == 7)
            {
                printf("+%-19d", datos[y][x]);
            }
            else
            {
                printf("%-20d", datos[y][x]);
            }
        }
        printf("\n");
    }
}



void cargarMatNumDeArch(int mat[F][C], char nom[N])
{
    FILE *arch;
    arch = fopen(nom, "r");
    int num = 0;

    int f, n1, n2, n3, n4, n5, n6, n7, n8, n9;
    // duda como hacerlo generico
    for (f = 0; fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9) != EOF && f < F; f++)
    {
        mat[f][0] = n1;
        mat[f][1] = n2;
        mat[f][2] = n3;
        mat[f][3] = n4;
        mat[f][4] = n5;
        mat[f][5] = n6;
        mat[f][6] = n7;
        mat[f][7] = n8;
        mat[f][8] = 100; //terminador 100;;
    }
    mat[f][0] = 100;
    fclose(arch);
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


int main()
{
    char mat[F][C] = {0};
    int mat2[F][C] = {0};
    char cabeceras[F][C] = {0};
    int num, col;
    char nom[N] = "items.txt";
    char nom2[N] = "datos.txt";
    char nom3[N] = "cabeceras.txt";
    cargarMatTextDeArch(mat, nom);
    cargarMatNumDeArch(mat2, nom2);
    cargarMatTextDeArch(cabeceras, nom3);
    imprimirTabla(mat2, cabeceras, mat, 5, 8);

    printf("ingrese del 0 / 7 dependiendo de que col quiera ordenar: ");
    scanf("%d", &col);
    printf("Ingrese 0 si quiere ordenar ascendente o 1 si quiere descendente: ");
    scanf("%d", &num);
    ordenarTabla(mat, mat2, col, num);
    imprimirTabla(mat2, cabeceras, mat, 5, 8);

    return 0;
}
