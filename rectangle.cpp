/***************************************************************************//**
 * @file
 ******************************************************************************/
/**************************************************************************//**
 * @file rectangle.cpp
 *
 * @brief OpenGL graphics program, illustrating use of GLUT and callback
 * functions.
 *
 * @author: John M. Weiss, Ph.D.
 *	    Sterling McKenzie
 *	    Minati Alphonso
 *
 * @par Class:
 * CSC300 Data Structures
 *
 * @date:   Fall 2015
 *
 * @par Modifications:
 *    * Added doxygen style comments : PJH 9/5/2016
 *    * Changed how rectangle is drawn : Sterling McKenzie 10/2/2019
 *    * Changed the contains function : Sterling McKenzie 10/2/2019
 ******************************************************************************/

// include files
#include <iostream>
using namespace std;

#include "rectangle.h"

// Rectangle class implementation

/**************************************************************************//**
 * @brief Constructor [x1,y1] to [x2,y2]
 *
 * @param[in] x1 - x-coordinate of the starting point
 * @param[in] y1 - y-coordinate of the starting point
 * @param[in] x2 - x-coordinate of the end point
 * @param[in] y2 - y-coordinate of the end point
 * @param[in] color - float array containing the color of the line being drawn
 *
 ******************************************************************************/
Rectangle::Rectangle( float x1, float y1, float x2, float y2, float *c ) :
    Shape( x1, y1, x2, y2, c ) {}

/**************************************************************************//**
 * @brief Destructor
 *
 ******************************************************************************/
Rectangle::~Rectangle( )
{}

/**************************************************************************//**
 * @brief Draw a rectangle with coordinates specified in the constructor
 *
 ******************************************************************************/
void Rectangle::draw( ) const
{
    DrawRectangle(xLoc1, yLoc1, xLoc2, yLoc2, &color[0]);
}

/**************************************************************************//**
 * @brief Determine if a point is contained by a given shape
 *
 * @param[in] x - x-coordinate of the clicked point
 * @param[in] y - y-coordinate of the clicked point
 *
 ******************************************************************************/
bool Rectangle::contains(float x, float y) const
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

