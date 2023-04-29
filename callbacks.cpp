/***************************************************************************//**
 * @file callbacks.cpp provide by Dr. Hinker in Glut Example Code
 ******************************************************************************/
#include "callbacks.h"

/***************************************************************************//**
 * @brief A callback function to flip the y = 0 coordinate to bottom of screen
 ******************************************************************************/
// OpenGL thinks the y = 0 coordinate is at the top of the screen. Flip it over
int actualY(int y)
{
    return glutGet(GLUT_WINDOW_HEIGHT) - y;
}

/***************************************************************************//**
 * @brief A callback function for refreshing the display
 ******************************************************************************/
void display()
{
    utilCentral(new DisplayEvent());
}

/***************************************************************************//**
 * @brief A callback function for handling keyboard input
 *
 * @param[in] key - the key that was pressed
 * @param[in] x   - the x-coordinate when the key was pressed
 * @param[in] y   - the y-coordinate when the key was pressed
 ******************************************************************************/
void keyboard(unsigned char key, int xCoord, int yCoord)
{
    utilCentral(new KeyboardEvent(key, xCoord, actualY(yCoord)));
}

/***************************************************************************//**
 * @brief A callback function for handling mouse click events
 *
 * @param[in] button - the mouse button pushed
 * @param[in] state  - the state of the button (i.e. GLUT_UP, GLUT_DOWN)
 * @param[in] x      - the x-coordinate when the button is pressed
 * @param[in] y      - the y-coordinate when the button is pressed
 ******************************************************************************/
void mouseClick(int button, int state, int xCoord, int yCoord)
{
    utilCentral(new MouseClickEvent(button, state, xCoord, actualY(yCoord)));
}

/***************************************************************************//**
 * @brief A callback function for handling window resize events
 *
 * @param[in] w      - new window width
 * @param[in] h      - new window height
 ******************************************************************************/
void reshape(const int w, const int h)
{
    utilCentral(new ReshapeEvent(w, h));
}

