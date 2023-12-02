#include "GameMechs.h"
#include "MacUILib.h"
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    loseFlag = false;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    loseFlag = false;
    score = 0;
}

GameMechs::~GameMechs()
{
    // do you need a destructor?
    //if so, deallocate all heap data members, defense against memory
    //leakage, may not need if no have heap data members
}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
    //could change later for other numbers
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}