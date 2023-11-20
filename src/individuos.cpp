#include "individuos.h"

bool dentroDaPrisao(Individuo *ind, float raioMenor, float raioMaior){
    float distanciaDoCentro = sqrt(ind->x * ind->x + ind->y * ind->y);
    return distanciaDoCentro > raioMenor && distanciaDoCentro < raioMaior;
}

float avaliarDesempenho(Individuo& ind) {
    // Lógica de avaliação (por exemplo, com base na proximidade ao centro)
    float distanciaDoCentro = sqrt(ind.x * ind.x + ind.y * ind.y);
    return 1.0 / distanciaDoCentro; // Quanto mais próximo ao centro, melhor a pontuação
}

bool pontoDentroDaPrisao(float x, float y, float raioMenor, float raioMaior){
    float distanciaDoCentro = sqrt(x * x + y * y);
    return distanciaDoCentro > raioMenor && distanciaDoCentro < raioMaior;
}
