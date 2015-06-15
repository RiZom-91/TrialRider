#include <include/GraphicsUtil.h>

b2Body* createBody(int x, int y, bool dyn=true)
{
    b2BodyDef bodydef;
    bodydef.position.Set(x*P2M_RATIO,y*P2M_RATIO);
    if(dyn)
        bodydef.type=b2_dynamicBody;
    b2Body* body=world->CreateBody(&bodydef);

    return body;
}

b2Body* addCircle(int x, int y, int radius, bool dyn=true)
{
    //b2Body* body=createBody(x, y, dyn);
    /*b2PolygonShape frameShape;
    b2Vec2* points;
    points[0].Set(x*P2M_RATIO-0.1, y*P2M_RATIO+0.1);
    points[1].Set(x*P2M_RATIO+0.1, y*P2M_RATIO+0.1);
    points[2].Set(x*P2M_RATIO+0.3, y*P2M_RATIO-0.3);
    points[3].Set(x*P2M_RATIO-0.3, y*P2M_RATIO-0.3);
    frameShape.Set(points, 4);
    b2FixtureDef fixturedef;
    fixturedef.shape=&frameShape;
    fixturedef.density=1.0;
    body->CreateFixture(&fixturedef);*/

    b2Body* body=createBody(x, y, dyn);
    b2CircleShape shape;
    shape.m_radius = radius*P2M_RATIO;

    b2FixtureDef fixturedef;
    fixturedef.shape=&shape;
    fixturedef.density=1.0;
    fixturedef.friction=1.0;
    body->CreateFixture(&fixturedef);

    //return body;
}

b2Body* addBikeToWorld(int x, int y)
{
    b2Body* body = createBody(x, y, true);
    b2PolygonShape frameShape;
    b2Vec2 points[8];
    points[0].Set(2.8f, 10.0f-4.8f);
    points[1].Set(3.4f, 10.0f-4.5f);
    points[2].Set(4.5f, 10.0f-2.5f);
    points[3].Set(5.7f, 10.0f-2.4f);
    points[4].Set(7.7f, 10.0f-4.8f);
    points[5].Set(9.4f, 10.0f-5.5f);
    points[6].Set(5.8f, 10.0f-5.2f);
    points[7].Set(3.4f, 10.0f-6.2f);
    frameShape.Set(points, 8);
    b2FixtureDef fixturedef;
    fixturedef.shape=&frameShape;
    fixturedef.density=1.0;
    body->CreateFixture(&fixturedef);

    return body;
}

b2Body* addRect(int x,int y,int w,int h,bool dyn=true)
{
    b2Body* body=createBody(x, y, dyn);

    b2PolygonShape shape;
    shape.SetAsBox(P2M_RATIO*w/2,P2M_RATIO*h/2);

    b2FixtureDef fixturedef;
    fixturedef.shape=&shape;
    fixturedef.density=1.0;
    body->CreateFixture(&fixturedef);

    return body;
}

void drawCircle(b2Vec2 center, float radius, float angle)
{
    glColor3f(1,1,1);
    glPushMatrix();
    glLineWidth(1.0);
    glTranslatef(center.x*M2P_RATIO,center.y*M2P_RATIO,0);
    glRotatef(angle*R2D_RATIO,0,0,1);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(radius*M2P_RATIO, 0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    for (int i=0; i < 360; i++)
    {
        float degInRad = i*D2R_RATIO;
        glVertex2f(cos(degInRad)*radius*M2P_RATIO,sin(degInRad)*radius*M2P_RATIO);
    }

    glEnd();
    glPopMatrix();
}

void drawSquare(b2Vec2* points, b2Vec2 center,float angle)
{
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(center.x*M2P_RATIO,center.y*M2P_RATIO,0);
    glRotatef(angle*R2D_RATIO,0,0,1);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++)
        glVertex2f(points[i].x*M2P_RATIO,points[i].y*M2P_RATIO);
    glEnd();
    glPopMatrix();
}

void drawPolygon(b2Body* body)
{
    b2PolygonShape* poly = (b2PolygonShape*) body->GetFixtureList()->GetShape();
    float angle = body->GetAngle();
    b2Vec2 center = body->GetWorldCenter();

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(center.x*M2P_RATIO,center.y*M2P_RATIO,0);
    glRotatef(angle*R2D_RATIO,0,0,1);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(poly->GetVertex(0).x*M2P_RATIO, poly->GetVertex(0).y*M2P_RATIO);
    glEnd();
    glBegin(GL_LINE_LOOP);

    int vertexCount = poly->GetVertexCount();
    b2Vec2 line;
    for (int i=0; i<vertexCount; i++)
    {
        line = poly->GetVertex(i);
        glVertex2f(line.x*M2P_RATIO,line.y*M2P_RATIO);
    }
    glEnd();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    b2Body* tmp=world->GetBodyList();

    while(tmp)
    {
        switch (tmp->GetFixtureList()->GetShape()->GetType())
        {
            case b2Shape::e_circle:
            {
                b2CircleShape* circle = (b2CircleShape*) tmp->GetFixtureList()->GetShape();
                drawCircle(tmp->GetWorldCenter(), circle->m_radius, tmp->GetAngle());
            }
            break;

            case b2Shape::e_polygon:
            {
                drawPolygon(tmp);
            }
            break;
        }
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
                     width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
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
    glOrtho(0,DEFAULT_WINDOW_W,DEFAULT_WINDOW_H,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0,0,0,1);

    world=new b2World(b2Vec2(0.0,DEFAULT_GRAVITY));
    DebugDraw* debugDraw = new DebugDraw(1/20);
    world->SetDebugDraw(debugDraw);

    addRect(DEFAULT_WINDOW_W/2,DEFAULT_WINDOW_H-50,DEFAULT_WINDOW_W,30,false);

    return true;
}

void refreshGraphics()
{
    display();
    world->Step(1.0/60.0, 8, 3);
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
