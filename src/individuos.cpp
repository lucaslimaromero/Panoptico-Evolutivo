#include "individuos.h"

#define windowWidth 900
#define windowHeight 900

bool dentroDaPrisao(Individuo *ind, float raioMenor, float raioMaior){
    float distanciaDoCentro = sqrt(ind->x * ind->x + ind->y * ind->y);
    return distanciaDoCentro > raioMenor && distanciaDoCentro < raioMaior;
}

