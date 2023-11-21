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



