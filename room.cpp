#include "room.h"
Room::Room(int roomNum, int roomWidth, int roomHeight, int inZone, int puzzleSt)
{
     puzzleStatus = puzzleSt;
	 roomNumber = roomNum;
	 width = roomWidth;
	 height = roomHeight;
	 zone = inZone;
	 if (zone == 1)
	 {
	    for (double i = 0; i < width; i = i + 476)
	    {
	           Body northWall ("wall", 476, 32);
               northWall.setPosition(i-1 , 0);
			   northWall.setSprite("wallZone1.bmp");
               inRoom.push_back(northWall);
      	 }
	  }
	 Body southWall ("wall", width, 5);
	 southWall.setPosition(0 ,height-5);
	 southWall.setSprite("southWall.bmp");
     inRoom.push_back(southWall);
	 
	 Body eastWall ("wall", 5, height);
	 eastWall.setPosition(width-5 , 0);
	 eastWall.setSprite("EWWall.bmp");
	 inRoom.push_back(eastWall);
	 
     Body westWall ("wall", 5, height);
   	 westWall.setPosition(0 ,0);
   	 westWall.setSprite("EWWall.bmp");
	 inRoom.push_back(westWall);
}
Body Room::pullNextBody()
{
     return inRoom.back();
}
void Room::popLastBody()
{
 	 inRoom.pop_back();
}
 	 
void Room::setWidth(int w)
{
     width = w;
}
void Room::setHeight(int h)	  
{
     height = h;
}
int Room::getWidth()
{
     return width;
}
int Room::getHeight()	  
{
     return height;
}
void Room::addBody(Body b)
{
     inRoom.push_back(b);
}
int Room::getRoomNumber()
{
    return roomNumber;
}
int Room::hasPuzzle()
{
    return puzzleStatus;
}
int Room::numberOfBodies()
{
    return inRoom.size();
}

int Room::getZone()
{
     return zone;
}


