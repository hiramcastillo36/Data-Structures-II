//
// Created by Hiram Castillo on 17/02/23.
//
/*
 * En una farmacia se venden 2 tipos de medicamentos: genéricos y de patente. Los datos de los tipos genéricos son:
 * el precio, sustancia activa, si requiere receta médica (“s” o “n”), porcentaje de descuento (si no hay se asigna un
 * cero) y precio final. Los datos para los medicamentos de patente son: precio, nombre comercial
 * (por ejemplo “aspirina”), sustancia activa (por ejemplo “ácido acetilsalicílico”), laboratorio (por ejemplo “Bayer”)
 * y si requiere receta médica (“s” o “n”).
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum{
    PATENTE,
    GENERICO
} TipoMedicamento;

typedef struct {
    float precio;
    char sustancia_activa[50];
    char receta;
    void *info_extra;
    TipoMedicamento tipo;
}Medicamento;

typedef struct {
    char laboratorio[40];
    char nombre_comercial[40];
}Patente;

typedef struct {
    int porcentaje_descuento;
    float precio_final;
}Generico;

/*
 * Escriba una función para reservar memoria para el arreglo de medicamentos. La función recibe dos parámetros:
 * el tamaño del arreglo y un apuntador por referencia donde se asignará la memoria dinámica para el arreglo.
 */
                    //Tamaño del arreglo, lista de medicamento
void reservar_memoria(int tam, Medicamento **lista_medic){
                        *lista_medic= (Medicamento *) malloc((tam * sizeof (Medicamento)));
}

/*
 * Escribir una función para capturar la información medicamentos genéricos y/o de patente.
 * La función recibe dos parámetros: un apuntador al arreglo de medicamentos y un entero con el tamaño del arreglo.
 * Utilice notación/aritmética de apuntadores para acceder a los elementos del arreglo
 */

void agregar_medicamentos(int tam, Medicamento *lista_medic){
    for(int i=0; i<tam; i++) {
        scanf("%f\n", &(lista_medic+i)->precio);
        scanf("%s\n", (lista_medic+i)->sustancia_activa);
        scanf("%c", &(lista_medic+i)->receta);
    }
}

void imprimir_medicamentos(int tam, Medicamento *lista_medic){
    for(int i=0; i<tam; i++) {
        printf("Precio: %f\n", (lista_medic+i)->precio);
        printf("Sustancia: %s\n", (lista_medic+i)->sustancia_activa);
        printf("Receta: %c\n", (lista_medic+i)->receta);
    }
}

int main(void){
    Medicamento *lista_med;
    int tam_arreglo;
    scanf("%d", &tam_arreglo);
    reservar_memoria(tam_arreglo, &lista_med);
    agregar_medicamentos(tam_arreglo, lista_med);
    imprimir_medicamentos(tam_arreglo, lista_med);
}