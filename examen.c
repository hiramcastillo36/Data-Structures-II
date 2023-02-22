#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nd;
    float *nums;
}datos;

float obtener_prom(int n, datos *ptr){
    float prom=0;
    float total_nums = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<(ptr+i)->nd; j++){
            prom += *(((ptr+i)->nums)+j);
        }
        total_nums += (ptr+i)->nd;
    }
    return (prom/total_nums);
}

void llenar_datos(int n, datos *ptr){
    for(int i=0; i<n; i++){
        scanf("%d", &(ptr+i)->nd);
        (ptr+i)->nums = (float *)malloc((ptr+i)->nd * sizeof(float));
        for(int j=0; j<((ptr+i)->nd); j++){
            scanf("%f", ((ptr+i)->nums)+j);
        }
        
    }
}

void imprimir_datos(int n, datos *ptr){
    for(int i=0; i<n; i++){
        for(int j=0; j<(ptr+i)->nd; j++){
           printf("%f ", *((ptr+i)->nums)+j);
        }
    }
}

int main(){
    datos *nums;
    nums = (datos *)malloc(3*sizeof(datos));
    llenar_datos(3, nums);
    //imprimir_datos(3, nums);
    printf("%f", obtener_prom(3, nums));
    return 0;
}