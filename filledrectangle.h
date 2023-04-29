/***************************************************************************//**
 * @file filledrectangle.h
 ******************************************************************************/
#ifndef _FILLEDRECTANGLE_H_
#define _FILLEDRECTANGLE_H_

#include "rectangle.h"
#include "graphics.h"

/***************************************************************************//**
 * @file Class FilledRectangle
 ******************************************************************************/
// Filled Rectangle class interface
class FilledRectangle : public Rectangle
{
protected:
    float *border;

public:
    FilledRectangle( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float c[3] = {0}, float b[3] = {0});
    ~FilledRectangle( );
    void draw( ) const;
    bool contains(float x, float y) const;
};

#endif
