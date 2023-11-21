#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include <ctime>
#include <cmath>

#include "display.h"
#include "individuos.h"
#include "defines.h"

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
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

void drawDynamicLightBeam() {
    glPushMatrix(); // Salva a matriz de transformação atual
    // Rotaciona o triângulo
    glColor3f(1.0f, 1.0f, 0.0f);
    // Draw your triangle here
    static float angle = 0.0f;
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotaciona no eixo Z
    angle += 0.5f; // Ajuste este valor para alterar a velocidade de rotação

    // Desenha o triângulo
    float height = RAIO_MENOR;
    float width = height / 2.0f; // Ajuste este valor para alterar a largura do triângulo

    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.0f); // Ponto central
        glVertex2f(-width / 2.0f, -height); // Ponto inferior esquerdo
        glVertex2f(width / 2.0f, -height); // Ponto inferior direito
    glEnd();
    glPopMatrix(); // Restaura a matriz de transformação original
}

void drawFilledCircle(float x_centro, float y_centro, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    
    glVertex2f(x_centro, y_centro);  // centro do círculo
    for (int i = 0; i <= num_segments; i++) {  // <= para fechar o círculo
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // ângulo atual
        float dx = r * cosf(theta); // cálculo do deslocamento x
        float dy = r * sinf(theta); // cálculo do deslocamento y
        glVertex2f(dx + x_centro, dy + y_centro);
    }
    glEnd();
}

void drawIndividuos(vector<Individuo> individuos) {
    // cout << "Drawing " << individuos.size() << " individuos..." << endl;
    glPointSize(TAM_INDIVIDUOS);
    
    glBegin(GL_POINTS);
    for (int i = 0; i < int(individuos.size()); i++) {
        glVertex2f(individuos[i].x, individuos[i].y);
    }
    glEnd();
}

void drawString(const char* str) {
    while (*str) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str++);
    }
}



