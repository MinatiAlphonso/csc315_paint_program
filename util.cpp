/***************************************************************************//**
 * @file util.cpp provide by Dr. Hinker in Glut Example Code
 ******************************************************************************/
#include "util.h"
#include "callbacks.h"
/***************************************************************************//**
 * @brief Main event dispatch function
 *
 * Any events to which the application has subscribed will be routed through
 * this function.
 *
 * @param[in] event - Pointer to an Event object.
 ******************************************************************************/
void utilCentral(Event *event)
{
    static vector<Shape*> shapes;
    event->doAction(shapes);

    delete event;
}

/***************************************************************************//**
 * Initialize glut callback functions, set the display mode, create a window
 ******************************************************************************/
void initOpenGL(int argc, char ** argv, int wCols, int wRows)
{
    glutInit(&argc, argv);

    // Choose the display mode for the window.  GLUT_DOUBLE means double buffering
    // GLUT_SINGLE is single buffering.  GLUT_RGBA is 24-bit color with 8-bit alpha
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);

    // Set window size and postion
    glutInitWindowSize(wCols, wRows);

    glutInitWindowPosition(100, 100);

    glutCreateWindow(argv[0]);

    // Subscribe to GLUT events
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouseClick);

    glutReshapeFunc(reshape);

    // Set the clear color (The color the window gets painted when the glClear function gets 		// called) 0, 0, 0, 0 is black
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Use the InitEvent object perform startup operations for the app
    utilCentral(new InitEvent(wCols, wRows));
}
