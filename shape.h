/***************************************************************************//**
 * @file shape.h
 ******************************************************************************/
/**************************************************************************//**
 * @file shape.h
 *
 * @brief Shape class implementation
 *
 * @author: John M. Weiss, Ph.D.
 *
 * @par Class:
 * CSC315 Data Structures
 *
 * @date:   Fall 2019
 * 
 * @par Modifications:
 *    * Added doxygen style comments
 *    * Added contains function: Sterling McKenzie / Minati Alphonso 
 *
 ******************************************************************************/

// guard against multiple inclusions
#ifndef _Shape_H_
#define _Shape_H_

// include files
#include <iostream>
#include <math.h>
using namespace std;

// Shape class interface
// Note that this is an abstract class since it contains pure virtual functions.
/***************************************************************************//**
 * @class Shape
 ******************************************************************************/
class Shape
{
protected:                    // note use of protected instead of private
    float xLoc1, yLoc1, xLoc2, yLoc2;
    float *color;

public:                       // public methods
    // constructor
    Shape( float x1 = 0.0, float y1 = 0.0, float x2 = 0.0, float y2 = 0.0, float c[3] = {0} );

    // destructor
    virtual ~Shape( );

    // pure virtual methods that must be overridden in non-abstract derived classes
	//pure virtual function to draw the shape
    virtual void draw() const = 0;
	//pure virtual function to check if a point is contained within the shape
    virtual bool contains(float x, float y) const = 0;
};

#endif

