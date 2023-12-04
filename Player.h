#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // direction state

        //constructor and deconstructor
        Player(GameMechs* thisGMRef);
        ~Player();

        //methods for moving the snake
        objPosArrayList* getPlayerPos();
        void updatePlayerDir();
        void movePlayer();

        //methods for collision
        bool checkFoodConsumption();
        void increasePlayerLength();

    private:
        objPosArrayList *playerPosList; //stores the snake's locations
        enum Dir myDir; //stores current direction
        GameMechs* mainGameMechsRef; //allows us to access the game mechanics class
};

#endif