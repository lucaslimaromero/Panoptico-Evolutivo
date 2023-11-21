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

// void reproducao(float taxaMutacao) {
//     // Avaliação dos indivíduos
//     sort(individuos.begin(), individuos.end(), [](const Individuo &a, const Individuo &b) {
//         return a.pontuacao > b.pontuacao;
//     });

    // Seleção dos pais (usando torneio simples)
//     vector<Individuo> pais;
//     for (int i = 0; i < TAM_POPULACAO / 2; ++i) {
//         int indice1 = rand() % TAM_POPULACAO;
//         int indice2 = rand() % TAM_POPULACAO;
//         pais.push_back((individuos[indice1].pontuacao > individuos[indice2].pontuacao) ? individuos[indice1] : individuos[indice2]);
//     }

//     // Cruzamento e mutação
//     vector<Individuo> descendentes;
//     for (int i = 0; i < pais.size(); i += 2) {
//         Individuo pai1 = pais[i];
//         Individuo pai2 = pais[i + 1];

//         // Operador de crossover (ponto de corte no meio)
//         Individuo filho1 = {pai1.x, pai1.y, (pai1.vx + pai2.vx) / 2, (pai1.vy + pai2.vy) / 2, 1.0};
//         Individuo filho2 = {pai2.x, pai2.y, (pai1.vx + pai2.vx) / 2, (pai1.vy + pai2.vy) / 2, 1.0};

//         // Operador de mutação
//         if ((rand() / (float)RAND_MAX) < taxaMutacao) {
//             filho1.vx += (float)(rand() % 21 - 10) / 10000.0f;
//             filho1.vy += (float)(rand() % 21 - 10) / 10000.0f;
//         }

//         if ((rand() / (float)RAND_MAX) < taxaMutacao) {
//             filho2.vx += (float)(rand() % 21 - 10) / 10000.0f;
//             filho2.vy += (float)(rand() % 21 - 10) / 10000.0f;
//         }

//         descendentes.push_back(filho1);
//         descendentes.push_back(filho2);
//     }

//     // Substituição dos menos adaptados pelos descendentes
//     for (int i = 0; i < descendentes.size(); ++i) {
//         individuos[TAM_POPULACAO - 1 - i] = descendentes[i];
//     }
// }

#endif
