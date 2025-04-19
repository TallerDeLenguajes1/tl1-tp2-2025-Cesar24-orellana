#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct compu 
{
    int velocidad;       //Velocidad del procesador en GHz (valor entre 1 y 3)
    int anio;             //Año de fabricacion (valor entre 2015 y 2024)
    int cantidad_nucleos;  //Cantidad de nucleos (valor entre 1 y 8)
    char *tipo_cpu;      //Tipo de procesador(apuntador a cadena de caracteres)
}Tcompu;

Tcompu *GenerarPCs(Tcompu *pc, int cantidad);
char TipodeProcesador(int *tipo);

int main(){
    Tcompu *pcs;
    pcs = (Tcompu*)malloc(5*sizeof(Tcompu) +1);
    int cantidad = 5;
    GenerarPCs(&pcs, cantidad);

    free(pcs);
    return 0;
}

Tcompu *GenerarPCs(Tcompu *pc, int cant) {
    pc->velocidad = 1 + rand() %3;
    pc->anio = 2015 + rand() %2024;
    pc->cantidad_nucleos = 1 + rand() %8;
    int tipo;
    char Atipo[10] = TipodeProcesador(&tipo);
    pc->tipo_cpu = (Tcompu*)malloc(tipo*sizeof+1);
    strcpy(pc->tipo_cpu,Atipo);
}

char TipodeProcesador(int *tipo){

}