#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs (36, 18); //board size
    myPlayer = new Player (myGM);
    
    objPos tempPlayerPos {-1, -1, 'o'};
    myGM->generateFood(tempPlayerPos);
    //problems after here
    
    //think of when to gen new food; in ppa3 we gen in init and somewhere
    //think if u want to set a debug key to call the food gen routine for verification
    //rmbr gen food requires player reference. provide after player obj is instantiated.
}

void GetInput(void)
{
    //already got for player in run logic function by using updatePlayerDir() from game mechanics. 
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    myGM->getFoodPos(tempFoodPos);
    
    for (int row =0; row<myGM->getBoardSizeY(); row++)
    {
        for (int col=0; col<myGM->getBoardSizeX(); col++)
        {   
            drawn = false;
            for (int k = 0; k<playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if (tempBody.x ==col&&tempBody.y==row)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }
            if (drawn) continue;

            if (row == tempFoodPos.y && col == tempFoodPos.x)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else if (row == 0||col==0||row==(myGM->getBoardSizeY()-1)||col==(myGM->getBoardSizeX()-1))
            {
                MacUILib_printf("#");
            }
            else
            {
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n", myGM->getScore());
    
    if (myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("loss");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    delete[] myGM;
    delete[] myPlayer;
    MacUILib_clearScreen();   
    MacUILib_uninit();
}
