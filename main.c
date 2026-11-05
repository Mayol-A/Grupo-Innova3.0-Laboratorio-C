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
        switch (opcion) {
            case 1: {
                ParametrosOrbita p_defecto = {192000.0, 33000.0};
                ResultadosOrbita r_defecto;

                calcular_orbita(&p_defecto, &r_defecto);
                mostrar_resultados(&p_defecto, &r_defecto);

                if (cantidad_simulaciones < MAX_HISTORIAL) {
                    historial_parametros[cantidad_simulaciones] = p_defecto;
                    historial_resultados[cantidad_simulaciones] = r_defecto;
                    cantidad_simulaciones++;
                }
                pausar();
                break;
            }
            case 2: {
                ParametrosOrbita p_custom;
                ResultadosOrbita r_custom;

                printf("\n--- INGRESO DE DATOS PERSONALIZADOS ---\n");
                p_custom.altitud_m = leer_double_positivo("Ingrese la altitud h en metros (> 0): ", 0.0);
                p_custom.masa_nave_kg = leer_double_positivo("Ingrese la masa de la nave en kg (> 0): ", 0.0);

                calcular_orbita(&p_custom, &r_custom);
                mostrar_resultados(&p_custom, &r_custom);

                if (cantidad_simulaciones < MAX_HISTORIAL) {
                    historial_parametros[cantidad_simulaciones] = p_custom;
                    historial_resultados[cantidad_simulaciones] = r_custom;
                    cantidad_simulaciones++;
                }
                pausar();
                break;
            }
            case 3: {
                if (cantidad_simulaciones == 0) {
                    printf("\n[INFO] Aun no se han ejecutado simulaciones en esta sesion.\n");
                } else {
                    printf("\n==================================================\n");
                    printf("             HISTORIAL DE SIMULACIONES            \n");
                    printf("==================================================\n");
                    for (int i = 0; i < cantidad_simulaciones; i++) {
                        printf("[%d] Altitud: %.0f m | Vel: %.2f m/s | Periodo: %.2f min\n",
                               i + 1,
                               historial_parametros[i].altitud_m,
                               historial_resultados[i].v_orbital_ms,
                               historial_resultados[i].periodo_min);
                    }
                }
                pausar();
                break;
            }
            case 4:
                printf("\nSaliendo del simulador... ¡Buen trabajo!\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}
        
