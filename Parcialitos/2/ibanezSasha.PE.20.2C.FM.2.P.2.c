/** SECCI�N[0] ---------------- G E N E R A L -------------------------------*/
///////////////////////////////////////////////////////  V E R S I O N   //////
// P R O G R A M A C I � N   E S T R U C T U R A D A //  20200427 19:30  //////
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[1]----- D A T O S   E S T U D I A N T E --------- */
/** ------ C O M P L E T A R    O B L I G A T O R I O ------ */
///////////////////////////////////////////////////////////////////////////////
// FECHA        :  19 / 10 / 2020
// COMISI�N     :   FM
// EXAMEN Nro   :   2
// EXAMEN [P|R] :   P
// TEMA Nro     :   2
// APELLIDO     : Ibanez Musielack
// NOMBRE       : Sasha
// LEGAJO       :  15-162222-7
// DNI          :  40384833
//
// COMENTARIOS o OBSERVACIONES del estudiante:
// <Usar si desea comunicar algo al profesor corrector>
//
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[2] ---- N O M B R E   D E L   A R C H I V O ------ */
///////////////////////////////////////////////////////////////////////////////
// �Como confeccionar el nombre del archivo ?
// [Apellido].PE.[Anio].[Cuatrimestre].[Comisi�n][NroExamen][TipoExamen][NroTema].c
//
// [Apellido]    -> REEMPLAZAR por tu apellido y nombre, con
//                  la forma apellidoNombre.
//  PE           -> NO se reemplaza, signifa Programaci�n Estructurada.
// [Anio]        -> REEMPLAZAR con dos d�gitos del a�o actual. Ej: 20
// [Cuatrimestre]-> REEMPLAZAR con un d�gito 1 =  1� Cuatr | 2 = 2� Cuatr.
// [Comisi�n]    -> REEMPLAZAR por las dos letras de su comisi�n Ejemplo: BM.
// [NroExamen]   -> REEMPLAZAR por el n�mero (entero) de examen ej: 1.
// [TipoExamen]  -> REEMPLAZAR con P  = Parcial | R = Recuperatorio |
//                  E = Extraordinario.
// [NroTema]     -> REEMPLAZAR por en n�mero(entero) de tema ej: 2.
//  c            -> NO se reemplaza, es la extensi�n del archivo.
//
//
// Un ejemplo del "nombre de un archivo" podria ser:
//
//     Ej ->   alvarezMartin.PE.20.1C.BM.1.P.2.c
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[3]--- E N V � O   D E L   A R C H I V O --------- */
///////////////////////////////////////////////////////////////////////////////
// El archivo .c con la soluci�n deber� ser entregado
// a trav�s de la plataforma EVA UCA
// Dentro de la pagina de la materia en EVA, IR a la
// solapa EVALUACIONES o bien copiar el siguiente link
//
// https://eva.uca.edu.ar/course/view.php?id=1360&section=4
//
// Ah� podr�n encontrar una tarea de entrega de parcialito
// Deber�n hacer click sobre ella y se abrir� una ventana
// donde aparecer� el bot�n 'Agregar Entrega'  en el cual deber�n hacer click
// sobre �l para desplegar una nueva ventana donde podr�n realizar la carga del
// archivo
//
// IMPORTANTE: La tarea ser� abierta pasados los 15 minutos
// del horario del comiezo de la clase y estar� disponible 90 minuto
// Ejemplo: Si tu clase es de 7:45 a 10:15 => la tarea se
//          abrir� a las 8:00 y se cerrar� 9:30
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[4]----- P A R A   E L   P R O F E S O R --------- */
///////////////////////////////////////////////////////////////////////////////
// COMENTARIOS o OBSERVACIONES del PROFESOR:
// <Reservado para uso del profesor>
//
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[5]-- S O L U C I � N   A  L A  C O N S I G N A --*/
// ||||| ///////////////////////////////////////////////////////// ||||| //////
// |||||  ESCRIBA su c�digo de la Soluci�n a partir de AQUI ABAJO  ||||| //////
// vvvvv ///////////////////////////////////////////////////////// vvvvv //////

//ibanezSasha.PE.20.2C.FM.2.P.2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 20

typedef struct{
    char *texto;
    int  anio, mes;
} t_emp;

int darMes(unsigned int num);
int darAnio(unsigned int num);
void cargar(t_emp datos[N], char *nomArch);
void imprimir(t_emp datos[N]);

int main(){
    int j;
    t_emp datos[N];
    cargar(datos, "empleados.txt");
    imprimir(datos);

    return 0;
}

void cargar(t_emp datos[N], char *nomArch){
    int i = 0, k = 0;
    unsigned int num = 0;
    char *nombre = NULL;
    char c;

    FILE *arch;
    arch = fopen(nomArch, "r");

    c = fgetc(arch);
    while (c != EOF){
        nombre = malloc(sizeof(char));
        while (c != ','){
            *(nombre + i) = c;
            i++;
            nombre = realloc(nombre, (i + 1) * sizeof(char));
            c = fgetc(arch);
        }
        *(nombre + i) = '\0';
        datos[k].texto = nombre;
        fscanf(arch, "%d\n", &num);
        datos[k].mes = darMes(num);
        datos[k].anio = darAnio(num);

        c = fgetc(arch);
        i = 0;
        k++;
    }
    datos[k].texto = NULL;
    fclose(arch);
}

int darMes(unsigned int num){
    unsigned int mask;
    mask = pow(2, 4) - 1;
    return (num)&mask;
}
int darAnio(unsigned int num){
    unsigned int mask;
    mask = pow(2, 12) - 1;
    return (num >> 4) & mask;
}


void imprimir(t_emp datos[N]){
    int i;
    for (i = 0; datos[i].texto != NULL; i++)  {
        printf("%d/%d: %s\n", datos[i].mes, datos[i].anio, datos[i].texto);
    }
}