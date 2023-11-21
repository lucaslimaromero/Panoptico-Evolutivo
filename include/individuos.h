#ifndef INDIVIDUOS_H
#define INDIVIDUOS_H

#include <iostream>
#include <cmath>

typedef struct _individuo{
    float x; // Posicao x 
    float y; // Posicao y
    float vx; // Velocidade em x
    float vy; // Velocidade em y
    float fitness; // Pontuacao do individuo
    int tipoDeMovimento; // Forma que o individuo se movimenta (1,2 ou 3)
    float taxaDecaimento; // Multiplicador de decaimento velocidade
} Individuo;

// O fitness do individuo sera mensurado com base na posicao dele e na taxa de decaimento
// 1- Posicao dele, pois ele deve estar na regiao da coroa
// 2- Taxa de decaimento, pois os melhores individuos, alem de estarem na posicao certa na hora da avaliacao, devem ter uma tendencia maior ao equilibrio (manterem-se nessa posicao)

bool dentroDaPrisao(Individuo *ind, float raioMenor, float raioMaior);
float calculaFitness(Individuo *ind);
bool pontoDentroDaPrisao(float x, float y, float raioMenor, float raioMaior);


#endif
