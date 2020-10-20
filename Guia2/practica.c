#include <stdio.h>
#include <stdlib.h>
#define TAM 20



struct s_fecha
{

    unsigned int anio, mes, dia;
};

typedef struct s_fecha t_fecha;

struct sdata
{

    char nom[TAM];

    t_fecha fecha;
};

typedef struct sdata t_data;

void decode(t_fecha *fecha, unsigned int fechabin){
    unsigned int MASK1,MASK2,MASK3;
    MASK1=255;
    MASK2=65535;
    //fechabin 130880522
    fecha->mes=fechabin&MASK1;
    fecha->dia=(fechabin>>8)&MASK1;
    fecha->anio=(fechabin>>16)&MASK2;
}
t_data *cargarArr(char *archivo){
    FILE *arch;
    arch=fopen(archivo,"r");
    t_data *personas[TAM];
    int i,j,k;
    unsigned int binario;
    k=0;
    char nombre[TAM];
    char caracter;
    //nombre=malloc(sizeof(char));
    caracter=fgetc(arch);
    while(caracter!='\0'){
        for(i=0;caracter!=',';i++){ //10
            //*(nombre+i)=caracter;
            nombre[i]=caracter;
            *personas[k]->nom=nombre[i];
            //nombre=realloc(nombre,(i+1)*sizeof(char));
            caracter = fgetc(arch);
        }
        //*personas[k]->nom =nombre;
        /// como se escribe bien esto
        fscanf(arch,"%d",binario);
        decode(&(personas[k]->fecha),binario);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        k++;
        caracter=fgetc(arch);

    }
    *personas[k]->nom='\0';
    return *(personas);
}

// int main(){
//     t_fecha fecha;
//     unsigned int fechabin=130880522;
//     decode(&fecha,fechabin);
//     printf("%d\n",fecha.mes);
//     printf("%d\n",fecha.dia);
//     printf("%d\n",fecha.anio);

// }

int main()
{
    /**NO SE PUEDE CAMBIAR EL C�DIGO DE main*/
    t_data *arr = NULL;
    char nomArch[TAM] = "datos.csv";
    //imprimirArch(nomArch);
    printf("\n");
    arr = cargarArr(nomArch);
    //imprimirArr(arr);
    printf("%s",arr->nom);

    return 0;
}