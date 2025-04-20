#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct
{
    int velocidad;       //Velocidad del procesador en GHz (valor entre 1 y 3)
    int anio;             //Año de fabricacion (valor entre 2015 y 2024)
    int cantidad_nucleos;  //Cantidad de nucleos (valor entre 1 y 8)
    char *tipo_cpu;      //Tipo de procesador(apuntador a cadena de caracteres)
}Tcompu;

Tcompu *GenerarPCs(Tcompu pc[], int cantidad);
void TipodeProcesador(char *Atipo, int *tipo);
void ListarPCs(Tcompu pc[], int cant);
void LiberarMemoria(Tcompu pc[], int cant);

int main(){
    srand(time(NULL));
    Tcompu pcs[5];
    int cantidad = 5;
    GenerarPCs(pcs, cantidad);
    ListarPCs(pcs, cantidad);

    LiberarMemoria(pcs, cantidad);
    return 0;
}

Tcompu *GenerarPCs(Tcompu pc[], int cant) {
    int n = 10;
    for (int i = 0; i < cant; i++)
    {
        pc[i].velocidad = 1 + rand() %3;
        pc[i].anio = 2015 + rand() %10; // Para un rango entre 2015 a 2024
        pc[i].cantidad_nucleos = 1 + rand() %8;
        int tipo;
        char Atipos[n];    // Arreglo de tipo
        TipodeProcesador(Atipos, &tipo);
        pc[i].tipo_cpu = (char *)malloc(strlen(Atipos)*sizeof(char) +1); // En los parentesis coloque char por que Tcompu, me daba una advertencia, y demoraba mas de compilar
        strcpy(pc[i].tipo_cpu , Atipos);
    }
    return pc;
}

void TipodeProcesador(char *Atipo, int *tipo){
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
        "Pentium"};
    *tipo = rand()% 6;
    strcpy(Atipo, tipos[*tipo]);
}

void ListarPCs(Tcompu pc[], int cant){
    printf("Lista de PCs:\n");

    for (int i = 0; i < cant; i++)
    {
        printf("PC Numero:%d\n",(i+1));
        printf("Velocidad del procesador: %d\n", pc[i].velocidad);
        printf("Anio de fabricacion: %d\n", pc[i].anio);
        printf("Cantidad de nucleos del procesador: %d\n",pc[i].cantidad_nucleos);
        printf("Tipo de procesador: %s\n", pc[i].tipo_cpu);
        printf("\n");
    }
    
}



void LiberarMemoria(Tcompu pc[], int cant){
    for (int i = 0; i < cant; i++)
    {
        free(pc[i].tipo_cpu);
    }
    
}