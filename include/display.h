#ifndef DISPLAY_H
#define DISPLAY_H

#define windowWidth 900
#define windowH

#include "individuos.h"

using namespace std;

#include <iostream>

void init();
void drawRandomPoints();
void drawRandomPointsInCrown(float innerRadius, float outerRadius, float cx, float cy, int num_points);
void drawCircle(float x_centro, float y_centro, float r, int num_segments);
void drawIndividuos(vector<Individuo> individuos);

void keyboard(unsigned char key, int x, int y);

#endif // DISPLAY_H
