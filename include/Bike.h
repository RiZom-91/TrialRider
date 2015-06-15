#ifndef BIKE_H
#define BIKE_H

#include <constants.h>
#include <Box2D/Box2D.h>
class Bike
{
    public:

        b2Body* frontWheel;
        b2Body* rearWheel;
        b2Body* frame;
        b2Body* swingarm;
        b2Body* fork;

        Bike();
        void AddBikeToWorld(b2Vec2 pos, b2World* world);
        virtual ~Bike();
    protected:
    private:
        b2Body* CreateBody(b2World* world, int x, int y, bool dyn);
};

#endif // BIKE_H
