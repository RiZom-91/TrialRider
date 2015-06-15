#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <list>
#include <Box2D/Box2D.h>
#include <include/Obstacle.h>

class Level
{
    public:
const float DEFAULT_GRAVITY=9.81;
        b2World* world;

        std::list<Obstacle*> obstacles;

        /// Creates a new level
        /// inputs: b2Vec2 gravity, a gravity vector
        /// outputs: none
        Level(b2Vec2 gravity);

        /// Changes the gravity of the level
        /// inputs: b2Vec2 gravity, the new gravity vector
        /// outputs: none
        void SetGravity(b2Vec2 gravity);

        /// Destructor
        /// arguments: none
        /// outputs: none
        virtual ~Level();

    protected:
    private:
};

#endif // LEVEL_H
