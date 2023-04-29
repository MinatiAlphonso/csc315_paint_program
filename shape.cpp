/***************************************************************************//**
 * @file shape.cpp
 ******************************************************************************/
/**************************************************************************//**
 * @file shape.cpp
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

// include files
#include <iostream>
using namespace std;

#include "shape.h"

// Shape class implementation
// Note that this is an abstract class since it contains pure virtual functions.

/***************************************************************************//**
 * @brief Constructor
 *
 * Constructor for the shape class
 *
 * @param[in] x - the x-coordinate of where the button was first pressed
 * @param[in] y - the y-coordinate of where the button was first pressed
 * @param[in] x2 - the x-coordinate of where the button released
 * @param[in] y2 - the y-coordinate of where the button released
 * @param[in] c - the color of the line
 *
 ******************************************************************************/
Shape::Shape( float x1, float y1, float x2, float y2, float *c ) : xLoc1( x1 ), yLoc1( y1 ), xLoc2( x2 ), yLoc2( y2 ), color( c )
{}

// destructor
Shape::~Shape( )
{
}

