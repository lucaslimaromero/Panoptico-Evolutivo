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

#define windowWidth 900
#define windowHeight 900
#define TAM_POPULACAO 100

#define RAIO_MENOR 0.55
#define RAIO_MAIOR 0.7
#define PROB_MORTE 0.1

vector<Individuo> individuos;

using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    glColor3f(0.0, 0.0, 0.0); // Define a cor para preto
    glLineWidth(3.0f);
    drawCircle(0.0, 0.0, RAIO_MAIOR, 100); // Desenha o círculo externo
    drawCircle(0.0, 0.0, RAIO_MENOR, 100); // Desenha o círculo interno

    // glColor3f(0.0, 0.0, 1.0);
    // glPointSize(3.0f);
    // drawRandomPointsInCrown(0.55, 0.7, 0.0, 0.0, 50); // Desenha os pontos aleatórios

    
    drawIndividuos(individuos);

    glutSwapBuffers();
    // glFlush(); // Força a execução dos comandos OpenGL
}

// Cria alguns indivíduos (100)
void initializeIndividuos() {
    for (int i = 0; i < TAM_POPULACAO; i++) {
        float x = rand() % windowWidth;
        float y = rand() % windowHeight;

        // Normaliza as coordenadas x e y para a escala do OpenGL
        x = 2.0f * ((x / windowWidth) - 0.5f);
        y = - 2.0f * ((y / windowHeight) - 0.5f);
        float vx = (float)(rand() % 21 - 10) / 1000.0f;  // Direção aleatória entre -1 e 1
        float vy = (float)(rand() % 21 - 10) / 1000.0f;  // Direção aleatória entre -1 e 1
        Individuo novoIndividuo = {x, y, vx, vy};
        cout << "x: " << x << " y: " << y << endl;
        individuos.push_back(novoIndividuo);
    }
}

void moveIndividuo(Individuo *ind){
    ind->x += ind->vx;
    ind->y += ind->vy;

    // Verifica se o indivíduo atingiu a parede e inverte a direção se necessário
    if (ind->x < -1.0f || ind->x > 1.0f) {
        ind->vx = -ind->vx;
    }
    if (ind->y < -1.0f || ind->y > 1.0f) {
        ind->vy = -ind->vy;
    }
}

void timer(int) {
    // Atualiza a posição dos indivíduos
    for(int i = 0; i < int(individuos.size()); i++){
        moveIndividuo(&individuos[i]);
    }

    // Redesenha a tela com os indivíduos em suas novas posições
    glutPostRedisplay(); // Essa funcao marca que a janela precisa ser redesenhada

    glutTimerFunc(1000/60, timer, 0); // Essa funcao registra a funcao timer para ser chamada daqui a 1000/60 milissegundos
}

void genocide(float raioMenor, float raioMaior, float probMorte){
    for(int i = 0; i < int(individuos.size()); i++){
        if(dentroDaPrisao(&individuos[i], raioMenor, raioMaior)){
            float prob = (float)rand() / RAND_MAX;
            if(prob < probMorte){
                individuos.erase(individuos.begin() + i);
            }
        }
    }
}

int main(int arc, char** argv){

    srand(42);
    glutInit(&arc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Panoptico Evolutivo");

    // Funcao para inicializar parametros
    init();
    initializeIndividuos();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0); // Define a funcao de animacao
    glutKeyboardFunc(keyboard); // Define a funcao de teclado
    glutMainLoop();
}