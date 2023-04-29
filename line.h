/***************************************************************************//**
 * @file line.h
 ******************************************************************************/
/**************************************************************************//**
 * @file line.h
 *
 * @brief Line class implementation
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
#ifndef _Line_H_
#define _Line_H_

#include "shape.h"
#include "graphics.h"

// Point class interface

/***************************************************************************//**
 * @class Line
 ******************************************************************************/
class Line : public Shape
{
public:
	//constructor
    Line( float x = 0.0, float y = 0.0, float x2 = 0.0, float y2 = 0.0, float color[3] = {0});
    //destructor
	~Line( );
	
	//function to draw the line
    void draw( ) const;
	//function to check if a point is contained within the line
    bool contains(float x, float y) const;
};

#endif
