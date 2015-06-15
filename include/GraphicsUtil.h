#ifndef GRAPHICSUTIL_H_INCLUDED
#define GRAPHICSUTIL_H_INCLUDED

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Box2D/Box2D.h>
#include <DebugDraw.h>

#include <constants.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_GLContext glContext = NULL;
static b2World* world = NULL;

b2Body* createBody(int x, int y, bool dyn);
b2Body* addCircle(int x, int y, int radius, bool dyn);
b2Body* addRect(int x,int y,int w,int h,bool dyn);
b2Body* addBikeToWorld(int x, int y);

void drawCircle(b2Vec2 center, float radius, float angle);
void drawSquare(b2Vec2* points,b2Vec2 center,float angle);
void drawPolygon(b2Body* body);

void display();

/// Initializes all graphics stuff
/// @param title: the title of the application
bool initGraphics(const char* title, const int width, const int height);

/// Refreshes the window of the application
void refreshGraphics();

/// Close the application window
void closeGraphics();

#endif // GRAPHICSUTIL_H_INCLUDED
