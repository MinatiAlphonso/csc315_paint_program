/***************************************************************************//**
 * @file main.cpp
 *
 * @mainpage program 1 - Paint
 *
 * @section course_section Course Information
 *
 * @author John M. Weiss, Ph.D.
 * @author Paul Hinker, Ph.D.
 * @author Sterling McKenzie
 * @author Minati Alphonso
 *
 * @date October 2, 2019
 *
 * @par Professor:
 *    Professor Hinker
 *
 * @par Course:
 *    CSC 315 - 10:00am
 *
 * @par Location:
 *    McLaury Building, Room 313
 *
 * @section program_section Program Information
 *
 * @details
 *
 * OOP example illustrating inheritance and late binding via virtual functions 
 * in C++.  Inheritance is used to derive various shape classes (Circle, 
 * Rectangle, Square) from a base Shape class.
 *
 * This version uses an STL vector to store the list of graphic objects.
 *
 * This class hierarchy was used to implement an object-oriented paint 
 * program.
 *
 * A paint program that can be used to select different shapes. The color and
 * and border of the shape can also be selected in a palette in the bottom left
 * corner of the screen. 
 *
 * This program utilizes OpenGl and GLUT to display the program in a window/GUI
 * format. Different inputs are recieved from mouse clicks and keyboard clicks
 * to determine what is done on the window.
 *
 * @par Modifications:
 *    * Added doxygen comments -- Nov. 2015 PJH
 *    * Refactoring            -- Nov. 2015 PJH
 *    * Implemented paint program -- Sept. 2019 Sterling McKenzie / Minati Alphonso
 * 
 * @bug Bugs: 
 *    * Color of previous drawn shapes sometimes changes to newly selected colors
 *    * Cannot move shapes with a select and drag
 ******************************************************************************/
#include "util.h"

int main(int argc, char** argv)
{
    initOpenGL(argc, argv, 640, 480);

    glutMainLoop();

    return 0;
}
