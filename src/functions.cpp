#include "functions.h"

// Esse arquivo contem as funcoes do processamento dos individuos

void initializeIndividuos(vector<Individuo> &individuos) {
    for (int i = 0; i < TAM_POPULACAO; i++) {
        float x = rand() % WINDOW_WIDTH;
        float y = rand() % WINDOW_HEIGHT;

        float pontuacao;        

        // Normaliza as coordenadas x e y para a escala do OpenGL
        x = 2.0f * ((x / WINDOW_WIDTH) - 0.5f);
        y = -2.0f * ((y / WINDOW_HEIGHT) - 0.5f);

        pontuacao = (pontoDentroDaPrisao(x,y,RAIO_MENOR, RAIO_MAIOR)) ? 10.0f: 5.0f;
        
        // Use uma velocidade inicial menor
        float vx = (float)(rand() % 21 - 10) / 10000.0f;  
        float vy = (float)(rand() % 21 - 10) / 10000.0f;

        Individuo novoIndividuo = {x, y, vx, vy, pontuacao};
        cout << "x: " << x << " y: " << y << endl;
        individuos.push_back(novoIndividuo);
    }
}

void moveIndividuo(Individuo *ind) {
    // Ajuste dinâmico da velocidade com base no fitness
    // float velocidade = 2*VELOCIDADE_BASE / ind->pontuacao;

    // Crie uma recompensa inicial
    float recompensa = 0.0f;

    // Verifica se o indivíduo está dentro da coroa
    if (dentroDaPrisao(ind, RAIO_MENOR, RAIO_MAIOR)) {
        recompensa += 1.0f; // Recompensa por estar dentro da coroa
    } else {
        recompensa -= 0.1f; // Penalidade por estar fora da coroa
    }

    // Reduza a velocidade do movimento
    ind->x += ind->vx;
    ind->y += ind->vy;

    // Verifica se o indivíduo atingiu a parede e inverte a direção se necessário
    if (ind->x < -1.0f || ind->x > 1.0f) {
        ind->vx = -ind->vx;
        ind->x = std::max(-1.0f, std::min(1.0f, ind->x)); // Limita a posição às bordas
        recompensa -= 0.01f; // Penalidade por colidir com a parede
    }
    if (ind->y < -1.0f || ind->y > 1.0f) {
        ind->vy = -ind->vy;
        ind->y = std::max(-1.0f, std::min(1.0f, ind->y)); // Limita a posição às bordas
        recompensa -= 0.01f; // Penalidade por colidir com a parede
    }

    // Atualizar a pontuação com base na recompensa
    ind->pontuacao += recompensa;

    // Tratando as colisões com a torre central
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

    // Posicao atual do individuo
    //cout << "x: " << ind->x << " y: " << ind->y << endl;
}