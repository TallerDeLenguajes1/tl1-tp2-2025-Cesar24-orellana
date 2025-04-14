#include <stdio.h>
#include <stdlib.h>
#define N 20

int main() {
    int i;
    double vt[N];
    double *pvt = vt;
    for (i = 0; i < N; i++)
    {
        pvt[i] = 1 + rand() % 100;
        //pvt++;
    }
    for (int j = 0; j < N; j++)
    {
        printf("%.2f   ", *pvt);
        pvt++;
    }
    
}