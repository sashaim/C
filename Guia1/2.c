#include <stdio.h>
#include <stdlib.h>

int ope(int num1, int num2 , char op);
int main(){
    int num1 ,num2;
    char op;
    printf ("ingrese el primer numero: ");
    scanf("%d",&num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&num2);
    getchar();
    printf("ingrese la operacion (= - / *) ; ");
    op =getchar();
    printf("el resultado es : %d \n",ope(num1,num2,op));
    
    return 0;
}

int ope (int num1,int num2, char op){
    int res;
    // swith case 1
    if (op == '+'){
        res = num1 + num2 ;
    }
    else if (op == '-')
    {
        res = num1 - num2;
    }
    else if (op == '*'){
        res = num1 * num2;
    }
    else if (op == '/'){
        res = num1 / num2;
    }
    return res ;
    
}