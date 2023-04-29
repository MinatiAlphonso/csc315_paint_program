/***************************************************************************//**
 * @file callbacks.h provide by Dr. Hinker in Glut Example Code
 ******************************************************************************/
#ifndef __CALLBACKS_H
#define __CALLBACKS_H
#include <iostream>
#include "event.h"
#include "util.h"

void display();

void keyboard(unsigned char key, int xCoord, int yCoord);

void mouseClick(int button, int state, int xCoord, int yCoord);

void reshape(const int w, const int h);

void utilCentral(Event *);

#endif
