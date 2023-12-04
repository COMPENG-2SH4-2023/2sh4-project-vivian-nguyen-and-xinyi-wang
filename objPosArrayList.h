#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        //variables for the arraylist class
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public:
        //constructor and deconstructor
        objPosArrayList();
        ~objPosArrayList();

        //methods for snake movement
        int getSize();
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        //methods to obtain snake elements
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);
};

#endif