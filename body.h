#ifndef BODY_H
#define BODY_H
#include <allegro.h>
#include <vector>
#include <iostream>
#include <fstream>
//#include "card.h"
//#include "deck.h"
//#include "character.h"

//const int STARTING_HAND_SIZE(3);



class Body
{ 
      friend class World;
public:
      explicit Body();
      explicit Body(std::string ud, int w, int h );
      //explicit Body(std::string ud, double xpos, double ypos, int w, int h, bool spriteSheet, int ssX, int ssY, int ssW, int ssH);
      void draw(BITMAP *sb);
      bool updateWorld();  
      void setType (int ty);
      void addMask (int m);
      void subtractMask (int mask_to_remove);
      int getX();
      int getY();
      int getWidth();
      int getHeight();
      int overlaps(int x1, int y1, int w1, int h1);
      void setX(double new_x);
      void setY(double new_y);
      void setPosition (double new_x, double new_y);
      void setWidth(int new_w);
      void setHeight(int new_h);
      int getType();
      std::string getUserData();
      bool isDynamic();
      void setSprite(std::string dir);
      void setSprite(BITMAP* new_sprite);
      
private:
        double x;
        double y;
        int width;
        int height;
        int shape;
        std::string userData;
        std::vector <int> mask;
        int type;
        bool dynamic;
        bool isSensor;
        BITMAP * sprite;
        int facing;
        

};
#endif
