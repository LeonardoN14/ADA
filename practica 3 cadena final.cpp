#include <stdio.h>#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMBINATIONS 1000  // Máximo de combinaciones
#define MAX_LENGTH 10          // Máximo de caracteres en la entrada

// Mapeo de dígitos a letras
const char *mapping[] = {
    "",    "",    "abc",  "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

// Función recursiva para generar combinaciones
void backtrack(const char *digits, int index, char *current, char **result, int *count) {
    if (digits[index] == '\0') {  // Si llegamos al final de la cadena
        current[index] = '\0';   // Agregar terminador de cadena
        result[*count] = strdup(current);  // Guardar combinación actual
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    if (digit < 2 || digit > 9) return;  // Validar que sea entre 2 y 9

    const char *letters = mapping[digit];  // Obtener letras del dígito actual
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];  // Agregar letra actual
        backtrack(digits, index + 1, current, result, count);
    }
}

// Función para obtener combinaciones de letras a partir de dígitos
char **letterCombinations(const char *digits, int *returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') return NULL;  // Si la entrada está vacía, retorna NULL

    char **result = (char **)malloc(MAX_COMBINATIONS * sizeof(char *));
    char current[MAX_LENGTH];  // Almacena la combinación actual

    backtrack(digits, 0, current, result, returnSize);

    return result;
}

// Función principal
int main() {
    char digits[MAX_LENGTH];
    
    printf("Ingrese los dígitos (2-9): ");
    scanf("%s", digits);

    // Validar que solo contenga caracteres entre '2' y '9'
    for (int i = 0; digits[i] != '\0'; i++) {
        if (digits[i] < '2' || digits[i] > '9') {
            printf("Error: Solo se permiten dígitos entre 2 y 9.\n");
            return 1;  // Terminar con código de error
        }
    }

    int returnSize;
    char **combinations = letterCombinations(digits, &returnSize);

    printf("Combinaciones posibles:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", combinations[i]);
        free(combinations[i]);  // Liberar memoria de cada combinación
    }
    printf("\n");

    free(combinations);  // Liberar memoria del array principal

    return 0;
}

