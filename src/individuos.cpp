#include "individuos.h"

bool dentroDaPrisao(Individuo *ind, float raioMenor, float raioMaior){
    float distanciaDoCentro = sqrt(ind->x * ind->x + ind->y * ind->y);
    return distanciaDoCentro > raioMenor && distanciaDoCentro < raioMaior;
}

bool pontoDentroDaPrisao(float x, float y, float raioMenor, float raioMaior){
    float distanciaDoCentro = sqrt(x * x + y * y);
    return distanciaDoCentro > raioMenor && distanciaDoCentro < raioMaior;
}

// Função para calcular o fitness de um indivíduo
float calcularFitness(Individuo* ind, float raioMenor, float raioMaior) {
    // 1- Componente baseada na posição (região da coroa)
    float fitnessPosicao = 1.0f;

    // Verifica se o indivíduo está dentro da coroa (ajuste os valores conforme necessário)
    if (!dentroDaPrisao(ind, raioMenor, raioMaior)) {
        fitnessPosicao = 0.0f;  // Penaliza indivíduos fora da coroa
    }

    // 2- Componente baseada na taxa de decaimento
    float fitnessDecaimento = ind->taxaDecaimento;

    // Combina os dois componentes (pode ajustar pesos conforme necessário)
    float fitnessFinal = fitnessPosicao * fitnessDecaimento;

    return fitnessFinal;
}
