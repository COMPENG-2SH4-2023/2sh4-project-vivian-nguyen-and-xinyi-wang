#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

//global variables!
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

    myGM = new GameMechs (36, 18); //change board size here
    myPlayer = new Player (myGM);
    
    //generates initial food position
    objPos tempPlayerPos {-1, -1, 'o'}; 
    myGM->generateFood(tempPlayerPos);
}

void GetInput(void)
{
    //gets input from the player
    myGM->getInput();
}

void RunLogic(void)
{
    //calculates the player's position depending on input
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();

}

void DrawScreen(void)
{
    //repeatedly clears screen to give appearance of animation
    MacUILib_clearScreen();    

    bool drawn; //bool to ensure that once we draw a piece of the snake, we don't draw whitespace/border/food, etc.

    //stores the positions of the snake body on the board
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    //stores the position of the food object on the board
    objPos tempFoodPos;
    myGM->getFoodPos(tempFoodPos);
    
    //goes through each row and column to draw the player, food, border, and whitespace
    for (int row =0; row<myGM->getBoardSizeY(); row++)
    {
        for (int col=0; col<myGM->getBoardSizeX(); col++)
        {   
            //draws snake body
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

            //draws food, border and white space
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
    
    /*
    if (myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("loss");
    }*/
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
