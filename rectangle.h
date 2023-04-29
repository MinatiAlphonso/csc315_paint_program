/***************************************************************************//**
 * @file rectangle.h
 ******************************************************************************/
/*
                    ***** rectangle.h *****

OOP example illustrating inheritance and late binding via virtual functions in C++.
Inheritance is used to derive various shape classes (Point, Line, Circle, Rectangle, Square)
from a base Shape class.

This file contains the Rectangle class interface.

Author: John M. Weiss, Ph.D.
Class:  CSC300 Data Structures
Date:   Fall 2015

Modifications:
*/

// guard against multiple inclusions
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "shape.h"
#include "graphics.h"

/***************************************************************************//**
 * @file Rectangle Class
 ******************************************************************************/
// Rectangle class interface
class Rectangle : public Shape
{
protected:
    float width, height;

public:
    Rectangle( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float c[3] = {0});
    ~Rectangle( );
    void draw( ) const;
    bool contains(float x, float y) const;
};

#endif

