#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dividir(int dividendo, int divisor);

int main() {
    int dividendo, divisor;
    printf("Division 2do Programa ");
    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);
    printf("Ingrese el divisor: ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Error: Division por cero no permitida.\n");
    } else {
        printf("El cociente es: %d\n", dividir(dividendo, divisor));
    }

    return 0;
}

int dividir(int dividendo, int divisor) {
    // Manejo de caso especial de desbordamiento
    if (dividendo == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determinar el signo del resultado
    int signo = (dividendo < 0) ^ (divisor < 0) ? -1 : 1;

    // Convertir a valores positivos usando long long para evitar desbordamientos
    long long num = dividendo;
    long long den = divisor;

    if (num < 0) num = -num;
    if (den < 0) den = -den;

    long long cociente = 0;

    // Algoritmo de división usando restas sucesivas optimizadas
    while (num >= den) {
        long long temp = den, multiplo = 1;
        while (num >= (temp << 1) && (temp << 1) > temp) {
            temp <<= 1;
            multiplo <<= 1;
        }
        num -= temp;
        cociente += multiplo;
    }

    return signo * (int)cociente;
}

