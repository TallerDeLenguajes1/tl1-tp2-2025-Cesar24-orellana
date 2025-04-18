#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7

int main()
{
    int i, j;
    int mt[N][M];
    int *pmt = &mt[0][0]; // El puntero siempre apunta al primer elemento
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            mt[i][j] = 1 + rand() % 100;
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d  ", *(pmt + i * M + j)); // i*M calcula el desplazamiento de memoria a la fila i, j calcula el desplazamiento dentro de la fila i para llegar a la columna j
        }
        printf("\n");
    }
    return 0;
}