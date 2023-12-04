#include "Player.h"


Player::Player(GameMechs* thisGMRef) //constructor for the player class
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    //draws the snake in the middle of the board with * symbol
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*');

    //keeps track of the snake body positions
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
}


Player::~Player()
{
    delete playerPosList;
    //deconstructor
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    //returns all the snake body locations
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    //gets input from the player's keyboard
    char input = mainGameMechsRef->getInput();

    //this switch statement changes the direction of the snake depending on the input
    switch(input)
    {
        //for your debugging purposes =================================
        /*case 'q': // exit
        {
            mainGameMechsRef->incrementScore();
            break;
        }
        case 'e': // exit
        {
            mainGameMechsRef->setLoseFlag();
            break;
        }*/
        
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

    //stores the current position of the head
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    //this if-else structure moves the position of the snake head
    //also implements wrap-around condition
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

    //stores the food's position
    objPos tempFoodPos;
    mainGameMechsRef->getFoodPos(tempFoodPos);

    //retrieves the tail position of the snake
    objPos* tempPosPtr = new objPos;
    playerPosList->getTailElement(*tempPosPtr);

    //if a collision occurs, the snake will incrase in size, a new food will be generated, and score increases
    if (tempFoodPos.isPosEqual(tempPosPtr))
    {
        playerPosList->insertHead(currentHead);
        mainGameMechsRef->generateFood(tempFoodPos);
        mainGameMechsRef->incrementScore();
    }
    //if no collision, the snake just moves normally (by adding head and removing tail)
    else
    {
        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
    }

    //for no memory leaks :)
    delete tempPosPtr;
}

bool Player::checkFoodConsumption()
{
    
}

void Player::increasePlayerLength()
{
    
}