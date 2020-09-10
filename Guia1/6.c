#include <stdio.h>
#include <stdlib.h>
#define N 100

void cargarText(char txt[N]);
void imprimirText(char txt[N]);
void normalizar(char txt[N]);
int mayus (char c);

void cargarText(char txt[N]){
    int i = 0 ;
    char c;
    c=getchar();
    while (c != '\r' && i< N-1){  // 10 en ascii es '\r'
        txt[i]=c;
        i++;
        c=getchar();
    }
    txt[i]='\0';

}
void imprimirText(char txt[N]){
    int i;
    for(i=0;txt[i]!='\0';i++){
        printf("%c",txt[i]);
    }
}

void normalizar(char txt[N]){
    int i =0;
    int len ;

    for(len= 0; txt[len]!= '\0';len ++);

    if (esMayus(txt[0]) != 1){
        txt[0] = txt[0] - 32; // menos 32 hace mayus . +32 hace minus
    }

    if (txt[len-2]!="."){
        text[len-1]=".";
        text[len]='\0';
    }
    while (txt[i]!='\0'){
        txt[i]

    }
}

int esMayus(char c){
    int mayus = 0 ;
    if (c >= "A" && c <= "Z" ){
        mayus = 1;
    }
    return mayus;
}