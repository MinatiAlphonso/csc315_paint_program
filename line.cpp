/***************************************************************************//**
 * @file line.cpp
 ******************************************************************************/
/**************************************************************************//**
 * @file line.cpp
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

// include files
#include <iostream>
using namespace std;

#include "line.h"

// Point class implementation


/***************************************************************************//**
 * @brief Constructor
 *
 * Constructor for the line class
 *
 * @param[in] x - the x-coordinate of where the button was first pressed
 * @param[in] y - the y-coordinate of where the button was first pressed
 * @param[in] x2 - the x-coordinate of where the button released
 * @param[in] y2 - the y-coordinate of where the button released
 * @param[in] c - the color of the line
 *
 ******************************************************************************/
Line::Line( float x, float y, float x2, float y2, float *c ) : Shape( x, y, x2, y2, c ) {}

// destructor
Line::~Line( ) {}

// must override pure virtual Shape::draw() method to instantiate class
/***************************************************************************//**
 * @brief draw
 *
 * A pure virtual function to draw the line
 *
 ******************************************************************************/
void Line::draw( ) const
{
    DrawLine(xLoc1, yLoc1, xLoc2, yLoc2, &color[0]);
}

// must override pure virtual Shape::erase() method to instantiate class
/***************************************************************************//**
 * @brief contains
 *
 * A pure virtual function to check if a point is within the line
 *
 * @param[in] x - the x-coordinate of where the mouse is clicked
 * @param[in] y - the y-coordinate of where the mouse is clicked
 * 
 ******************************************************************************/
bool Line::contains(float x, float y) const
{
    // Calculate middle point of ellipse contained by rectangle
    float xMiddle = (xLoc1 + xLoc2) / 2;
    float yMiddle = (yLoc1 + yLoc2) / 2;
    // Calculate the radius of the ellipse contained by the rectangle
    float xRadius = abs(xLoc1 - xMiddle);
    float yRadius = abs(yLoc1 - yMiddle);

    if(xMiddle + xRadius > x && xMiddle - xRadius < x)
        return true;
    if(yMiddle + yRadius > y && yMiddle - yRadius < y)
        return true;

    return false;
}

