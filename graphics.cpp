/**************************************************************************//**
 * @file graphics.cpp
 *
 * @brief OpenGL graphics program, illustrating use of GLUT and callback
 * functions.
 *
 * @author: John M. Weiss, Ph.D.
 *
 * @par Class:
 * CSC300 Data Structures
 *
 * @date:   Fall 2015
 *
 * @par Modifications:
 *    * Added doxygen style comments : PJH 9/5/2016
 *    * Added additional colors: Sterling McKenzie / Minati Alphonso 9/24/19
 ******************************************************************************/
#include "graphics.h"

/**************************************************************************//**
 * @brief Draw a line in the active window from point [x1,y1] to [x2,y2]
 *
 * @param[in] x1 - x-coordinate of the starting point
 * @param[in] y1 - y-coordinate of the starting point
 * @param[in] x2 - x-coordinate of the end point
 * @param[in] y2 - y-coordinate of the end point
 * @param[in] color - float array containing the color of the line being drawn
 *
 ******************************************************************************/
void DrawLine( float x1, float y1, float x2, float y2, const float color[] )
{
    glLineWidth( 3 );
    glColor3fv( color );
    glBegin( GL_LINES );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}

/**************************************************************************//**
 * @brief Draw a rectangle in the active window from point [x1,y1] to [x2,y2]
 *
 * @param[in] x1 - x-coordinate of the left-lower corner
 * @param[in] y1 - y-coordinate of the left-lower corner
 * @param[in] x2 - x-coordinate of the right-upper corner
 * @param[in] y2 - y-coordinate of the right-upper corner
 * @param[in] color - float array containing the color of the boundries
 *
 ******************************************************************************/
