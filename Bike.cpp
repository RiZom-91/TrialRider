#include "include/Bike.h"

Bike::Bike()
{
    //ctor
}

void Bike::AddBikeToWorld(b2Vec2 pos, b2World* world)
{
    frame = CreateBody(world, pos.x, pos.y, true);
    b2PolygonShape frameShape;
    b2Vec2* points;
    points[0].Set(pos.x-0.1, pos.y+0.1);
    points[1].Set(pos.x+0.1,pos.x+0.1);
    points[2].Set(pos.x+0.3, pos.y-0.3);
    points[3].Set(pos.x-0.3, pos.y-0.3);
    frameShape.Set(points, 4);
    b2FixtureDef fixturedef;
    fixturedef.shape=&frameShape;
    fixturedef.density=1.0;
    frame->CreateFixture(&fixturedef);
}

b2Body* Bike::CreateBody(b2World* world, int x, int y, bool dyn=true)
{
    b2BodyDef bodydef;
    bodydef.position.Set(x*P2M_RATIO,y*P2M_RATIO);
    if(dyn)
        bodydef.type=b2_dynamicBody;

    b2Body* body=world->CreateBody(&bodydef);

    return body;
}

Bike::~Bike()
{
    //dtor
}
