#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
}Tipo1;

typedef struct {
    void *tipo;
}Prueba;

void no_se(Prueba *ejemplo){
    ejemplo->tipo = malloc(sizeof (Tipo1));
    ((Tipo1*)ejemplo->tipo)->x=5;
    printf("%d", ((Tipo1*)ejemplo->tipo)->x);
}

int main(void){
    Prueba aux;
    Prueba ejemplo;
    
    //no_se(&ejemplo);
    (&ejemplo)->tipo = malloc(sizeof (Tipo1));
    ((Tipo1*)(&ejemplo)->tipo)->x=5;
    printf("%d", ((Tipo1*)(&ejemplo)->tipo)->x);
    printf("%p", &ejemplo);
    free((&ejemplo)->tipo);
    int **matriz;
    int n=5, m=7;
    matriz = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        *(matriz+i) = (int *)malloc(m*sizeof(int));
        for(int j=0; j<m; j++){
            *(*(matriz+i)+j) = 5;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d", *(*(matriz + i)+j));
        }
        printf("\n");
    }
}