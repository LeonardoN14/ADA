#include <stdio.h>#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMBINATIONS 1000  // M�ximo de combinaciones
#define MAX_LENGTH 10          // M�ximo de caracteres en la entrada

// Mapeo de d�gitos a letras
const char *mapping[] = {
    "",    "",    "abc",  "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

// Funci�n recursiva para generar combinaciones
void backtrack(const char *digits, int index, char *current, char **result, int *count) {
    if (digits[index] == '\0') {  // Si llegamos al final de la cadena
        current[index] = '\0';   // Agregar terminador de cadena
        result[*count] = strdup(current);  // Guardar combinaci�n actual
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    if (digit < 2 || digit > 9) return;  // Validar que sea entre 2 y 9

    const char *letters = mapping[digit];  // Obtener letras del d�gito actual
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];  // Agregar letra actual
        backtrack(digits, index + 1, current, result, count);
    }
}

// Funci�n para obtener combinaciones de letras a partir de d�gitos
char **letterCombinations(const char *digits, int *returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') return NULL;  // Si la entrada est� vac�a, retorna NULL

    char **result = (char **)malloc(MAX_COMBINATIONS * sizeof(char *));
    char current[MAX_LENGTH];  // Almacena la combinaci�n actual

    backtrack(digits, 0, current, result, returnSize);

    return result;
}

// Funci�n principal
int main() {
    char digits[MAX_LENGTH];
    
    printf("Ingrese los d�gitos (2-9): ");
    scanf("%s", digits);

    // Validar que solo contenga caracteres entre '2' y '9'
    for (int i = 0; digits[i] != '\0'; i++) {
        if (digits[i] < '2' || digits[i] > '9') {
            printf("Error: Solo se permiten d�gitos entre 2 y 9.\n");
            return 1;  // Terminar con c�digo de error
        }
    }

    int returnSize;
    char **combinations = letterCombinations(digits, &returnSize);

    printf("Combinaciones posibles:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", combinations[i]);
        free(combinations[i]);  // Liberar memoria de cada combinaci�n
    }
    printf("\n");

    free(combinations);  // Liberar memoria del array principal

    return 0;
}

