#include <include/GraphicsUtil.h>

bool initGraphics(const char* title = "Application", const int width = 640, const int height = 480)
{
    // Initialize SDL
    if( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }

    // Create the window of the application
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                     width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }

    // Create the renderer
    /*if (renderer== NULL) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }*/

    SDL_GL_CreateContext(window);

    // Draw a white background
    /*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);*/

    return true;
}

void refreshGraphics()
{
    SDL_GL_SwapWindow(window);
}

void closeGraphics()
{
    SDL_Quit();
    window = NULL;
    renderer = NULL;
}
