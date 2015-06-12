#ifndef B2OBJECT_H
#define B2OBJECT_H

#include <Box2D/Box2D.h>

class b2Object
{
    public:

        b2World* world;
        b2BodyDef bodyDef;
        b2Body* body;

        b2Object();
        virtual ~b2Object();
    protected:
    private:
};

#endif // B2OBJECT_H
