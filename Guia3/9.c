#include <stdio.h>
#include <stdlib.h>

char * subcadena(char * p, unsigned int i, int n);
char *leerArch(const char *nomArch);

int main(){
    char *cadena =NULL;
    char *arch= NULL;
    int i=8, n=-7;
    arch=leerArch("frase.txt");
    cadena=subcadena(arch,i,n);

    printf("%s \n",cadena);


    return 0;
}

char * subcadena(char * p , unsigned int i , int n){
    char * sub = NULL;
    sub=(char*)malloc(sizeof(char));
    int pos;
    int len;
    int k,cant;
    char letra;
    if (n<0){
        cant=-n;
    }
    else{
        cant=n;
    }
    for(len=0;*(p+len)!= '\0';len ++);
    if (len>i && n!=0){
        letra=*(p+i);
        for(k=0;k<cant;k++){
            *(sub+k)=letra;
            sub=realloc(sub,sizeof(char)*k);
            if(n<0){
                letra=*(p+i-k);
                printf("%c", letra);
            }
            else{
                letra=*(p+i+k);
                printf("%c",letra);
            }

            
        }
    }
    *(sub+k)='\0';
    printf("%s",sub);
    return sub;

}

char *leerArch(const char *nomArch)
{
    char *str = NULL;
    char caracter = 0;
    int contadorDeLetras = 0;
    FILE *archivoConFrase = fopen(nomArch, "r");

    str = malloc(sizeof(char));

    caracter = fgetc(archivoConFrase);

    while (caracter != EOF)
    {
        *(str + contadorDeLetras) = caracter;

        contadorDeLetras++;
        str = realloc(str, sizeof(char) * (contadorDeLetras + 1));

        caracter = fgetc(archivoConFrase);
    }

    *(str + contadorDeLetras) = '\0';

    fclose(archivoConFrase);

    return str;
}
