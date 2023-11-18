#include "individuos.h"

bool dentroDaPrisao(Individuo *ind, float raioMenor, float raioMaior){
    float distanciaDoCentro = sqrt(ind->x * ind->x + ind->y * ind->y);
    return distanciaDoCentro > raioMenor && distanciaDoCentro < raioMaior;
}

