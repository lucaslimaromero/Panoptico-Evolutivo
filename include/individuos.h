#ifndef INDIVIDUOS_H
#define INDIVIDUOS_H

#include <iostream>
#include <cmath>

typedef struct _individuo{
    float x;
    float y;
    float vx;
    float vy;
    float pontuacao;
} Individuo;

bool dentroDaPrisao(Individuo *ind, float raioMenor, float raioMaior);
float avaliarDesempenho(Individuo& ind);
bool pontoDentroDaPrisao(float x, float y, float raioMenor, float raioMaior);

#endif
