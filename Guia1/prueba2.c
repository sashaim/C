/**
01G-arreglo-1d-string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#define TAM 20          /** Tamanio de los arreglos*/
#define TAM1 20         /** Tamanio de los arreglos*/
#define TAM2 20         /** Tamanio de los arreglos*/

#define INF 0
#define SUP 99
#define TIPO_MAY 0      /** Valor identificatorio para generar mayusculas*/
#define TIPO_MIN 1      /** Valor identificatorio para generar minusculas*/
#define TIPO_MAY_MIN 2  /** Valor identificatorio para generar mayusculas y/o minusculas*/


int aleatorio(int inf, int sup);
int aleatorioL(int tipo);
void cargarArrC(char arrS[TAM]);
void cargarArrCAle(char arrS[TAM]);
void imprimirArrC(char arrS[TAM]);
int largoArrC(char arr[]);
void ordenarArrC(char arrC[TAM]);
char aMinus(char c);

void caso01();
void caso02();
void caso03();
void caso04();
void caso05();


int main() {
    srand(time(NULL));          /** Seteo de la semilla del generador de valores aleatorios*/
    printf("\nARREGLOS DE CARACTERES\n");

    printf("\n------------- ----------------\n");
    caso01();

    printf("\n------------- ----------------\n");
    caso02();

    printf("\n------------- ----------------\n");
    caso03();

    printf("\n------------- ----------------\n");
    caso04();

    printf("\n------------- ----------------\n");
    caso05();

    printf("\n-------------  ---------------\n");

    return 0;
}

void caso01(){

    printf("CASO01: Cargar una arreglo de caracteres 'string' desde el teclado \n\t");

    char nombre[TAM]={0};              /** Se define el arreglo nombre y se lo inicializa con 0 en todas sus posiciones */
    cargarArrC(nombre);                /** Carga arreglo desde teclado*/
    printf("\n\tEl arreglo cargado contiene: -> ");
    imprimirArrC(nombre);              /** Imprime arreglo de caracteres*/
}

void caso02(){

    printf("CASO02: Cargar una arreglo de caracteres 'string' con caracteres \n\tletra aleatorio y de tamanio aleatorio \n");

    char miArrC[TAM]={0};
    cargarArrCAle(miArrC);
    printf("\n\tEl arreglo de largo efectivo (caracteres utiles)= %d\n",largoArrC(miArrC));
    printf("\ty de largo total(Tamanio)= %d,\n\tcontiene -> ",TAM);
    imprimirArrC(miArrC);
}

void caso03(){

    printf("CASO03: Copiar un arreglo caracteres 'string' a otro arreglo\n");
    printf("\tde caracteres, CON libreria string.h\n");
    printf("\tIMPORTANTE, el tamanio de 'des' debe ser mayor o igual que el tamanio de 'ori'\n");

    char ori[TAM1]={"hola"}; /** arreglo origen inicializado , ori[TAM1]={"hola"} solo cuando se inicializa*/
    char des[TAM2]={0};      /** arreglo origen inicializado todo en 0 */

    printf("\t ANTES de copiar\n");
    printf("\t\t ori = %s, des = %s\n",ori,des);
    strcpy(des,ori);
    printf("\t DESPUES de copiar\n");
    printf("\t\t ori = %s, des = %s\n",ori,des);
    printf("\n\t*Se sugiere desarrollar una rutina propia de copiado de arreglo, \n\t es decir relizar su porpia srtcpy*");
}

void caso04(){

    printf("CASO04: Comparar el contenido de dos  areglos de  caracteres 'string'\n");
    printf("\tCON libreria string.h, con funcion strcmp ()\n");
    printf("\t ( 0): si los arg. son iguales\n");
    printf("\t ( 1): si arg izq mayor que arg. der.\n");
    printf("\t (-1): si arg izq menor que arg. der.\n");
    printf("\t EJEMPLO: \n\n");

    char arrA[TAM1]={0}; /** arreglo origen inicializado todo en 0 */
    char arrB[TAM2]={0}; /** arreglo origen inicializado todo en 0 */

    strcpy(arrA,"hola");
    strcpy(arrB,"hola");
    printf("\t strcmp(\"%s\",\"%s\")     ->  %d\n",arrA,arrB, strcmp(arrA,arrB));

    strcpy(arrA,"holass");
    strcpy(arrB,"hola");
    printf("\t strcmp(\"%s\",\"%s\")   ->  %d\n",arrA,arrB, strcmp(arrA,arrB));

    strcpy(arrA,"hola");
    strcpy(arrB,"holass");
    printf("\t strcmp(\"%s\",\"%s\")   -> %d\n",arrA,arrB, strcmp(arrA,arrB));

    printf("\n\t*Se sugiere desarrollar una rutina propia de comparacion de arreglos, \n\t es decir relizar su porpia strcmp*");
}

void caso05(){

    printf("CASO05: Ordenar el contenido de un  arreglo de  caracteres 'string'\n");
    char arrA[TAM]={0}; /** arreglo origen inicializado todo en 0 */

    printf("\t%-22s","Original");
    printf("%-22s\n\n","Ordenado");

    strcpy(arrA,"Holas");
    printf("\t%-22s ",arrA);
    ordenarArrC(arrA);
    printf("%-22s \n",arrA);

    strcpy(arrA,"321");
    printf("\t%-22s ",arrA);
    ordenarArrC(arrA);
    printf("%-22s \n",arrA);

    strcpy(arrA,"Hola como va");
    printf("\t%-22s ",arrA);
    ordenarArrC(arrA);
    printf("%-22s \n",arrA);
}

