/***************************************************************************//**
 * @file graphics.h
 *
 * OpenGL graphics program, illustrating use of GLUT and callback functions.
 *
 * @author John M. Weiss, Ph.D.
 * 	   Sterling McKenzie
 * @par Class
 *    CSC300 Data Structures
 * @date Fall 2015
 *
 * Modifications:
 *    * Added doxygen style comments: PJH 9/5/2016
 *    * Added additional colors: Sterling McKenzie / Minati Alphonso 9/24/19
 *    * Added DrawShapes, DrawPalette, RedrawShapes, ChooseColor and Choose Shape : Sterling
 *       McKenzie / Minati Alphonso 10/2/19
 ******************************************************************************/
#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <vector>
#include "shape.h"
// the GLUT header automatically includes gl.h and glu.h
#include <GL/freeglut.h>

/// Define the Black color
const float Black[] = { 0.0, 0.0, 0.0 };
/// Define the Red color
const float Red[]   = { 1.0, 0.0, 0.0 };
/// Define the LightGreen color
const float LightGreen[] = { 0.5, 1.0, 0.5 };
//Define the DarkGreen color
const float DarkGreen[] = { 0.0, 0.5, 0.0 };
/// Define the Blue color
const float Blue[]  = { 0.0, 0.0, 1.0 };
/// Define the Magenta color
const float Magenta[]   = { 1.0, 0.0, 1.0 };
/// Define the Cyan color
const float Cyan[]  = { 0.0, 1.0, 1.0 };
/// Define the Yellow color
const float Yellow[]    = { 1.0, 1.0, 0.0 };
/// Define the Orange color
const float Orange[]	= { 1.0, 0.5, 0.0 };
/// Define the White color
const float White[] = { 1.0, 1.0, 1.0 };

/// DrawLine function
void DrawLine( float x1, float y1, float x2, float y2, const float color[] );
/// DrawRectangle function
void DrawRectangle( float x1, float y1, float x2, float y2, const float color[] );
/// DrawFilledRectangle function
void DrawFilledRectangle( float x1, float y1, float x2, float y2, const float color[] );
/// DrawEllipse function
void DrawEllipse( float xRadius, float yRadius, int x, int y, const float color[] );
/// DrawFilledEllipse function
void DrawFilledEllipse( float xRadius, float yRadius, int x, int y, const float color[] );
/// DrawPalette function
void DrawPalette();
/// DrawShapes function
void DrawShapes(std::vector<Shape*> shapes);
/// RedrawShapes function
void RedrawShapes(std::vector<Shape*> shapes);
/// ChooseColor function
void ChooseColor(int x1, int y1, float *color);
/// ChooseShape function
char ChooseShape(int x1, int y1);
#endif

