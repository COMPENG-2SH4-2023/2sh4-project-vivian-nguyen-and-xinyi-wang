#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2,'*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    char input = mainGameMechsRef->getInput();
    
    switch(input)
    {
        //remove later =================================
        case 'q': // exit
        {
            mainGameMechsRef->incrementScore();
            break;
        }
        case 'e': // exit
        {
            mainGameMechsRef->setLoseFlag();
            break;
        }
        
        //=============================================
        case 'w':
        {
            if (myDir == STOP||myDir == LEFT||myDir==RIGHT)
            {
                myDir = UP;
            } 
            
            break;
        }
        case 'a':
        {
            if (myDir == STOP||myDir == UP||myDir==DOWN)
            {
                myDir = LEFT;
            } 
            break;
        }
        case 's':
        {
            if (myDir == STOP||myDir == LEFT||myDir==RIGHT)
            {
                myDir = DOWN;
            } 
            break;
        }
        case 'd':
        {
            if (myDir == STOP||myDir == UP||myDir==DOWN)
            {
                myDir = RIGHT;
            } 
            break;
        }
        default:
        {
            break;
        }
    }       
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    if (myDir == UP)
    {
        if (currentHead.y>1)
        {
            currentHead.y--;
        }
        else
        {
            currentHead.y = (mainGameMechsRef->getBoardSizeY())-2;
        }
    }
    else if (myDir==DOWN)
    {
        if (currentHead.y<(mainGameMechsRef->getBoardSizeY())-2)
        {
            currentHead.y++;
        }
        else
        {
            currentHead.y = 1;
        }
    }
    else if (myDir==LEFT)
    {
        if (currentHead.x>1)
        {
            currentHead.x--;
        }
        else
        {
            currentHead.x = (mainGameMechsRef->getBoardSizeX())-2;
        }
    }
    else if (myDir==RIGHT)
    {
        if (currentHead.x<(mainGameMechsRef->getBoardSizeX())-2)
        {
            currentHead.x++;
        }
        else
        {
            currentHead.x = 1;
        }
    }

    objPos tempFoodPos;
    mainGameMechsRef->getFoodPos(tempFoodPos);

    objPos* tempPosPtr = new objPos;
    playerPosList->getTailElement(*tempPosPtr);

    if (tempFoodPos.isPosEqual(tempPosPtr))
    {
        playerPosList->insertHead(currentHead);
        mainGameMechsRef->generateFood(tempFoodPos);
    }
    else
    {
        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
    }

    delete tempPosPtr;
}

bool Player::checkFoodConsumption()
{
    
}

void Player::increasePlayerLength()
{
    
}