/**************************************************************************//**
 * @file filledellipse.cpp
 *
 * @brief OpenGL graphics program, illustrating use of GLUT and callback
 * functions.
 *
 * @author: Sterling McKenzie
 *	    Minati Alphonso
 *
 * @par Class:
 * CSC300 Data Structures
 *
 * @date:   Fall 2015
 *
 * @par Modifications:
 *    * Changed how ellipse is drawn : Sterling McKenzie / Minati Alphonso 10/2/2019
 *    * Changed the contains function : Sterling McKenzie / Minati Alphonso 10/2/2019
 ******************************************************************************/
#include <iostream>
#include "filledellipse.h"

using namespace std;

// FilledEllipse class implementation

/**************************************************************************//**
 * @brief Constructor [x1,y1] to [x2,y2]
 *
 * @param[in] x1 - x-coordinate of the starting point
 * @param[in] y1 - y-coordinate of the starting point
 * @param[in] x2 - x-coordinate of the end point
 * @param[in] y2 - y-coordinate of the end point
 * @param[in] color - float array containing the color of the line being drawn
 * @param[in] border - float array containing the border color value
 *
 ******************************************************************************/
FilledEllipse::FilledEllipse( float x1, float y1, float x2, float y2, float *c, float *b) : Ellipse(x1, y1, x2, y2, c), border( b ) {}

/**************************************************************************//**
 * @brief Destructor
 *
 ******************************************************************************/
FilledEllipse::~FilledEllipse( ) {}
/**************************************************************************//**
 * @brief Draw a filled ellipse with coordinates specified in the constructor
 *
 ******************************************************************************/
// must override pure virtual Shape::draw() method to instantiate class
void FilledEllipse::draw( ) const
{
    // Calculate middle point of ellipse
    float xMiddle = (xLoc1 + xLoc2) / 2;
    float yMiddle = (yLoc1 + yLoc2) / 2;

    // Calculate xRadius and yRadius
    float xRadius = abs(xLoc1 - xMiddle);
    float yRadius = abs(yLoc1 - yMiddle);

    DrawFilledEllipse(xRadius, yRadius, xMiddle, yMiddle, &color[0]);
    DrawEllipse(xRadius, yRadius, xMiddle, yMiddle, &border[0]);
}
/**************************************************************************//**
 * @brief Determine if a location is contained by a given point
 *
 * @param[in] x - x-coordinate of the clicked point
 * @param[in] y - y-coordinate of the clicked point
 *
 ******************************************************************************/
// must override pure virtual Shape::erase() method to instantiate class
bool FilledEllipse::contains(float x, float y) const
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
