#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2,'*');

    // no heap member yet wait for it. 3 to add
}


Player::~Player()
{
    // delete any heap members here
    //will add in it. 3
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    //where do i get input how do i check for input? hint:
    //def not by calling mac ui lib get char()
    //coordinate with ur teammember who is designing game mechanism class
    //there will be game mechanism class that collectively check input and store most recent input
    //u just need to figure how to get to it. how? it lies within GameMechs*
    //inside ur private member
    char input = mainGameMechsRef->getInput();
    
    switch(input)
    {
        case 27: // exit
        {
            mainGameMechsRef->setExitTrue();
            break;
        }
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
    if (myDir == UP)
    {
        if (playerPos.y>1)
        {
            playerPos.y--;
        }
        else
        {
            playerPos.y = (mainGameMechsRef->getBoardSizeY())-2;
        }
    }
    else if (myDir==DOWN)
    {
        if (playerPos.y<(mainGameMechsRef->getBoardSizeY())-2)
        {
            playerPos.y++;
        }
        else
        {
            playerPos.y = 1;
        }
    }
    else if (myDir==LEFT)
    {
        if (playerPos.x>1)
        {
            playerPos.x--;
        }
        else
        {
            playerPos.x = (mainGameMechsRef->getBoardSizeX())-2;
        }
    }
    else if (myDir==RIGHT)
    {
        if (playerPos.x<(mainGameMechsRef->getBoardSizeX())-2)
        {
            playerPos.x++;
        }
        else
        {
            playerPos.x = 1;
        }
    }
}

