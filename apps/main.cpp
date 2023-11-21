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
#include <algorithm>

#include "evolucao.h"
#include "individuos.h"
#include "display.h"
#include "functions.h"

#include "defines.h"
#define GENOCIDIO_MENU 1
#define RESET_MENU 2

// --- Variaveis Globais ---

// Definindo o vetor de individuos (populacao)
vector<Individuo> individuos;

// Definindo a cor daquela populacao (detalhe visual)
float corAtualGeracao[3] = {0.0f, 0.0f, 0.1f};

// Geracao atual
int numeroDaGeracao = 1;

// --- Funcoes do OpenGL --- //

void mainMenuHandler(int choice){
    switch(choice){
        case GENOCIDIO_MENU:
            genocidio(individuos, RAIO_MENOR, RAIO_MAIOR, PROB_MORTE);
            break;
        // case RESET_MENU:
        //     initializeIndividuos(individuos);
        //     numeroDaGeracao = 1;
        //     glutPostRedisplay();
        //     break;
    }
}

// Funcoes do menu
void menuInit(){
    glutCreateMenu(mainMenuHandler);
    glutAddMenuEntry("Genocidio", GENOCIDIO_MENU);
    // glutAddMenuEntry("Reset", RESET_MENU);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Funcoes do display
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    glColor3f(0.0, 0.0, 0.0); // Define a cor para preto
    glLineWidth(3.0f);
    // Desenhando as celas
    drawCircle(0.0, 0.0, RAIO_MAIOR, 100); // Desenha o círculo externo
    drawCircle(0.0, 0.0, RAIO_MENOR, 100); // Desenha o círculo interno

    drawDynamicLightBeam();
    // Desenhando a torre central
    glColor3f(0.3, 0.3, 0.3);
    drawFilledCircle(0.0, 0.0, RAIO_TORRE, 100);

    glColor3f(corAtualGeracao[0], corAtualGeracao[1], corAtualGeracao[2]); 
    drawIndividuos(individuos);

    glColor3f(0.0, 0.0, 0.0);  // Defina a cor do texto para branco
    glRasterPos2f(-0.95, 0.9);  // Posição do texto na janela

    // Converta o número da geração para uma string
    string geracaoStr = "Geracao: " + to_string(numeroDaGeracao);

    // Desenhe cada caractere do texto
    drawString(geracaoStr.c_str());

    glutSwapBuffers();
}

void atualizaCorGeracao(){
    corAtualGeracao[0] = static_cast<float>(rand()) / RAND_MAX;
    corAtualGeracao[1] = static_cast<float>(rand()) / RAND_MAX;
    corAtualGeracao[2] = static_cast<float>(rand()) / RAND_MAX; 
}

void timer(int value) {
    // Atualiza a posição dos indivíduos
    for(int i = 0; i < int(individuos.size()); i++){
        moveIndividuo(&individuos[i]);
    }

    if ((value * 1000/60) % TEMPO_GERACAO == 0) {  // A cada 3 segundos

        float probGenocidio = (rand() / (float)RAND_MAX);
    
        if(probGenocidio < PROBABILIDADE_GENOCIDIO)
            genocidio(individuos, RAIO_MENOR, RAIO_MAIOR, PROB_MORTE);
        
        // Reposicao da populacao

        // Ordena a população com base no fitness, ou seja os com maior fitness ficam no inicio do vetor
        sort(individuos.begin(), individuos.end(), [](const Individuo& a, const Individuo& b) {
            return a.fitness > b.fitness;
        }); // Essa funcao pode ser a responsavel pela convergencia nao tao boa

        // Remove os menos adaptados
        int numeroRemovidos = max(0, int(TAM_POPULACAO * TAXA_REMOCAO));
        individuos.resize(TAM_POPULACAO - numeroRemovidos);

        // Apenas gera filhos se a populacao nao estiver cheia
        while (individuos.size() < TAM_POPULACAO) {
            // Seleção dos pais
            int indicePai1 = selecaoTorneio(individuos);
            int indicePai2 = selecaoTorneio(individuos);

            // Crossover
            Individuo pai1 = individuos[indicePai1];
            Individuo pai2 = individuos[indicePai2];
            Individuo filho = crossover(pai1, pai2);

            // Mutação
            mutacao(&filho);

            // Adicionar o filho à população
            individuos.push_back(filho);
        }
        numeroDaGeracao++;

        cout << "Tamanho da populacao: " << individuos.size() << endl;
        cout << "Geracao atual: " << numeroDaGeracao << endl;

        //  Atualiza a cor da geração
        atualizaCorGeracao();
    }

    // Redesenha a tela com os indivíduos em suas novas posições
    glutPostRedisplay(); // Essa funcao marca que a janela precisa ser redesenhada

    glutTimerFunc(1000/60, timer, value + 1); // Essa funcao registra a funcao timer para ser chamada daqui a 1000/60 milissegundos
}

// --- Fim das Funcoes do OpenGL --- //

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

    // Funcao para inicializar o menu
    menuInit();
    // Funcao para inicializar o vetor global de individuos (populacao inicial)
    initializeIndividuos(individuos);

    glutDisplayFunc(display);

    // Define a funcao de animacao
    glutTimerFunc(0, timer, 0);

    // Define a funcao de teclado
    glutKeyboardFunc(keyboard); 
    glutMainLoop();
}