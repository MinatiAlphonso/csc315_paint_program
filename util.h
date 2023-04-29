/***************************************************************************//**
 * @file util.h provide by Dr. Hinker in Glut Example Code
 ******************************************************************************/
#ifndef __UTIL_H
#define __UTIL_H
#include <GL/freeglut.h>
#include "event.h"
#include "callbacks.h"

void utilCentral(Event *event);
void initOpenGL(int argc, char **argv, int wCols, int wrows);
#endif
