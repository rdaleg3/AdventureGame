#ifndef SENSOR_H
#define SENSOR_H

//#include "card.h"
//#include "deck.h"
//#include "character.h"

//const int STARTING_HAND_SIZE(3);

class Sensor
{ 
      friend class World;
      friend class Room;
public:
      explicit Sensor();
      explicit Sensor(int typ, int val, int xpos, int ypos, int w, int h, bool show);
      void draw(BITMAP *sb);
      void setType (int ty);
      int getX();
      int getY();
      int getWidth();
      int getHeight();
      bool overlaps(int x, int y, int w, int h);
      void setX(int new_x);
      void setY(int new_y);
      void setPosition (int new_x, int new_y);
      void setWidth(int new_w);
      void setHeight(int new_h);
      int getType();
      int getValue();
      bool isHidden();
      void setSprite(std::string dir);
      
private:
        int x;
        int y;
        int width;
        int height;
        int type;
        int value;
        bool hidden;
        BITMAP * sprite;
        int facing;
        

};
#endif
