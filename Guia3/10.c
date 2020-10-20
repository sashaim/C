#include <stdlib.h>
#include <stdio.h>



struct s_texto{
    char * txt;
    unsigned int longitud;

};
typedef struct s_texto t_texto;



t_texto cargarStrDin1(){
    t_texto estructura;
    estructura.txt=malloc(sizeof(char));
    int cont = 0;
    char caracter = 0;

    caracter = getchar();
    

    while (caracter != 10){
        *(estructura.txt + cont) = caracter;

        cont++;

        estructura.txt = realloc(estructura.txt, (cont + 1) * sizeof(char));

        caracter = getchar();
    }

    *(estructura.txt + cont) = '\0';
    estructura.longitud=cont;
    printf("%s \n",estructura.txt);
    return estructura;
}

void escribirArchText(char *nombre,t_texto estructura){
    FILE *arch;
    arch=fopen(nombre,"w");
    int i;
    char caracter;
    fprintf(arch,"%d,",estructura.longitud);
    for(i=0;*(estructura.txt+i)!='\0';i++){
        caracter=*(estructura.txt+i);
        fputc(caracter,arch);
    }
    fputc('\n',arch);
    fclose(arch);

}

int main(){
    escribirArchText("frases_longitud.csv",cargarStrDin1());

    return 0;
}