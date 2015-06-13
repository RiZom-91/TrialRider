#ifndef GRAPHICSUTIL_H_INCLUDED
#define GRAPHICSUTIL_H_INCLUDED

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Box2D/Box2D.h>
#include <DebugDraw.h>

static SDL_Window* window;
static SDL_Renderer* renderer;
static SDL_GLContext glContext;
static b2World* world;


const float M2P=20;
const float P2M=1/M2P;
const int WIDTH=640;
const int HEIGHT=480;

b2Body* addRect(int x,int y,int w,int h,bool dyn);

void drawSquare(b2Vec2* points,b2Vec2 center,float angle);

void display();

/// Initializes all graphics stuff
/// @param title: the title of the application
bool initGraphics(const char* title, const int width, const int height);

/// Refreshes the window of the application
void refreshGraphics();

/// Close the application window
void closeGraphics();

#endif // GRAPHICSUTIL_H_INCLUDED
