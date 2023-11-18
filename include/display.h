#ifndef DISPLAY_H
#define DISPLAY_H

#include "individuos.h"

using namespace std;

#include <iostream>

void init();
void drawRandomPoints();
void drawRandomPointsInCrown(float innerRadius, float outerRadius, float cx, float cy, int num_points);
void drawCircle(float x_centro, float y_centro, float r, int num_segments);
void drawFilledCircle(float x_centro, float y_centro, float r, int num_segments);
void drawIndividuos(vector<Individuo> individuos);

void keyboard(unsigned char key, int x, int y);
void drawString(const char* str);

#endif // DISPLAY_H
