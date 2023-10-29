#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 50
#define CELLS 10
#define CHANCE_OF_DEATH 0.1

// Estrutura para representar um indivíduo
typedef struct {
    int x;
    int y;
    int alive;
} Individual;

void initializePopulation(Individual population[POPULATION_SIZE]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i].x = rand() % CELLS;
        population[i].y = rand() % CELLS;
        population[i].alive = 1;
    }
}

void evolvePopulation(Individual population[POPULATION_SIZE]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        // Verificar se o indivíduo está dentro das células
        if (population[i].x < 0 || population[i].x >= CELLS ||
            population[i].y < 0 || population[i].y >= CELLS) {
            // Aleatoriamente decidir se o indivíduo morre
            if (rand() < CHANCE_OF_DEATH * RAND_MAX) {
                population[i].alive = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Individual population[POPULATION_SIZE];
    
    // Inicializar a população
    initializePopulation(population);

    for (int generation = 0; generation < 100; generation++) {
        evolvePopulation(population);
        printf("Geração %d: %d sobreviventes\n", generation, POPULATION_SIZE);
    }

    return 0;
}
