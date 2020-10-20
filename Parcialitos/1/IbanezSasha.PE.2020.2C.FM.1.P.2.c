/** SECCI�N[0] ---------------- G E N E R A L -------------------------------*/
///////////////////////////////////////////////////////  V E R S I O N   //////
// P R O G R A M A C I � N   E S T R U C T U R A D A //  20200427 19:30  //////
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[1]----- D A T O S   E S T U D I A N T E --------- */
/** ------ C O M P L E T A R    O B L I G A T O R I O ------ */
///////////////////////////////////////////////////////////////////////////////
// FECHA        :  28 / 09 / 2020
// COMISI�N     :	FM
// EXAMEN Nro   :
// EXAMEN [P|R] :
// TEMA Nro     :  3
// APELLIDO     : Ibanez Musielack	
// NOMBRE       : Sasha
// LEGAJO       : 151622227	
// DNI          : 40384833
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 25
#define C 25

void cargarArchivo(char mat[F][C], char nom[F]);
void imprimirMat(char mat[F][C]);
void ordenarMat(char mat[F][C]);


int main(){

    char mat[F][C]={0};
    char nom[F]="inscriptos.txt";
    cargarArchivo(mat,nom);
    printf("Matriz: \n");
    imprimirMat(mat);
    ordenarMat(mat);
    printf("\nMatriz ordenada : \n");
    imprimirMat(mat);

    return 0;
}

void cargarArchivo(char mat[F][C], char nom[F]){
    FILE *arch;
    arch = fopen(nom, "r");
    char letra;
    int f, c;

    letra = fgetc(arch);
    for (f = 0; f < F && letra != EOF && letra != 10; f++){
        for (c = 0; c < C && letra != 10; c++){

            mat[f][c] = letra;
            letra = fgetc(arch);
        }
        mat[f][c] = '\0';
        letra = fgetc(arch);
    }
    mat[f][0] = '\0';
    fclose(arch);
}

void imprimirMat(char mat[F][C]){
    int f,c;
    for(f=0;f<F && mat[f][0]!= '\0';f++){
        for(c=0;c<C && mat[f][c]!= '\0'; c++){
            printf("%c",mat[f][c]);
        }
        printf("\n");
    }

}

void ordenarMat(char mat[F][C]){
    int f,c;
    char aux[F]={0};
    for(f=0;f<F && mat[f][0]!= '\0'; f++){
        for(c=0;c<C && mat[c][0]!='\0';c++){
            if (strcmp(mat[f],mat[c])<0){
                strcpy(aux,mat[f]);
                strcpy(mat[f],mat[c]);
                strcpy(mat[c],aux);

            }
        }
    }
}