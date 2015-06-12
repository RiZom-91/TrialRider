#ifndef GRAPHICSUTIL_H_INCLUDED
#define GRAPHICSUTIL_H_INCLUDED

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

static SDL_Window* window;
static SDL_Renderer* renderer;

/// Initializes all graphics stuff
/// @param title: the title of the application
bool initGraphics(const char* title, const int width, const int height);

/// Refreshes the window of the application
void refreshGraphics();

/// Close the application window
void closeGraphics();

#endif // GRAPHICSUTIL_H_INCLUDED
