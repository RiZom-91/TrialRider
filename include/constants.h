#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <iostream>
#include <string>
#include <math.h>

// Global constants for the application
const unsigned short int DEFAULT_WINDOW_W = 640;
const unsigned short int DEFAULT_WINDOW_H = 480;
const float MAX_FPS = 60.0;
const float MIN_TIME_STEP = 1.0/MAX_FPS;
const float MIN_TIME_STEP_MILLISECONDS = MIN_TIME_STEP *1000;
const float M2P_RATIO=20;
const float P2M_RATIO=1/M2P_RATIO;
const float D2R_RATIO=M_PI/180.0;
const float R2D_RATIO=1/D2R_RATIO;
const float DEFAULT_GRAVITY=9.81;
const std::string TITLE = "Trial Rider";

#endif // CONSTANTS_H_INCLUDED
