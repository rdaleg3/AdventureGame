#ifndef ROOM_H
#define ROOM_H
#include "body.h"
#include "sensor.h"
const int DEFAULT_ROOM_WIDTH(1080);
const int DEFAULT_ROOM_HEIGHT(720);
//const BITMAP* PLAYER_SPRITE = load_bitmap ("null.bmp", NULL);
class Room
{ 
      friend class World;
public:
      explicit Room(int roomNum, int roomWidth, int roomHeight, int inZone, int puzzleSt);
      
      void drawAll(BITMAP *sb);
	  Body pullNextBody();
	  void popLastBody(); 
	  Sensor pullNextSensor();
	  void popLastSensor(); 
	  void setWidth(int w);
	  void setHeight(int h);
      int getWidth();
	  int getHeight();	  
	  void addBody(Body b);
	  void addSensor(Sensor s);
	  int getZone();
      int getRoomNumber();
      int hasPuzzle();
      int numberOfBodies();
      int numberOfSensors();
      
private:
     std::vector <Body> inRoom;
     std::vector <Sensor> sensors;
	 int puzzleStatus;
	 int roomNumber;
	 int width;
	 int height;
	 int zone;
	 

};
#endif