void ordenarArrC(char arrC[TAM]){

    int i,j;
    int aux;
    int cantCar = largoArrC(arrC);               /** cantidad de caracteres que contiene el arreglo. Es la longuitud del string*/
    for(i=0;i < cantCar - 1 ; i++) {
        for(j=i+1; j < cantCar ; j++){
                                                /** Si son letras, las comparo con la minuscula a ambos lados de simbolo de comparacion*/
            if (aMinus(arrC[i]) > aMinus(arrC[j])){
                aux = arrC[i];                  /** Itercambio */
                arrC[i] = arrC[j];
                arrC[j] = aux;
            }
        }
    }

}
char aMinus(char c){
    /** Recordar que en tabla ascii la diferencia entre un mayuscula y una minuscula es 32*/
    if (c>='A' && c<='Z')
        return c+32;
    return c;
}

void imprimirArrC(char arrC[TAM]){
    /** El arreglo de carcteres se puede impirmir con una solo linea*/
    printf("%s",arrC);

    /** El arreglo tambien se puede imprimir recorriendolo con un ciclo*/
    /*
    int i;
    printf("\n");
    for (i=0; arrC[i]!='\0';i++){
            printf("%c",arrC[i]);

    }
    printf("\n");
    */
}


void cargarArrC(char arrC[TAM]){
    int i=0;
    char aux;
    printf("Ingrese contenido: ");

    if(i<TAM-1)
        aux=getchar();            /** Leer desde el teclado*/
    while(aux!=10 && i<TAM-1){    /** \\r es la tecla ENTER, no confundir con \\n Que representa una nueva linea*/
                                    /** Se debe controlar no pasasrse del tamanio TAM*/
        arrC[i] = aux;              /** Asignar caracter al arreglo arrC en la posición i*/
        i++;                        /** cambia posicion del arreglo / es variable de control */
        if(i<TAM-1)
            aux=getchar();        /** Leer desde el teclado*/
    }
    arrC[i]='\0';                   /** Las cadenas de caracteres 'string' siempre contienen el caracter'\0'*/
                                    /** como elemento terminador indicando el fin de los datos utiles del arreglo.*/
}

void cargarArrCAle(char arrC[TAM]){
    /**Carga un arreglo de caracteres con caracteres aleatorios y su tamanio es aleatorio < TAM*/

    int i=0;
    char aux;
    int cantCar = aleatorio(0,TAM-2);       /** derterminar la cantidad de caracteres utiles a cargar*/

    if(i<TAM-1)
        aux = aleatorioL(TIPO_MAY_MIN);     /** generar letra aleatoria y guardar en aux*/
    while(i<=cantCar && i<TAM-1){           /**i<=cantCar Se controla la cantidad de caracatreres cargados */
                                            /** Se debe controlar no pasasrse del tamanio TAM*/
        arrC[i] = aux;                      /** Asignar caracter al arreglo arrC en la posición i*/
        i++;                                /** cambia posicion del arreglo / es variable de control */
        if(i<TAM-1)
            aux = aleatorioL(TIPO_MAY_MIN); /** generar letra aleatoria y guardar en aux*/
    }
    arrC[i]='\0';                           /** Las cadenas de caracteres 'string' siempre contienen el caracter'\0'*/
                                            /** como elemento terminador indicando el fin de los datos utiles del arreglo.*/

/*	----------------*/
/*	char aux;*/
/*	aux=64;	aux='@';	*/
/*	printf("%c",aux); -> '@'*/
/*	printf("%d",aux); -> 64*/	
/*	----------------*/
}

int aleatorio(int inf, int sup){
    /** Genera un numero aleatorio entre inf y sup (ambos extremos incluidos)*/
    return inf + (rand() % (sup-inf+1));
}

int aleatorioL(int tipo){

    /** Funcion que Genera una Letra del abecedario.Hay distintos tipo de generacion */
    /**
        TIPO_MAY -> genera mayusculas en forma aleatoria
        TIPO_MIN -> genera minusculas en forma aleatoria
        TIPO_MAY_MIN -> genera mayusculas o minusculas en forma aleatoria
    */
    int res;
    if (tipo==TIPO_MAY){                /**Mayuscula en forma aleatoria*/
        res= aleatorio(65,90);          /**Mayuscula*/
    }
    else if(tipo==TIPO_MIN){            /**minuscula en forma aleatoria*/
        res= aleatorio(97,122);         /**minuscula*/
    }
    else if(tipo==TIPO_MAY_MIN){        /**Mayuscula y/o minuscula en forma aleatoria*/
        if (aleatorio(0,1)==0){         /** 0: genera mayuscula, 1: genera minuscula*/
            res= aleatorio(65,90);      /**Mayuscula*/
        }
        else{
            res= aleatorio(97,122);     /**minuscula*/
        }
    }
    else{
        res=0;
    }
    return res;
}

int largoArrC(char arrC[]){
    /** retorna el largo efectivo (cantidad de caracteres) que contiene un arreglo de caracteres*/
    int i;
    for (i=0; i<TAM-1 && arrC[i]!='\0'; i++);
    return i;
}
