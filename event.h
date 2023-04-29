/***************************************************************************//**
 * @file event.h provide by Dr. Hinker in Glut Example Code
 ******************************************************************************/
#ifndef _EVENT_H_
#define _EVENT_H_
#include <iostream>
#include <GL/freeglut.h>
#include <sstream>
#include "graphics.h"
#include "filledrectangle.h"
#include "filledellipse.h"
#include "line.h"
#include <vector>
using namespace std;

#define ESCAPE_KEY 27
#define LOWERCASE_Q 113
#define LOWERCASE_C 99
#define LOWERCASE_D 100

/***************************************************************************//**
 * @class Event
 ******************************************************************************/
class Event
{
public:
    virtual void doAction(std::vector<Shape*> &shapes) = 0;
    virtual ~Event();
};

class InitEvent : public Event
{
    int columns, rows;
public:
    InitEvent(int, int);

    void doAction(std::vector<Shape*> &shapes);
};

/***************************************************************************//**
 * @class Display Event
 ******************************************************************************/
class DisplayEvent : public Event
{
public:
    void doAction(std::vector<Shape*> &shapes);
};

/***************************************************************************//**
 * @class Keyboard Event
 ******************************************************************************/
class KeyboardEvent : public Event
{
    // The key involved in this event
    unsigned char key;
    // The x-location of where the event took place
    int xLoc;
    // The y-location of where the event took place
    int yLoc;

public:
    // Constructor
    KeyboardEvent(unsigned char, int, int);

    void doAction(std::vector<Shape*> &shapes);
};

/***************************************************************************//**
 * @class Mouse Click Event
 ******************************************************************************/
class MouseClickEvent : public Event
{
    // The button involved in the event
    int button;
    // The state of the button for this event (e.g. up, down)
    int state;
    // The x-location of where the event took place
    int xLoc;
    // The y-location of where the event took place
    int yLoc;

public:
    // Constructor
    MouseClickEvent(int, int, int, int);

    void doAction(std::vector<Shape*> &shapes);
};

/***************************************************************************//**
 * @class Reshape Window Event
 ******************************************************************************/
class ReshapeEvent : public Event
{
    int width;
    int height;
public:
    ReshapeEvent(int, int);

    void doAction(std::vector<Shape*> &shapes);
};


#endif
