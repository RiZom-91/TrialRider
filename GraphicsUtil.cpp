#include <include/GraphicsUtil.h>

b2Body* addRect(int x,int y,int w,int h,bool dyn=true)
{
        b2BodyDef bodydef;
        bodydef.position.Set(x*P2M,y*P2M);
        if(dyn)
                bodydef.type=b2_dynamicBody;
        b2Body* body=world->CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox(P2M*w/2,P2M*h/2);

        b2FixtureDef fixturedef;
        fixturedef.shape=&shape;
        fixturedef.density=1.0;
        body->CreateFixture(&fixturedef);

}

void drawSquare(b2Vec2* points,b2Vec2 center,float angle)
{
        glColor3f(1,1,1);
        glPushMatrix();
                glTranslatef(center.x*M2P,center.y*M2P,0);
                glRotatef(angle*180.0/M_PI,0,0,1);
                glBegin(GL_QUADS);
                        for(int i=0;i<4;i++)
                                glVertex2f(points[i].x*M2P,points[i].y*M2P);
                glEnd();
        glPopMatrix();
}

void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        b2Body* tmp=world->GetBodyList();
        b2Vec2 points[4];
        while(tmp)
        {
                for(int i=0;i<4;i++)
                        points[i]=((b2PolygonShape*)tmp->GetFixtureList()->GetShape())->GetVertex(i);

                drawSquare(points,tmp->GetWorldCenter(),tmp->GetAngle());
                tmp=tmp->GetNext();
        }
}

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
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer== NULL) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }

    glContext = SDL_GL_CreateContext(window);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,WIDTH,HEIGHT,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0,0,0,1);

    world=new b2World(b2Vec2(0.0,-9.81));
    DebugDraw* debugDraw = new DebugDraw(1/20);
    world->SetDebugDraw(debugDraw);

    addRect(WIDTH/2,HEIGHT-50,WIDTH,30,false);

    // Draw a white background
    /*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);*/

    return true;
}

void refreshGraphics()
{
    display();
    world->Step(1/60, 8,3);
    //world->DrawDebugData();
    SDL_GL_SwapWindow(window);
}

void closeGraphics()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    SDL_GL_DeleteContext(glContext);
    window = NULL;
    renderer = NULL;
    glContext = NULL;
}
