#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int dividePlayers(int* skill, int skillSize) {
    qsort(skill, skillSize, sizeof(int), compare);
    int n = skillSize;
    int total_chemistry = 0;
    int team_sum = skill[0] + skill[n - 1]; // Expected sum for all teams
    
    for (int i = 0; i < n / 2; i++) {
        if (skill[i] + skill[n - 1 - i] != team_sum) {
            return -1; // Not possible to form teams with equal total skill
        }
        total_chemistry += skill[i] * skill[n - 1 - i];
    }
    
    return total_chemistry;
}

int main() {
    int n;
    printf("Ingrese la cantidad de jugadores (debe ser un numero par): ");
    scanf("%d", &n);
    
    if (n % 2 != 0) {
        printf("La cantidad de jugadores debe ser un numero par.\n");
        return 1;
    }
    
    int *skill = (int*)malloc(n * sizeof(int));
    if (skill == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    
    printf("Ingrese las habilidades de los jugadores: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &skill[i]);
    }
    
    int result = dividePlayers(skill, n);
    printf("Resultado: %d\n", result);
    
    free(skill);
    return 0;
}

