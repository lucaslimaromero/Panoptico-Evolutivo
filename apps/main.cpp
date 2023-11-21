#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <vector>

#define TEMPO_GERACAO 500

#include "individuos.h"
#include "display.h"
#include "functions.h"

#include "defines.h"

// --- Variaveis Globais ---

// Definindo o vetor de individuos (populacao)
vector<Individuo> individuos;

// Definindo a cor daquela populacao (detalhe visual)
float corAtualGeracao[3] = {0.0f, 0.0f, 0.1f};

// Geracao atual
int numeroDaGeracao = 1;

// Funcoes do sistema evolutivo

// Funcao de mutacao de um individuo
void mutacao(Individuo *ind){
    // Nao havera mudanca das coordenadas x e y

    // Mutacao na velocidade
    if ((rand() / (float)RAND_MAX) < TAXA_MUTACAO) {
        ind->vx += (float)(rand() % 21 - 10) / 10000.0f;
        ind->vy += (float)(rand() % 21 - 10) / 10000.0f;
    }

    // Mutacao no tipo de movimento (1, 2 ou 3)
    if ((rand() / (float)RAND_MAX) < TAXA_MUTACAO) 
        ind->tipoDeMovimento = rand() % 3 + 1;
    

    // Mutacao na taxa de decaimento
    if ((rand() / (float)RAND_MAX) < TAXA_MUTACAO) 
        // Adiciona um valor aleatório entre -0.001 e 0.001 à taxaDecaimento
        ind->taxaDecaimento += ((rand() % 11) / 1000.0f);
    
}

// Vamos implementar a funcao de selecao dos pais
int selecaoTorneio(){
    int tamTorneio = 5; // Tamanho do torneio (quantos individuos participarao)
    int indiceVencedor = rand() % individuos.size(); // A priori, sorteia qualquer um

    for(int i = 0; i < tamTorneio; i++){
        int indiceCandidato = rand() % individuos.size();
        if(individuos[indiceCandidato].fitness > individuos[indiceVencedor].fitness){
            indiceVencedor = indiceCandidato;
        }
    }
    cout << "Indice vencedor: " << indiceVencedor << endl;
    return indiceVencedor;
}

// Genocidio
void genocide(float raioMenor, float raioMaior, float probMorte){
    for (auto it = individuos.begin(); it != individuos.end(); ) {
        if (!dentroDaPrisao(&(*it), raioMenor, raioMaior) && (rand() / (float)RAND_MAX) < probMorte) {
            // Remove o indivíduo do vetor
            it = individuos.erase(it);
        } else {
            ++it;
        }
    }
}

// Funcao de reproducao (crossover)
Individuo crossover(const Individuo& pai1, const Individuo& pai2) {
    Individuo filho;

    // Crossover nas características dos pais (aleatoriamente escolhendo)
    filho.x = (rand() % 2 == 0) ? pai1.x : pai2.x;
    filho.y = (rand() % 2 == 0) ? pai1.y : pai2.y;
    filho.vx = (rand() % 2 == 0) ? pai1.vx : pai2.vx;
    filho.vy = (rand() % 2 == 0) ? pai1.vy : pai2.vy;
    filho.tipoDeMovimento = (rand() % 2 == 0) ? pai1.tipoDeMovimento : pai2.tipoDeMovimento;
    filho.taxaDecaimento = (rand() % 2 == 0) ? pai1.taxaDecaimento : pai2.taxaDecaimento;

    return filho;
}

// --- Funcoes do OpenGL ---

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

 

    glColor3f(0.0, 0.0, 0.0); // Define a cor para preto
    glLineWidth(3.0f);
    // Desenhando as celas
    drawCircle(0.0, 0.0, RAIO_MAIOR, 100); // Desenha o círculo externo
    drawCircle(0.0, 0.0, RAIO_MENOR, 100); // Desenha o círculo interno

    // Desenhando a torre central
    glColor3f(0.3, 0.3, 0.3);
    drawFilledCircle(0.0, 0.0, RAIO_TORRE, 100);

    glColor3f(corAtualGeracao[0], corAtualGeracao[1], corAtualGeracao[2]); // Define a cor para vermelho
    drawIndividuos(individuos);
    // cout << "Tamanho da populacao: " << individuos.size() << endl;

    // glColor3f(0.0f, 0.0f, 0.0f);  // Defina a cor do texto para branco
    // glRasterPos2f(0.01, 0.9);  // Substitua x e y pela posição onde você deseja desenhar o texto
    // drawString("Genocidio acontecendo");

    

    glutSwapBuffers();
    // glFlush(); // Força a execução dos comandos OpenGL
}

void timer(int value) {
    // Atualiza a posição dos indivíduos
    for(int i = 0; i < int(individuos.size()); i++){
        moveIndividuo(&individuos[i]);
    }

    if ((value * 1000/60) % TEMPO_GERACAO == 0) {  // A cada 3 segundos
        genocide(RAIO_MENOR, RAIO_MAIOR, PROB_MORTE);
        // Reposicao da populacao

        // Apenas gera filhos se a populacao nao estiver cheia
        while (individuos.size() < TAM_POPULACAO) {
            // Seleção dos pais
            int indicePai1 = selecaoTorneio();
            int indicePai2 = selecaoTorneio();

            // Crossover
            Individuo pai1 = individuos[indicePai1];
            Individuo pai2 = individuos[indicePai2];
            Individuo filho = crossover(pai1, pai2);

            // Mutação
            mutacao(&filho);

            // Adicionar o filho à população
            individuos.push_back(filho);
            // Printa a quantidade
            cout << "Tamanho da populacao: " << individuos.size() << endl;
        }

        //  Atualiza a cor da geração
        corAtualGeracao[0] = static_cast<float>(rand()) / RAND_MAX;
        corAtualGeracao[1] = static_cast<float>(rand()) / RAND_MAX;
        corAtualGeracao[2] = static_cast<float>(rand()) / RAND_MAX;
    }

    // Redesenha a tela com os indivíduos em suas novas posições
    glutPostRedisplay(); // Essa funcao marca que a janela precisa ser redesenhada

    glutTimerFunc(1000/60, timer, value + 1); // Essa funcao registra a funcao timer para ser chamada daqui a 1000/60 milissegundos
}

int main(int argc, char** argv){

    srand(42);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    // Define o tamanho inicial da janela
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Define a posicao inicial da janela
    glutInitWindowPosition(0, 0);

    // Define o titulo da janela
    glutCreateWindow("Panoptico Evolutivo");

    // Funcao para limpar a tela
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Funcao para inicializar o vetor global de individuos (populacao inicial)
    initializeIndividuos(individuos);

    glutDisplayFunc(display);

    // Define a funcao de animacao
    glutTimerFunc(0, timer, 0);

    // Define a funcao de teclado
    glutKeyboardFunc(keyboard); 
    glutMainLoop();
}