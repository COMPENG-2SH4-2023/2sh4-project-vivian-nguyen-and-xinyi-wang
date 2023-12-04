#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos();
        void updatePlayerDir();
        void movePlayer();

        //need more actions in here: after inserting head and removing the tail...
        //- check if player's new head position collides with food.
        // if yes increment score in gm , generate new food, do not remove tail
        // else remove tail and move on

        //add self collision
        // if self collide, set loseFlag and exitflag true through GM
        // if ending u need to differentiate the end game state
        // - lost - duisplay lost messsage
        // otherwise display end game message only

    private:
        objPosArrayList *playerPosList; 
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif