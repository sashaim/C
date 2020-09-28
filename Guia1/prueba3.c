/**
01G-arreglo-1d-int
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 0  /** limite inferior para el rango de valores para cargar en el arreglo */
#define SUP 99 /** limite superior para el rango de valores para cargar en el arreglo */

#define TAM 10   /** Tamanio del arreglo*/
#define TERM_I 0 /** Elemento entero (int) para indicar el fin de numeros utiles en el arreglo */

/**
IMPORTANTE:
    Los arreglos de numeros no tienen por definicion un elemento terminador (es decir un elemento que indique
    el finde los elemnentos útiles).
    NOSOTROS, tendremos como convención indicar con un número, que no pertenezca al dominio de datos, el fin
    de los datos útiles del arreglo. Lo llamaremos  dicho número elemento teminador.
    Para el caso definimos la constante TERM_I.
    Es mandatorio que el valor del terminador NO pertenezca al dominio de los datos útiles.
*/

int aleatorio(int inf, int sup);
void cargarArrI(int arr[TAM]);
void imprimirArrI(int arr[TAM]);
void cargarArrIAle(int arr[TAM]);
int largoArrI(int arr[]);
void ordenarArrI(int arr[TAM]);

void caso01();
void caso02();
void caso03();

int main()
{
    srand(time(NULL)); /** Seteo de la semilla del generador de valores aleatorios*/
    printf("\nARREGLOS DE NUMEROS\n");

    printf("\n------------- ----------------\n");
    caso01();

    printf("\n------------- ----------------\n");
    caso02();

    printf("\n-------------  ---------------\n");
    caso03();

    printf("\n-------------  ---------------\n");

    return 0;
}

void caso01()
{

    printf("CASO01: Cargar una arreglo de numeros entero desde el teclado \n");

    int arrI[TAM] = {0}; /** Se define el arreglo nombre y se lo inicializa con 0 en todas sus posiciones */
    cargarArrI(arrI);    /** Carga arreglo desde teclado*/
    printf("\tEl arreglo cargado contiene: -> ");
    printf("\n\t");
    imprimirArrI(arrI); /** Imprime arreglo*/
    printf("\n");
}

void caso02()
{

    printf("CASO02: Cargar una arreglo de numeros enteros \n\t en forma aleatoria y de tamanio aleatorio \n");

    int miArrI[TAM] = {0};
    cargarArrIAle(miArrI);
    printf("\tEl arreglo de largo efectivo (elementos utiles)= %d\n", largoArrI(miArrI));
    printf("\ty de largo total(Tamanio)= %d, contiene:\n\t", TAM);
    imprimirArrI(miArrI);
}

void caso03()
{

    printf("CASO03: Ordenar el contenido de un  arreglo de  numeros \n");
    int arrA[TAM] = {0}; /** arreglo origen inicializado todo en 0 */

    cargarArrIAle(arrA);
    printf("\n\t%-15s: ", "Original");
    imprimirArrI(arrA);
    printf("\n\t%-15s: ", "Ordenado");
    ordenarArrI(arrA);
    imprimirArrI(arrA);

    cargarArrIAle(arrA);
    printf("\n\n\t%-15s: ", "Original");
    imprimirArrI(arrA);
    printf("\n\t%-15s: ", "Ordenado");
    ordenarArrI(arrA);
    imprimirArrI(arrA);
}

void ordenarArrI(int arr[TAM])
{
    int i, j;
    int aux;
    int cantNum = largoArrI(arr); /** cantidad de numeros que contiene el arreglo. Es la longuitud del arreglo*/
    for (i = 0; i < cantNum - 1; i++)
    {
        for (j = i + 1; j < cantNum; j++)
        {
            if (arr[i] > arr[j])
            {
                aux = arr[i]; /** Itercambio */
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void imprimirArrI(int arrI[TAM])
{

    /** El arreglo se imprime recorriendolo con un ciclo*/

    int i;

    for (i = 0; i < TAM && arrI[i] != TERM_I; i++)
    {
        printf("%d - ", arrI[i]);
    }
}

void cargarArrI(int arrI[TAM])
{

    /**Se carga el arreglo de numeros hasta que el usuario ingrese un 0 (cero) desde
         el teclado, que es el valor del elemento terminados TERM_I
         */
    /** Por una cuestion de convención (NUESTRA), le colocamos el valor del número terminador,*/
    /** como elemento terminador indicando el fin de los datos utiles del arreglo.*/

    int i = 0;
    int aux;
    printf("\tIngrese contenido. O Ingrese 0 (Cero) para terminar la carga: \n");

    printf("\t[%d]: ", i);
    if (i < TAM - 1)
        scanf("%d", &aux); /** Leer desde el teclado*/
    while (aux != TERM_I && i < TAM - 1)
    {                  /** hasta que el usuaior ingrese 0 cero (que es TERM_I)*/
                       /** Se debe controlar no pasarse del tamanio TAM*/
        arrI[i] = aux; /** Asignar valor al arreglo en la posición i*/
        i++;           /** cambia posicion del arreglo / i es variable de control */
        printf("\t[%d]: ", i);
        if (i < TAM - 1)
            scanf("%d", &aux); /** Leer desde el teclado*/
    }
    arrI[i] = TERM_I; /** Por una cuestion de convención, le colocamos el valor del número terminador,*/
                      /** como elemento terminador indicando el fin de los datos utiles del arreglo.*/
}

void cargarArrIAle(int arrI[TAM])
{
    /**Carga un arreglo de caracteres con caracteres aleatorios y su tamanio es aleatorio < TAM*/

    int i = 0;
    int aux;
    int cantEle = aleatorio(0, TAM - 2); /** derterminar la cantidad de elementos utiles a cargar*/

    if (i < TAM - 1)
        aux = aleatorio(INF, SUP); /** generar letra aleatoria y guardar en aux*/
    while (i <= cantEle && i < TAM - 1)
    {                  /** i<=cantEle Se controla la cantidad de elemento utiles cargados */
                       /** Se debe controlar no pasasrse del tamanio TAM*/
        arrI[i] = aux; /** Asignar caracter al arreglo arrI en la posición i*/
        i++;           /** cambia posicion del arreglo / es variable de control */
        if (i < TAM - 1)
            aux = aleatorio(INF, SUP); /** generar letra aleatoria y guardar en aux*/
    }
    arrI[i] = TERM_I; /**OJO que es int*/
                      /** Las cadenas de caracteres 'string' siempre contienen el caracter'\0'*/
                      /** como elemento terminador indicando el fin de los datos utiles del arreglo.*/
}
int largoArrI(int arrI[])
{
    /** retorna el largo efectivo (cantidad de numeros) que contiene un arreglo de enteros*/
    int i;
    for (i = 0; i < TAM - 1 && arrI[i] != TERM_I; i++)
        ;
    return i;
}
int aleatorio(int inf, int sup)
{
    /** Genera un numero aleatorio entre inf y sup (ambos extremos incluidos)*/
    return inf + (rand() % (sup - inf + 1));
}
