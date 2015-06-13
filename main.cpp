#include <iostream>
#include <SDL2/SDL.h>
#include <include/GraphicsUtil.h>

using namespace std;

// Application settings and attributs
const char* TITLE = "Trial Rider";
const unsigned int WINDOW_W = 640;
const unsigned int WINDOW_H = 480;
const Uint16 MAX_FPS_MS = 1000/60;
const Uint16 MAX_FPS = 1/60;

int main()
{
    if (initGraphics(TITLE, WINDOW_W, WINDOW_H) == false)
        return 1;

    bool running = true;
    Uint32 start;
    Uint32 interval = 0;
    SDL_Event event;

    while(running)
    {
        start = SDL_GetTicks();

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running=false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            running=false;
                            break;
                        }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    addRect(event.button.x,event.button.y,20,20,true);
                    break;

            }
        }

        refreshGraphics();

        interval = SDL_GetTicks() - start;
        cout << "Interval: " << interval << "ms\n";
        if(interval < MAX_FPS_MS)
            SDL_Delay(MAX_FPS_MS - interval);
    }

    return 0;
}
