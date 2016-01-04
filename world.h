#ifndef WORLD_H
#define WORLD_H
#include <allegro.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "body.h"
#include "room.h"
#include "textbox.h"
//#include "character.h"

const double SCROLL_X_BY(.5);
const double SCROLL_Y_BY(.5);
const int NUMBER_OF_EVENTS(5);
const int DEFAULT_WIDTH(1080);
const int DEFAULT_HEIGHT(720);
const int NUMBER_OF_ROOMS(80);
//const BITMAP* PLAYER_SPRITE = load_bitmap ("null.bmp", NULL);
class World
{ 
      friend class Game;
public:
      explicit World();
      explicit World(int worldWidth, int worldHeight);

      //bool updateWorld();
	  //int createNewEvent(int event_code); 
	  //bool handleEvents();
	  void clearAll();
	  void drawAll(BITMAP *sb);
	  void setWidth(int w);
	  void setHeight(int h);	  
	  void setCameraX(int cx);
	  void setCameraY(int cy);
	  void addBody(Body b);
	  void update(int dt);
	  //bool resolveColisions();
	  //bool colide();
	  std::string getColisionData();
      void loadRoom(int roomNumber);
      int getCameraX();
      int getCameraY();
      int getPlayerX();
      int getPlayerY();
      void buildAllRooms(); 
      void setHat (int hatID);
	  void drawHat(BITMAP *draw); 
      int getRoom();
      int getHat();
      void drawPlayer(BITMAP* pl);
      
private:
     std::vector <Body> inWorld;
	 //BITMAP *worldSpace;
	 //std::vector <Body> clipless;
	 //std::vector <int> events;
	 std::vector <Room> roomLibrary;
	 int colisionWithIndex;
	 bool eventBooleans[NUMBER_OF_EVENTS];
	 int cameraX;   
	 int cameraY;
	 int playerFacing;
	 Body player;
	 int width;
	 int height;
	 int frame;
	 int zone;
	 int inRoom;
	 bool messageQued;
	 //BITMAP * hatSprite;
	 int hatFrame;
	 int hat;
	 std::string messageBox;
	 bool roomTriggers[NUMBER_OF_ROOMS][10];
	 int debugValueA;
	 int debugValueB;
	 int debugValueC;
	 int debugValueD;
	 int debugValueE;
	 int debugValueF;
	 BITMAP* hatE;
	 BITMAP* hatW;
     BITMAP* hatN;
	 BITMAP* hatS;
	 BITMAP* playerE;
	 BITMAP* playerW;
     BITMAP* playerN;
	 BITMAP* playerS;
     bool playerCanMoveN;
     bool playerCanMoveS;
     bool playerCanMoveE;
     bool playerCanMoveW;
     BITMAP* zoneFloor;

};
#endif
