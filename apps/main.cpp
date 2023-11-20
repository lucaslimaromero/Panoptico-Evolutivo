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

#include "individuos.h"
#include "display.h"
#include "functions.h"

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900
#define TAM_POPULACAO 100
#define VELOCIDADE_BASE 0.5f

#define RAIO_MENOR 0.55
#define RAIO_MAIOR 0.7
#define RAIO_TORRE 0.12
#define PROB_MORTE 0.1

using namespace std;

// Definindo o vetor de individuos (populacao)
vector<Individuo> individuos;

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

    
    drawIndividuos(individuos);
    // cout << "Tamanho da populacao: " << individuos.size() << endl;

    // glColor3f(0.0f, 0.0f, 0.0f);  // Defina a cor do texto para branco
    // glRasterPos2f(0.01, 0.9);  // Substitua x e y pela posição onde você deseja desenhar o texto
    // drawString("Genocidio acontecendo");

    glutSwapBuffers();
    // glFlush(); // Força a execução dos comandos OpenGL
}

// Funcoes do sistema evolutivo
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

void timer(int value) {
    // Atualiza a posição dos indivíduos
    for(int i = 0; i < int(individuos.size()); i++){
        moveIndividuo(&individuos[i]);
    }

    if ((value * 1000/60) % 100 == 0) {  // A cada 3 segundos
        genocide(RAIO_MENOR, RAIO_MAIOR, PROB_MORTE);
        // Reposicao da populacao 
    }

    // Redesenha a tela com os indivíduos em suas novas posições
    glutPostRedisplay(); // Essa funcao marca que a janela precisa ser redesenhada

    glutTimerFunc(1000/60, timer, value + 1); // Essa funcao registra a funcao timer para ser chamada daqui a 1000/60 milissegundos
}

int main(int argc, char** argv){

    srand(42);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Panoptico Evolutivo");

    // Funcao para inicializar parametros
    init();
    initializeIndividuos(individuos);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0); // Define a funcao de animacao
    glutKeyboardFunc(keyboard); // Define a funcao de teclado
    glutMainLoop();
}