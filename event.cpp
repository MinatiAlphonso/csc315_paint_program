/***************************************************************************//**
 * @file event.cpp provide by Dr. Hinker in Glut Example Code
 ******************************************************************************/
#include "event.h"

Event::~Event() {}


/***************************************************************************//**
 * @brief Constructor
 *
 * This event should only happen once on initial startup.  If the game state
 * needs initialization, here is where that would likely happen
 *
 * @param[in] c - columns (in pixels) of the window
 * @param[in] r - rows (in pixels) of the window
 ******************************************************************************/
InitEvent::InitEvent(int c, int r) : columns(c), rows(r) {}

void InitEvent::doAction(std::vector<Shape*> &shapes)
{
    glClear(GL_COLOR_BUFFER_BIT);
}

/***************************************************************************//**
 * @brief Constructor
 *
 * Display event is called under a number of circumstances.  During its action
 * method, we just swap the buffers (we are assuming double buffer mode)
 * If there is a repaint required by the game, here is where that would likely
 * happen
 ******************************************************************************/
void DisplayEvent::doAction(std::vector<Shape*> &shapes)
{
    // Setting the title of the window
    stringstream ss;

    ss << "SDSM&T Paint";
    glutSetWindowTitle(ss.str().c_str());

    // Swap the back plane forward
    glutSwapBuffers();
    // Clear the back plane
    glClear(GL_COLOR_BUFFER_BIT);

    DrawPalette();
    DrawShapes(shapes);

    //glFlush();
    glutSwapBuffers();
}

/***************************************************************************//**
 * @brief Constructor
 *
 * This event gets called continuously as the window is resized.  This event
 * usually also triggers a display event
 *
 * @param[in] w - width (in pixels) of the window
 * @param[in] h - height (in pixels) of the window
 ******************************************************************************/
ReshapeEvent::ReshapeEvent(int w, int h) : width(w), height(h) {}

void ReshapeEvent::doAction(std::vector<Shape*> &shapes)
{
    int minWidth = 405;
    int minHeight = 405;

    //Size of window cannot be smaller than 400x400
    if(width < minWidth && height < minHeight)
        glutReshapeWindow(minWidth, minHeight);
    else if(width < minWidth)
        glutReshapeWindow(minWidth, height);
    else if(height < minHeight)
        glutReshapeWindow(width, minHeight);

    glMatrixMode( GL_PROJECTION );      	// use an orthographic projection
    glLoadIdentity();                   	// initialize transformation matrix
    gluOrtho2D( 0.0, width, 0.0, height );	// make OpenGL coordinates
    glViewport( 0, 0, width, height );     	// the same as the screen coordinates
}


/***************************************************************************//**
 * @brief Constructor
 *
 * Self-explanatory, a mouse click event has happened, react as necessary
 *
 * @param[in] b - the button that was pressed
 * @param[in] s - the state of the button that was pressed (0-down, 1-up)
 * @param[in] x - the x-coordinate of where the button 'b' was pressed/released
 * @param[in] y - the y-coordinate of where the button 'b' was pressed/released
 ******************************************************************************/
MouseClickEvent::MouseClickEvent(int b, int s, int x, int y) :
    button(b), state(s), xLoc(x), yLoc(y) {}

void MouseClickEvent::doAction(std::vector<Shape*> &shapes)
{
    static float color[3];
    static float border[3];
    static char shape;
    static int x1;
    static int y1;
    Shape* shapePtr = nullptr;

    // Left click
    if( button == 0)
    {
        //When Button is Clicked
        if(state == 0)
        {
            //Choose Border Color
            if( xLoc < 100 && yLoc < 250 )
                ChooseColor(xLoc,yLoc, &border[0]);
            //Choose Shape
            else if( xLoc < 100 && yLoc < 400 )
                shape = ChooseShape(xLoc, yLoc);
            //Initial Location
            else
            {
                x1 = xLoc;
                y1 = yLoc;
            }
        }
        //When Button is Released
        if(state == 1 )
        {
            if (!(xLoc < 100 && yLoc < 400) && !(x1 < 100 && y1 < 400))
            {
                //Filled Rectangle
                if(shape == 'R')
                {
                    shapePtr = new FilledRectangle(x1, y1, xLoc, yLoc, &color[0], &border[0]);
                }
                //Unfilled Rectangle
                if(shape == 'r')
                {
                    shapePtr = new Rectangle(x1, y1, xLoc, yLoc, &border[0]);
                }
                //Filled Ellipse
                if(shape == 'E')
                {
                    shapePtr = new FilledEllipse(x1, y1, xLoc, yLoc, &color[0], &border[0]);
                }
                //Unfilled Ellipse
                if(shape == 'e')
                {
                    shapePtr = new Ellipse(x1, y1, xLoc, yLoc, &border[0]);
                }
                //Line
                if(shape == 'l')
                {
                    shapePtr = new Line(x1, y1, xLoc, yLoc, &border[0]);
                }

                if (shapePtr != nullptr)
                {
                    // Push new shape into shapes vector
                    shapes.push_back(shapePtr);
                    shapePtr->draw();
                    glutSwapBuffers();
                }
            }
        }
    }

    // Right Click
    if( button == 2)
    {
        if( state == 0 )
        {
            //Choose Fill Color
            if( xLoc < 100 && yLoc < 250 )
                ChooseColor(xLoc,yLoc, &color[0]);
            //Determine if a shape is being selected
            if (!(xLoc < 100 && yLoc < 400) && !(x1 < 100 && y1 < 400))
            {
                for(unsigned int i = 0; i < shapes.size(); i++)
                {
                    // Move selected shape to the front
                    if(shapes[i]->contains(xLoc,yLoc))
                    {
                        shapes.push_back(shapes[i]);
                        shapes.erase(shapes.begin() + i);
                        RedrawShapes(shapes);
                        // Getting out of for loop when shape is found
                        i = shapes.size();
                    }
                }
            }
        }
    }

}

/***************************************************************************//**
 * @brief Constructor
 *
 * A keyboard key has been pressed.  This object's action method will react
 * to the escape key by leaving the main glut event loop.  If you need to do
 * resource freeing, doing so before leaving the glut main loop (or immediately
 * thereafter) is suggested
 *
 * @param[in] k - the ascii value of the key that was pressed
 * @param[in] x - the x-coordinate of where the key 'k' was pressed
 * @param[in] y - the y-coordinate of where the key 'k' was pressed
 ******************************************************************************/
KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : key(k), xLoc(x), yLoc(y) {}

void KeyboardEvent::doAction(std::vector<Shape*> &shapes)
{
    // Leave program if the escape key is pressed or the q key is pressed
    if (key == ESCAPE_KEY || key == LOWERCASE_Q)
        glutLeaveMainLoop();
    // Clear the screen if the c key is pressed
    if (key == LOWERCASE_C)
    {
        shapes.clear();
        glutSwapBuffers();
        glClear(GL_COLOR_BUFFER_BIT);
		shapes.clear();
        DrawPalette();
        glutSwapBuffers();
    }
    // Delete the topmost shape if the d key is pressed
    if (key == LOWERCASE_D)
    {
        if(!shapes.empty())
        {
            shapes.pop_back();
            RedrawShapes(shapes);
        }
    }
    // Any other key that is pressed will redraw the screen
    else
    {
        RedrawShapes(shapes);
    }

}
