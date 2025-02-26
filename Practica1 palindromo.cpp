#include <stdio.h>
#include <stdbool.h>

bool esPalindromo(int x) {
    if (x < 0) return false; // Los números negativos no son  palíndromos
    
    int original = x, reverso = 0;
    while (x > 0) {
        reverso = reverso * 10 + x % 10;
        x /= 10;
    }
    return original == reverso;
}

int main() {
    int numero;
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);
    
    if (esPalindromo(numero)) {
        printf("%d es un palíndromo.\n", numero);
    } else {
        printf("%d no es un palíndromo.\n", numero);
    }
    
    return 0;
}
