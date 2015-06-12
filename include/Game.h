#ifndef GAME_H
#define GAME_H

#include <include/Level.h>
#include <include/Rider.h>
#include <include/Bike.h>

class Game
{
    public:

        Level* level;
        Rider* rider;
        Bike* bike;

        /// Creates a new empty game
        /// inputs: none
        /// outputs: none
        Game();

        /// Destructor
        /// inputs: none
        /// outputs: none
        virtual ~Game();
    protected:
    private:
};

#endif // GAME_H
