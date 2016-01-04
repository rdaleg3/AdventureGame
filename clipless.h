#ifndef CLIPLESS_H
#define CLIPLESS_H
#include <allegro.h>
#include <vector>
#include <iostream>
#include <fstream>
//#include "card.h"
//#include "deck.h"
//#include "character.h"

//const int STARTING_HAND_SIZE(3);



class Clipless
{ 
      friend class World;
      friend class Room;
public:
      explicit Clipless();
      explicit Clipless(std::string ud, int w, int h );
      void draw(BITMAP *sb);  
      void setType (int ty);
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
      void setSprite(std::string dir);
      void setSprite(BITMAP* new_sprite);
      
private:
        double x;
        double y;
        int width;
        int height;
        int shape;
        std::string userData;
        int type;
        BITMAP * sprite
        

};
#endif