void DrawRectangle( float x1, float y1, float x2, float y2, const float color[] )
{
    glColor3fv( color );
    glBegin( GL_LINE_LOOP );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

/**************************************************************************//**
 * @brief Draw a filled rectangle in the active window from point [x1,y1] to
 * [x2,y2]
 *
 * @param[in] x1 - x-coordinate of the left-lower corner
 * @param[in] y1 - y-coordinate of the left-lower corner
 * @param[in] x2 - x-coordinate of the right-upper corner
 * @param[in] y2 - y-coordinate of the right-upper corner
 * @param[in] color - float array containing the filled color of the rectangle
 *
 ******************************************************************************/
void DrawFilledRectangle( float x1, float y1, float x2, float y2, const float color[] )
{
    glColor3fv( color );
    glBegin( GL_POLYGON );
    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

/**************************************************************************//**
 * @brief Draw an ellipse in the active window at point [x,y]
 *
 * @param[in] xRadius - x-radius of the ellipse
 * @param[in] yRadius - y-radius of the ellipse
 * @param[in] x - x-coordinate of the center of the ellipse
 * @param[in] y - y-coordinate of the center of the ellipse
 * @param[in] color - float array containing the filled color of the ellipse
 *
 ******************************************************************************/
void DrawEllipse( float xRadius, float yRadius, int x, int y, const float color[] )
{
    // stretch circle into ellipse
    float radius = xRadius < yRadius ? xRadius : yRadius;
    glColor3fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );

    // by ratio of major to minor axes
    glScalef( xRadius / radius, yRadius / radius, 1.0 );
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, radius - 1, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

/**************************************************************************//**
 * @brief Draw an ellipse in the active window at point [x,y]
 *
 * @param[in] xRadius - x-radius of the ellipse
 * @param[in] yRadius - y-radius of the ellipse
 * @param[in] x - x-coordinate of the center of the ellipse
 * @param[in] y - y-coordinate of the center of the ellipse
 * @param[in] color - float array containing the filled color of the ellipse
 *
 ******************************************************************************/
void DrawFilledEllipse( float xRadius, float yRadius, int x, int y, const float color[] )
{
    // stretch circle into ellipse
    float radius = xRadius < yRadius ? xRadius : yRadius;
    glColor3fv( color );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( x, y, 0 );

    // by ratio of major to minor axes
    glScalef( xRadius / radius, yRadius / radius, 1.0 );
    GLUquadricObj *disk = gluNewQuadric();
    gluDisk( disk, 0, radius, int( radius ), 1 );
    gluDeleteQuadric( disk );
    glLoadIdentity();
    glFlush();
}

/**************************************************************************//**
 * @brief Draw a palette in a the bottom left corner of a window
 ******************************************************************************/
void DrawPalette()
{
    // Left Coloumn of Palette
    DrawFilledRectangle(0,0,50,50, Black);
    DrawFilledRectangle(0,50,50,100, Blue);
    DrawFilledRectangle(0,100,50,150, LightGreen);
    DrawFilledRectangle(0,150,50,200, Magenta);
    DrawFilledRectangle(0,200,50,250, Red);
    // Right Coloumn of Palette
    DrawFilledRectangle(50,0,100,50, White);
    DrawFilledRectangle(50,50,100,100, Cyan);
    DrawFilledRectangle(50,100,100,150, Yellow);
    DrawFilledRectangle(50,150,100,200, Orange);
    DrawFilledRectangle(50,200,100,250, DarkGreen);

    //left column Boxes
    DrawRectangle(0,250,50,300,White);
    DrawRectangle(0,300,50,350,White);
    DrawRectangle(0,350,50,400,White);
    //right column Boxes
    DrawRectangle(50,250,100,300,White);
    DrawRectangle(50,300,100,350,White);
    DrawRectangle(50,350,100,400,White);

    //Unfilled Rectangle
    DrawRectangle(10,260,40,290,White);
    //Filled Rectangle
    DrawFilledRectangle(60,260,90,290,White);
    //Unfilled Ellipse
    DrawEllipse(15,15,25,325,White);
    //Filled Ellipse
    DrawFilledEllipse(15,15,75,325,White);
    //Line
    DrawLine(10,360,40,390,White);
}
/**************************************************************************//**
 * @brief Draw shapes from a given vector of shapes
 *
 * @param[in] shapes - a vector of shape object pointers
 *
 ******************************************************************************/
void DrawShapes(std::vector<Shape*> shapes)
{
    for(unsigned int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->draw();
    }
}
/**************************************************************************//**
 * @brief Redraw shapes from a given vector of shapes. Used when window is resized
 *
 * @param[in] shapes - a vector of shape object pointers
 *
 ******************************************************************************/
void RedrawShapes(std::vector<Shape*> shapes)
{
    // Swap the back plane forward
    glutSwapBuffers();
    // Clear the back plane
    glClear(GL_COLOR_BUFFER_BIT);
    //Redraw pallette
    DrawPalette();
    for(unsigned int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->draw();
    }
    glutSwapBuffers();
}
/**************************************************************************//**
 * @brief Choose the color on the location of the palette
 *
 * @param[in] x1 - x location of mouse click
 * @param[in] y1 - y location of mouse click
 * @param[in] color - pointer to the color chosen
 *
 ******************************************************************************/
void ChooseColor(int x1, int y1, float *color)
{

    if(x1 > 50 && y1 > 200 && x1 < 100 && y1 < 250)
    {
        color[0] = DarkGreen[0];
        color[1] = DarkGreen[1];
        color[2] = DarkGreen[2];
    }
    else if(x1 > 50 && y1 > 150 && x1 < 100 && y1 < 200)
    {
        color[0] = Orange[0];
        color[1] = Orange[1];
        color[2] = Orange[2];
    }
    else if(x1 > 50 && y1 > 100 && x1 < 100 && y1 < 150)
    {
        color[0] = Yellow[0];
        color[1] = Yellow[1];
        color[2] = Yellow[2];
    }
    else if(x1 > 50 && y1 > 50 && x1 < 100 && y1 < 100)
    {
        color[0] = Cyan[0];
        color[1] = Cyan[1];
        color[2] = Cyan[2];
    }
    else if(x1 > 50 && y1 > 0 && x1 < 100 && y1 < 500)
    {
        color[0] = White[0];
        color[1] = White[1];
        color[2] = White[2];
    }
    else if(x1 > 0 && y1 > 200 && x1 < 50 && y1 < 250) //
    {
        color[0] = Red[0];
        color[1] = Red[1];
        color[2] = Red[2];
    }
    else if(x1 > 0 && y1 > 150 && x1 < 50 && y1 < 200)
    {
        color[0] = Magenta[0];
        color[1] = Magenta[1];
        color[2] = Magenta[2];
    }
    else if(x1 > 0 && y1 > 100 && x1 < 50 && y1 < 150)
    {
        color[0] = LightGreen[0];
        color[1] = LightGreen[1];
        color[2] = LightGreen[2];
    }
    else if(x1 > 0 && y1 > 50 && x1 < 50 && y1 < 100)
    {
        color[0] = Blue[0];
        color[1] = Blue[1];
        color[2] = Blue[2];
    }
    else if(x1 > 0 && y1 > 0 && x1 < 50 && y1 < 500)
    {
        color[0] = Black[0];
        color[1] = Black[1];
        color[2] = Black[2];
    }
}
/**************************************************************************//**
 * @brief Choose the shape selected on the palette based on the mouse click location
 *
 * @param[in] x1 - x location of mouse click
 * @param[in] y1 - y location of mouse click
 * @param[in] color - pointer to the shape chosen
 *
 ******************************************************************************/
char ChooseShape(int x1, int y1)
{
    char shape = 'b';

    // Line selected
    if(x1 > 0 && y1 > 350 && x1 < 50 && y1 < 400)
        shape = 'l';
    // Rectangle selected
    else if(x1 > 0 && y1 > 250 && x1 < 50 && y1 < 300)
        shape = 'r';
    // Filled rectangle selected
    else if(x1 > 50 && y1 > 250 && x1 < 100 && y1 < 300)
        shape = 'R';
    // Ellipse selected
    else if(x1 > 0 && y1 > 300 && x1 < 50 && y1 < 350)
        shape = 'e';
    // Filled ellipse selected
    else if(x1 > 50 && y1 > 300 && x1 < 100 && y1 < 350)
        shape = 'E';
    // Blank spot selected
    else
        shape = 'b';

    return shape;
}
