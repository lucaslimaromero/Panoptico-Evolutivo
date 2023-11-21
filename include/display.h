#ifndef DISPLAY_H
#define DISPLAY_H

#include "individuos.h"

using namespace std;

#include <iostream>
#include <vector>

// Funcoes responsaveis pelos desenhos em OpenGL

void drawCircle(float x_centro, float y_centro, float r, int num_segments);
void drawFilledCircle(float x_centro, float y_centro, float r, int num_segments);
void drawIndividuos(vector<Individuo> individuos);
void drawDynamicLightBeam();

void keyboard(unsigned char key, int x, int y);
void drawString(const char* str);

#endif // DISPLAY_H
