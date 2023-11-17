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

#include <display.h>

// Função para inicializar parâmetros
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Cor de fundo (branco)
    // gluOrtho2D(0.0, 500.0, 0.0, 500.0);  // Estabelece o sistema de coordenadas
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

// Função para desenhar os pontos aleatórios
void drawRandomPoints() {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpa o buffer de cor

    glColor3f(0.0, 0.0, 0.0);  // Cor dos pontos (preto)
    glPointSize(3.0);  // Tamanho dos pontos

    // Gera e desenha pontos aleatórios
    srand(time(NULL));
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; i++) {
        int x = rand() % 500;
        int y = rand() % 500;
        glVertex2i(x, y);
    }
    glEnd();

    glFlush();  // Força o desenho
}

void drawRandomPointsInCrown(float innerRadius, float outerRadius, float cx, float cy, int num_points) {
    srand(time(0)); // seed the random number generator
    glBegin(GL_POINTS);
    for (int i = 0; i < num_points; i++) {
        float theta = 2.0f * 3.1415926f * ((float)rand() / RAND_MAX); // random angle
        float r = innerRadius + ((float)rand() / RAND_MAX) * (outerRadius - innerRadius); // random radius
        float x = r * cos(theta) + cx; // convert polar to Cartesian coordinates
        float y = r * sin(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
}

void drawCircle(float x_centro, float y_centro, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // ângulo atual
        float dx = r * cos(theta); // cálculo do deslocamento x
        float dy = r * sin(theta); // cálculo do deslocamento y
        glVertex2f(dx + x_centro, dy + y_centro);
    }
    glEnd();
}  

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    glColor3f(0.0, 0.0, 0.0); // Define a cor para preto
    glLineWidth(3.0f);
    drawCircle(0.0, 0.0, 0.7, 1000); // Desenha o círculo externo
    drawCircle(0.0, 0.0, 0.55, 100); // Desenha o círculo interno

    glColor3f(0.0, 0.0, 1.0);
    glPointSize(3.0f);
    drawRandomPointsInCrown(0.55, 0.7, 0.0, 0.0, 50); // Desenha os pontos aleatórios

    glFlush(); // Força a execução dos comandos OpenGL
}