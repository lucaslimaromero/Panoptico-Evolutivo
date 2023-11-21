#ifndef EVOLUCAO_H
#define EVOLUCAO_H

#include <algorithm>
#include <vector>

#include "individuos.h"
#include "defines.h"

void mutacao(Individuo *ind);
int selecaoTorneio(vector<Individuo>& individuos);
void genocidio(vector<Individuo>& individuos, float raioMenor, float raioMaior, float probMorte);
Individuo crossover(const Individuo& pai1, const Individuo& pai2);
// Função para calcular o fitness de um indivíduo
float calcularFitness(Individuo *ind);

#endif