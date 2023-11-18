#ifndef INDIVIDUOS_H
#define INDIVIDUOS_H

#include <iostream>
#include <cmath>

typedef struct _individuo{
    float x;
    float y;
    float vx;
    float vy;
} Individuo;

bool dentroDaPrisao(Individuo *ind, float raioMenor, float raioMaior);

#endif
