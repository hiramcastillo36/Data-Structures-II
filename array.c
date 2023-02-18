#include <stdlib.h>
#include <stdio.h>

int main(void){
    int *array=NULL;
    int n=3;
    array = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", (array+i));
    }
    for(int i=0; i<n; i++){
        printf("%d ", *(array+i));
    }   
    free(array);
    return 0;
}