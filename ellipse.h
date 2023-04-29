/***************************************************************************//**
 * @file ellipse.h 
 ******************************************************************************/
 /**************************************************************************//**
 * @file ellipse.h
 *
 * @brief Ellipse class implementation
 *
 * @author: Sterling McKenzie / Minati Alphonso
 *
 * @par Class:
 * CSC315 Data Structures
 *
 * @date:   Fall 2019
 *
 ******************************************************************************/
// guard against multiple inclusions
#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_

#include "shape.h"
#include "graphics.h"

/***************************************************************************//**
 * @class Ellipse
 ******************************************************************************/
class Ellipse : public Shape
{
protected:
	//the x-radius of the ellipse
    float xRadius; 
	//the y-radius of the ellipse
	float yRadius;
public:
	//constructor
    Ellipse( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float c[3] = {0});
	//destructor
    ~Ellipse( );
	//function to draw the ellipse
    void draw( ) const;
	//function to check if a point is contained within the ellipse
    bool contains(float x, float y) const;
};

#endif
