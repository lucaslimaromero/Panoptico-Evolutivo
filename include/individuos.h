#ifndef INDIVIDUOS_H
#define INDIVIDUOS_H

#define windowWidth 900
#define windowHeight 900

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
