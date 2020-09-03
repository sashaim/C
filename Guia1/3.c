#include <stdlib.h>
#include <stdio.h>
#define N 100
void leer(char text[N]);
void reemplazar(char text[N],char l1 , char l2);

int main(){
    char text[N];
    char l1 , l2;
    int i;
    leer(text);
    //printf("%s \n",text);
    
    printf("ingreasar caracter a reemplazar = ");
    l1=getchar();
    //fflush(stdin);
    getchar();
    printf("ingreasar caracter de remplazo = ");
    l2= getchar();
    reemplazar(text,l1,l2);
    printf("El resultado es : ");
    for(i=0;text[i]!= '\0';i++){
        printf("%c",text[i]);
    }
    printf("\n");
    
    return 0;

}
/*
void imprimir(char text[N]){
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
    }
}
*/
void leer(char text[N]){
    char c;
    int i = 0;
    printf("ingresar texto: ");
    c = getchar();
    while( c != 10){  // == '\r'
        text[i]=c;
        i++;
        c = getchar();
    }
    text[i]='\0';

}
void reemplazar(char text[N], char l1, char l2){
    int i = 0;
    while (text[i] != '\0'){
        if (text[i] == l1){
            text[i] = l2;
        }
        i ++;
    }
}
