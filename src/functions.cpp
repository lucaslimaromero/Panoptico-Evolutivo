#include "functions.h"

// Esse arquivo contem as funcoes do processamento dos individuos

void initializeIndividuos(vector<Individuo> &individuos) {
    srand(time(0));
    for (int i = 0; i < TAM_POPULACAO; i++) {
        // Cria as coordenadas x e y aleatoriamente
        float x = rand() % WINDOW_WIDTH;
        float y = rand() % WINDOW_HEIGHT;

        // Normaliza as coordenadas x e y para a escala do OpenGL
        x = 2.0f * ((x / WINDOW_WIDTH) - 0.5f);
        y = -2.0f * ((y / WINDOW_HEIGHT) - 0.5f);

        // Cria as velocidades em cada eixo
        float vx = (float)(rand() % 21 - 10) / 10000.0f;  
        float vy = (float)(rand() % 21 - 10) / 10000.0f;
        
        // Criando um fitness
        float fitness = (pontoDentroDaPrisao(x, y, RAIO_MENOR, RAIO_MAIOR)) ? 10.0f: 5.0f;

        // Randomiza o tipo de movimento
        int tipoDeMovimento = rand() % 3 + 1;

        // Randomiza a taxa de decaimento entre 0.99 e 0.999
        float taxaDecaimento = (float)(rand() % 901 + 99) / 1000.0f;

        Individuo novoIndividuo = {x, y, vx, vy, fitness, tipoDeMovimento, taxaDecaimento};   
        // cout << "x: " << x << " y: " << y << endl;
        individuos.push_back(novoIndividuo);
    }
}

void moveTipo2(Individuo *ind, float velocidadeAngular) {
    float novaVx = ind->vx * cos(velocidadeAngular) - ind->vy * sin(velocidadeAngular);
    float novaVy = ind->vx * sin(velocidadeAngular) + ind->vy * cos(velocidadeAngular);
    ind->vx = novaVx;
    ind->vy = novaVy;
}

void moveTipo3(Individuo *ind, float amplitudeZigueZague, float frequenciaZigueZague) {
    float deslocamentoZigueZague = amplitudeZigueZague * sin(frequenciaZigueZague);
    float novaVxZigueZague = ind->vx * cos(deslocamentoZigueZague) - ind->vy * sin(deslocamentoZigueZague);
    float novaVyZigueZague = ind->vx * sin(deslocamentoZigueZague) + ind->vy * cos(deslocamentoZigueZague);
    ind->vx = novaVxZigueZague;
    ind->vy = novaVyZigueZague;
}

void colisaoComParedes(Individuo *ind) {
    float recompensa = 0.0f;
    if (ind->x < -1.0f || ind->x > 1.0f) {
        ind->vx = -ind->vx;
        ind->x = std::max(-1.0f, std::min(1.0f, ind->x)); // Limita a posição às bordas
    }
    if (ind->y < -1.0f || ind->y > 1.0f) {
        ind->vy = -ind->vy;
        ind->y = std::max(-1.0f, std::min(1.0f, ind->y)); // Limita a posição às bordas
    }
}

void colisaoComTorre(Individuo *ind) {
    float distanciaDoCentro = sqrt(ind->x * ind->x + ind->y * ind->y);
    if (distanciaDoCentro < RAIO_TORRE) {
        // Calcula o vetor normalizado da direção do indivíduo
        float direcaoX = ind->x / distanciaDoCentro;
        float direcaoY = ind->y / distanciaDoCentro;

        // Calcula o vetor normalizado da direção da reflexão
        float reflexaoX = ind->vx - 2 * (ind->vx * direcaoX + ind->vy * direcaoY) * direcaoX;
        float reflexaoY = ind->vy - 2 * (ind->vx * direcaoX + ind->vy * direcaoY) * direcaoY;

        // Atualiza a velocidade do indivíduo com o vetor de reflexão
        ind->vx = reflexaoX;
        ind->vy = reflexaoY;
    }
}

void moveIndividuo(Individuo *ind) {
    // Ajuste dinâmico da velocidade com base no fitness

    // Crie uma recompensa inicial
    float recompensa = 0.0f;

    // Verifica se o indivíduo está dentro da coroa
    if (dentroDaPrisao(ind, RAIO_MENOR, RAIO_MAIOR)) {
        recompensa += 1.0f; // Recompensa por estar dentro da coroa
    } else {
        recompensa -= 0.5f; // Penalidade por estar fora da coroa
    }

    switch (ind->tipoDeMovimento) {
        case 2:
            moveTipo2(ind, VELOCIDADE_ANGULAR);
            break;
        case 3:
            moveTipo3(ind, AMPLITUDE_ZIGUEZAGUE, FREQUENCIA_ZIGUEZAGUE);
            break;
        default:
            break;
    }

    ind->vx *= TAXA_DECAIMENTO;
    ind->vy *= TAXA_DECAIMENTO; 
    ind->x += ind->vx;
    ind->y += ind->vy;

    // Verifica se o indivíduo atingiu a parede e inverte a direção se necessário
    colisaoComParedes(ind);
    colisaoComTorre(ind);
    // Atualizar a pontuação com base na recompensa
    ind->fitness += recompensa;

    // Posicao atual do individuo
    //cout << "x: " << ind->x << " y: " << ind->y << endl;
}

// Função para calcular o fitness de um indivíduo
float calcularFitness(Individuo *ind) {
    // 1- Componente baseada na posição (região da coroa)
    float fitnessPosicao = 1.0f;

    // Verifica se o indivíduo está dentro da coroa (ajuste os valores conforme necessário)
    if (!dentroDaPrisao(ind, RAIO_MENOR, RAIO_MAIOR)) {
        fitnessPosicao = 0.0f;  // Penaliza indivíduos fora da coroa
    }

    // 2- Componente baseada na taxa de decaimento
    float fitnessDecaimento = ind->taxaDecaimento;

    // Combina os dois componentes (pode ajustar pesos conforme necessário)
    float fitnessFinal = fitnessPosicao * fitnessDecaimento;

    return fitnessFinal;
}