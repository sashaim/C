#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct puntos
{
    float x ,y ;
};
typedef struct puntos t_punto;

double sacarNorma(t_punto p);
void distacia(t_punto p1 ,t_punto p2);
int main(){
    t_punto p1;
    t_punto p2;
    printf("Cordenada x del p1 : ");
    scanf("%f",&p1.x);
    printf("Cordenada y del p1 : ");
    scanf("%f",&p1.y);
    printf("Cordenada x del p2 : ");
    scanf("%f", &p2.x);
    printf("Cordenada y del p2 : ");
    scanf("%f", &p2.y);
    distacia(p1,p2);
    printf("\n");

    return 0;
}

double sacarNorma(t_punto p){
    double norma;
    norma = sqrt(pow(p.x,2)+pow(p.y,2));
    return norma;
}
void distacia(t_punto p1 ,t_punto p2){
    double norma1,norma2;
    norma1 = sacarNorma(p1);
    norma2 = sacarNorma(p2);
    if (norma1 > norma2){
        printf("El p1 es el mas lejano");
    }
    else if (norma1< norma2){
        printf("El p2 es el mas lejano");
    }
    else{
        printf("Estan a la misma distancia");
    }

}