#include <stdio.h>
#include <stdbool.h>

bool esPalindromo(int x) {
    if (x < 0) return false; // Los n�meros negativos no son  pal�ndromos
    
    int original = x, reverso = 0;
    while (x > 0) {
        reverso = reverso * 10 + x % 10;
        x /= 10;
    }
    return original == reverso;
}

int main() {
    int numero;
    printf("Ingrese un n�mero entero: ");
    scanf("%d", &numero);
    
    if (esPalindromo(numero)) {
        printf("%d es un pal�ndromo.\n", numero);
    } else {
        printf("%d no es un pal�ndromo.\n", numero);
    }
    
    return 0;
}
