#include <iostream>
#include <SDL2/SDL.h>
#include <include/GraphicsUtil.h>
#include <Settings.h>
#include <constants.h>

using namespace std;

int main()
{
    Settings* settings = new Settings();

    if (initGraphics(TITLE.c_str(), settings->get_window_w(), settings->get_window_h()) == false)
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
                {
                    running=false;
                }
                break;

                case SDL_KEYDOWN:
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            running=false;
                            break;
                        }
                }
                break;

                case SDL_MOUSEBUTTONDOWN:
                {
                    switch(event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            addRect(event.button.x,event.button.y,20,20,true);
                            break;
                        case SDL_BUTTON_RIGHT:
                            addBikeToWorld(event.button.x, event.button.y);
                            //addCircle(event.button.x,event.button.y,20,true);
                            break;

                    }
                }
                break;
            }
        }

        refreshGraphics();

        interval = SDL_GetTicks() - start;
        if(interval < MIN_TIME_STEP_MILLISECONDS) {
            SDL_Delay(MIN_TIME_STEP_MILLISECONDS - interval);
            cout << "60 FPS\n;";
        }
        else {
            cout << 1000.0/interval << " FPS\n;";
        }
    }

    return 0;
}
