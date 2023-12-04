#include "objPosArrayList.h"

//constructor
objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}

//deconstructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList; //remember to use to delete all in array or else only first deleted
}

//getter method for size of array list - in this case size of snake
int objPosArrayList::getSize()
{
    return listSize;
}

//inserts a head for the snake
void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize != arrayCapacity)
    {
        for (int i = listSize; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]); //shuffles elements towards tail
        }
        aList[0].setObjPos(thisPos); //adds a piece of snake to the front
        listSize++;
    }
    
}

//adds a tail to snake
void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < arrayCapacity)
    {
        aList[listSize].setObjPos(thisPos); //no need to shuffle
        listSize++;
    }
}

//removes head
void objPosArrayList::removeHead()
{
    if (listSize > 0)
    {
        for (int i = 0; i < listSize-1; i++)
        {
            aList[i].setObjPos(aList[i+1]); //shuffles to the front of snake
        }
        listSize--;
    }
}

//removes tail of snake
void objPosArrayList::removeTail()
{
    if (listSize > 0)
    {
        listSize--;
    }
}

//gets the head element
void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

//gets tail element
void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

//gets any element in snake
void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}