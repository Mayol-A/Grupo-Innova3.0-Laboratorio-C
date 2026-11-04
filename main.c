#include <stdio.h>
#include <stdlib.h>
#include "simulador.h"
#include "validaciones.h"

#define MAX_HISTORIAL 10

int main(void) {
    int opcion;
    ResultadosOrbita historial_resultados[MAX_HISTORIAL];
    ParametrosOrbita historial_parametros[MAX_HISTORIAL];
    int cantidad_simulaciones = 0;

    do {
        printf("\n=============================================\n");
        printf("   SIMULADOR DE ORBITA TERRESTRE BAJA (LEO)  \n");
        printf("=============================================\n");
        printf("1. Ejecutar simulacion con valores Orion (192 km)\n");
        printf("2. Ejecutar simulacion con parametros personalizados\n");
        printf("3. Ver historial de simulaciones realizadas\n");
        printf("4. Salir\n");
        printf("=============================================\n");
        
        opcion = leer_entero("Seleccione una opcion (1-4): ", 1, 4);

        