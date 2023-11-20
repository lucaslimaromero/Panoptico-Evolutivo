#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "individuos.h"
#include "display.h"
#include <vector>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900
#define TAM_POPULACAO 100
#define VELOCIDADE_BASE 0.5f

#define RAIO_MENOR 0.55
#define RAIO_MAIOR 0.7
#define RAIO_TORRE 0.12
#define PROB_MORTE 0.1

using namespace std;

// Include any necessary headers
#include <iostream>

// Declare functions, classes, or variables
void initializeIndividuos(vector<Individuo> &individuos);
void moveIndividuo(Individuo *ind);

// Close the include guards
#endif // FUNCTIONS_H

