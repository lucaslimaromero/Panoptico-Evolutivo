#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
// #include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <vector>

#include "individuos.h"
#include "display.h"

#define windowWidth 900
#define windowHeight 900

using namespace std;
std::vector<Individuo> individuos;

int main(int arc, char** argv){
    glutInit(&arc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Panoptico Evolutivo");
    // Funcao para inicializar parametros
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Define a funcao de teclado
    glutMainLoop();
}