#include <stdio.h>
#include <stdlib.h> // Para malloc y free

// Declaraciones de funciones (prototipos)
int max(int a, int b);
int min(int a, int b);
int trap(int* height, int n);

int main() {
    int n; // N�mero de elementos
    int* height; // Puntero para el array de alturas
    
    printf("Practica de laboratorio num 9\n");
    printf("Bienvenido al calculador de agua atrapada.\n");
    printf("Ingrese el numero de barras (n): ");
    // Validar que n sea un entero positivo
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Ingrese un numero de barras valido (entero positivo).\n");
        return 1; // Salir con c�digo de error
    }

    // Asignar memoria din�micamente para el array de alturas
    height = (int*)malloc(n * sizeof(int));

    // Verificar si la asignaci�n de memoria fue exitosa
    if (height == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para las alturas.\n");
        return 1; // Salir con c�digo de error
    }

    printf("Ingrese las alturas de las %d barras, separadas por espacios o saltos de linea:\n", n);
    for (int i = 0; i < n; i++) {
        // Validar que cada altura sea un entero no negativo
        if (scanf("%d", &height[i]) != 1 || height[i] < 0) {
            printf("Error: Ingrese alturas validas (enteros no negativos).");
            free(height); // Liberar memoria antes de salir
            return 1; // Salir con c�digo de error
        }
    }

    // Calcular y mostrar el resultado
    int result = trap(height, n);
    printf("\nLa cantidad total de agua atrapada es: %d\n", result);

    // Liberar la memoria asignada para el array de alturas
    free(height);

    return 0;
}

// Definiciones de funciones

// Funci�n para encontrar el m�ximo de dos enteros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Funci�n para encontrar el m�nimo de dos enteros
int min(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * @brief Calcula la cantidad de agua que se puede atrapar en un mapa de elevaci�n.
 *
 * Esta funci�n toma un array de enteros que representan las alturas de un mapa de elevaci�n
 * y calcula la cantidad total de agua que se puede atrapar despu�s de llover.
 *
 * @param height El array de enteros que representa las alturas de las barras.
 * @param n El n�mero de elementos en el array height.
 * @return La cantidad total de agua atrapada.
 */
int trap(int* height, int n) {
    if (n <= 2) { // No se puede atrapar agua con 0, 1 o 2 barras
        return 0;
    }

    int water_trapped = 0;

    // Crear dos arrays para almacenar la altura m�xima a la izquierda y a la derecha de cada barra
    int* left_max = (int*)malloc(n * sizeof(int));
    int* right_max = (int*)malloc(n * sizeof(int));

    // Verificar si la asignaci�n de memoria fue exitosa
    if (left_max == NULL || right_max == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para los arrays auxiliares.\n");
        // Intentar liberar la memoria que s� se pudo asignar (si la hubiera)
        if (left_max != NULL) free(left_max);
        if (right_max != NULL) free(right_max);
        return 0; // Devolver 0 o un c�digo de error espec�fico si es necesario
    }

    // Calcular la altura m�xima a la izquierda para cada posici�n
    left_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // Calcular la altura m�xima a la derecha para cada posici�n
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // Calcular el agua atrapada en cada posici�n
    for (int i = 0; i < n; i++) {
        // El agua atrapada en la posici�n 'i' es el m�nimo de la altura m�xima izquierda
        // y la altura m�xima derecha, menos la altura actual de la barra.
        water_trapped += min(left_max[i], right_max[i]) - height[i];
    }

    // Liberar la memoria asignada din�micamente
    free(left_max);
    free(right_max);

    return water_trapped;
}
