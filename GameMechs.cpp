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

    foodPos.setObjPos(-1, -1, 'o'); //init outside game board remove later
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    loseFlag = false;
    score = 0;
    foodPos.setObjPos(-1, -1, 'o'); //init outside game board remove later - also think about where to seed the rng
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
        if (input == 27)
        {
            setExitTrue();
        }
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

void GameMechs::generateFood(objPos blockOff) //remove
{
    //generate random x and y coord and make sure they are not border or blockoff position
    //check x and y against  0 and boardsize x and y
    // remember objPos class has is posequal; use isntead of comparing element by element
    srand(time(NULL));
    int candidateX =-1;
    int candidateY=-1;

    do
    {
        candidateX = (rand()%(boardSizeX-2))+1; //17
        candidateY = (rand()%(boardSizeY-2))+1; //7
        
    } while (blockOff.isPosEqual(&foodPos));

    foodPos.setObjPos(candidateX, candidateY, 'o');

}

void GameMechs::getFoodPos(objPos &returnPos) //remove
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}