#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private: //variables for the game mechanics class
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        
        objPos foodPos; 

        int boardSizeX;
        int boardSizeY;

    public:
        //constructors and deconstructors
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
        //methods for game mechanics
        bool getExitFlagStatus();
        void setExitTrue();
        char getInput();
        void setInput(char this_input);
        void clearInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();
        void incrementScore();
        bool getLoseFlagStatus();
        void setLoseFlag();

        //methods for food generation
        void generateFood(objPos blockOff); 
        void getFoodPos(objPos &returnPos); 

};

#endif