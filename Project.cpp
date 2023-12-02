#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
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
}

void GetInput(void)
{
    //already got for player in run logic function by using updatePlayerDir() from game mechanics. 
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

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);
    
    for (int row =0; row<myGM->getBoardSizeY(); row++)
    {
        for (int col=0; col<myGM->getBoardSizeX(); col++)
        {
            if (row == tempPos.y && col == tempPos.x)
            {
                MacUILib_printf("%c", tempPos.symbol);
            }
            else
            {
                if (row == 0||col==0||row==(myGM->getBoardSizeY()-1)||col==(myGM->getBoardSizeX()-1))
                {
                    MacUILib_printf("#");
                }
                else
                {
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d> + %c\n",
        myGM->getBoardSizeX(), myGM->getBoardSizeY(),
        tempPos.x, tempPos.y, tempPos.symbol);
    
    MacUILib_printf("Score: %d\n",
        myGM->getScore());
    
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
    delete myGM;
    delete myPlayer;
    MacUILib_clearScreen();   
    MacUILib_uninit();
}
