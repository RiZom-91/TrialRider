#include "include/Level.h"

Level::Level(b2Vec2 gravity = b2Vec2(0.00f,DEFAULT_GRAVITY))
{
    world = new b2World(gravity);
}

void Level::SetGravity(b2Vec2 gravity)
{
    if (world != NULL)
        world->SetGravity(gravity);
}

Level::~Level()
{
    //dtor
}
