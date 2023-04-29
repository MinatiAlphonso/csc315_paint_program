/***************************************************************************//**
 * @file ellipse.cpp
 ******************************************************************************/
/**************************************************************************//**
 * @file ellipse.cpp
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
#include <iostream>
using namespace std;

#include "ellipse.h"

/***************************************************************************//**
 * @brief Constructor
 *
 * Constructor for the ellipse class
 *
 * @param[in] x1 - the x-coordinate of where the button was first pressed
 * @param[in] y1 - the y-coordinate of where the button was first pressed
 * @param[in] x2 - the x-coordinate of where the button released
 * @param[in] y2 - the y-coordinate of where the button released
 * @param[in] c - the fill color of the ellipse
 *
 ******************************************************************************/
Ellipse::Ellipse( float x1, float y1, float x2, float y2, float *c) : Shape(x1, y1, x2, y2, c) {}

// destructor
Ellipse::~Ellipse( ) {}

// must override pure virtual Shape::draw() method to instantiate class
/***************************************************************************//**
 * @brief draw
 *
 * A pure virtual function to draw the ellipse
 *
 ******************************************************************************/
void Ellipse::draw() const
{
    float xRadius, yRadius, xMiddle, yMiddle;

    // Calculate middle point of ellipse
    xMiddle = (xLoc1 + xLoc2) / 2;
    yMiddle = (yLoc1 + yLoc2) / 2;

    // Calculate xRadius and yRadius
    xRadius = abs(xLoc1 - xMiddle);
    yRadius = abs(yLoc1 - yMiddle);


    DrawEllipse(xRadius, yRadius, xMiddle, yMiddle, &color[0]);

}

// must override pure virtual Shape::erase() method to instantiate class
/***************************************************************************//**
 * @brief contains
 *
 * A pure virtual function to check if a point is within the ellipse
 *
 * @param[in] x - the x-coordinate of where the mouse is clicked
 * @param[in] y - the y-coordinate of where the mouse is clicked
 * 
 ******************************************************************************/
bool Ellipse::contains(float x, float y) const
{
    // Calculate middle point of ellipse
    float xMiddle = (xLoc1 + xLoc2) / 2;
    float yMiddle = (yLoc1 + yLoc2) / 2;
    // Calculate radius and diameter of ellipse
    float xRadius = abs(xLoc1 - xMiddle);
    float yRadius = abs(yLoc1 - yMiddle);

    // Calculate if the point is contained in the shape
    float contain = (pow(x - xMiddle, 2) / pow(xRadius, 2))+(pow(y - yMiddle, 2) / pow(yRadius, 2));

    if(contain < 1)
        return true;
    else
        return false;

    return true;
}
