#include <stdio.h>
#include <stdlib.h>

#define F 20
#define C 20
#define N 20

void ordenarTabla(char mat[F][C],int mat2[F][C],int col,int ord);
void cargarMatNumDeArch(int mat[F][C], char nom[N]);
void cargarMatTextDeArch(char mat[F][C], char nom[N]);
void SwapI(int ele1[F], int ele2[F]);
void SwapC(char ele1[F], char ele2[F]);
void imprimirTabla(int datos[][N], char cabeceras[][N], char items[][N], int fil, int col);
void strcpy(char arregloCopia[], char arreglo[]); 
int main()
{
    char mat[F][C]={0};
    int mat2[F][C]={0};
    char cabeceras[F][C]={0};
    int num,col;
    char nom[N]="items.txt";
    char nom2[N]="datos.txt";
    char nom3[N]="cabeceras.txt";
    cargarMatTextDeArch(mat,nom);
    cargarMatNumDeArch(mat2,nom2);
    cargarMatTextDeArch(cabeceras,nom3);
    imprimirTabla(mat2,cabeceras,mat,5,8);

    printf("ingrese del 0 / 7 dependiendo de que col quiera ordenar: ");
    scanf("%d",&col);
    printf("Ingrese 0 si quiere ordenar ascendente o 1 si quiere descendente: ");
    scanf("%d",&num);
    ordenarTabla(mat,mat2,col,num);
    imprimirTabla(mat2, cabeceras, mat, 5, 8);

    return 0;
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
    mat[f][0] = EOF;
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

void ordenarTabla(char mat[F][C],int mat2[F][C],int col,int ord){
    int i , j ,len;
    //for (len=0;mat2[len]!='\0';len ++);
    //printf("%d",len);
    len = 6;
    for (i=0;i<len-1;i++){
        for (j=i;j<len-1;j++){
            if(ord==0){ //ordena de manera ascendente
                if (mat2[i][col-1] > mat2[j][col-1]){
                    SwapI(mat2[i][0],mat2[j][0]);
                    SwapC(mat[i][0],mat[j][0]);
                }
            }
            if (ord == 1){ //ordena de manera ascendente
                if (mat2[i][col - 1] < mat2[j][col - 1])
                {
                    SwapI(mat2[i], mat2[j]);
                    SwapC(mat[i], mat[j]);
                }
            }
        }
    }

}


void SwapI(int ele1[F][C],int ele2[F][C]){
    int i ;
    int aux[F][C]={0};
    for (i=0;i<F && ele1[F][i]!= 100;i++){
        aux[F][i]=ele1[F][i];
        printf("%d",aux[F][i]);
        ele1[F][i]=ele2[F][i];
        ele2[F][i]=aux[F][i];
    }
}



void SwapC(char ele1[F], char ele2[F]){
    int i;
    char aux[F]={0};
    for (i=0;i<F && ele1[i]!= '\0';i++){
        strcpy(aux[i],ele1[i]);
        strcpy(ele1[i],ele2[i]);
        strcpy(ele2[i],aux[i]);
    }
    

}

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

void strcpy(char arregloCopia[], char arreglo[])
{
    int i;

    for (i = 0; arreglo[i] != '\0'; i++)
    {
        arregloCopia[i] = arreglo[i];
    }

    arregloCopia[i] = '\0';
}