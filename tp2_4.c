#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int velocidad;       //Velocidad del procesador en GHz (valor entre 1 y 3)
    int anio;             //Año de fabricacion (valor entre 2015 y 2024)
    int cantidad_nucleos;  //Cantidad de nucleos (valor entre 1 y 8)
    char *tipo_cpu;      //Tipo de procesador(apuntador a cadena de caracteres)
}Tcompu;

Tcompu *GenerarPCs(Tcompu pc[], int cantidad);
char TipodeProcesador(int *tipo);

int main(){
    Tcompu pcs[5];
    int cantidad = 5;
    GenerarPCs(pcs, cantidad);

    free(pcs);
    return 0;
}

Tcompu *GenerarPCs(Tcompu pc[], int cant) {
    for (int i = 0; i < cant; i++)
    {
        pc[i].velocidad = 1 + rand() %3;
        pc[i].anio = 2015 + rand() %2024;
        pc[i].cantidad_nucleos = 1 + rand() %8;
        int tipo;
        char tipos[10] = TipodeProcesador(&tipo);
        pc[i].tipo_cpu = (Tcompu *)malloc(tipo*sizeof(Tcompu) +1);
        strcpy(pc[i].tipo_cpu , tipos);
    }
    
}

char TipodeProcesador(int *tipo){
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
        "Pentium"};
    tipo = 0 + rand()% 5;
    return tipos[*tipo];
}