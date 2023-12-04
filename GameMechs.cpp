#include "GameMechs.h"
#include "MacUILib.h"
GameMechs::GameMechs() //default constructor
{
    input = 0;
    exitFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    loseFlag = false;
    score = 0;

    foodPos.setObjPos(-1, -1, 'o'); 
}

GameMechs::GameMechs(int boardX, int boardY) //constructor where u can specify board size.
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    loseFlag = false;
    score = 0;
    foodPos.setObjPos(-1, -1, 'o'); 
}

GameMechs::~GameMechs()
{
    //did not end up needing a destructor
}

//getter method for exit flag
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    //gets input from the keyboard, and immediately checks if we should exit the game.
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
        if (input == 27)
        {
            setExitTrue();
        }
    }
    return input;
}

//getter method for board width
int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

//getter method for board height
int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

//setter method for exit flag
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

//setter method keyboard input
void GameMechs::setInput(char this_input)
{
    input = this_input;
}

//clears input; ensures we don't have double input in main project code (can cause errors)
void GameMechs::clearInput()
{
    input = 0;
}

//getter method for score
int GameMechs::getScore()
{
    return score;
}

//increases score by one when called
void GameMechs::incrementScore()
{
    score++;
}

//getter method for loseFlag
bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

//setter method for loseFlag
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

//generates a "new" food item by resetting the food's position.
void GameMechs::generateFood(objPos blockOff) 
{
    srand(time(NULL));
    int candidateX =-1;
    int candidateY=-1;

    do
    {
        candidateX = (rand()%(boardSizeX-2))+1; 
        candidateY = (rand()%(boardSizeY-2))+1; 
        foodPos.setObjPos(candidateX, candidateY, 'o');

    } while (foodPos.isPosEqual(&blockOff));
    
}

//returns the food's position
void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}