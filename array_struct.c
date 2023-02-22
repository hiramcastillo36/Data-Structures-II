#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}coordenadas;

typedef struct {
    void *info;
}Estructura;

int main(void) {
    int n=5;
    Estructura *coor=NULL;
    coor=(Estructura *)malloc(n*sizeof(Estructura));
    for(int i=0; i<n; i++){
        (coor+i) -> info = (coordenadas *)malloc(sizeof(coordenadas));
        ((coordenadas*)(coor+i)->info)->x = i+1;
        ((coordenadas*)(coor+i)->info)->y = (i+1)*2;
    }
    for(int i=0; i<n; i++){
        printf("%d %d\n", ((coordenadas*)(coor+i)->info)->x, ((coordenadas*)(coor+i)->info)->y);
        
    }
    for(int i=0; i<n; i++){
        free((coordenadas*)(coor+i)->info);
    }
    free(coor);
}