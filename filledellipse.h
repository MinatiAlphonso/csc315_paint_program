/***************************************************************************//**
 * @file filledellipse.h
 ******************************************************************************/
#ifndef _FILLEDELLIPSE_H_
#define _FILLEDELLIPSE_H_

#include "ellipse.h"
#include "graphics.h"

using namespace std;

/***************************************************************************//**
 * @file Class FilledEllipse
 ******************************************************************************/
class FilledEllipse : public Ellipse
{
protected:
    float *border;

public:
    FilledEllipse( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float c[3] = {0}, float b[3] = {0});
    ~FilledEllipse( );
    void draw( ) const;
    bool contains(float x, float y) const;
};
#endif
