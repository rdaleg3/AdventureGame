#include "sensor.h"

using namespace std;
Sensor::Sensor()
{
                
        x = 5;
        y = 5;
        width = 5;
        height = 5;
        value = -1;
        type = -1;
        hidden = true;

}
Sensor::Sensor(int typ, int val, int xpos, int ypos, int w, int h, bool show)
{
                
        x = xpos;
        y = ypos;
        width = w;
        height = h;
        value = val;
        type = typ;
        hidden = !show;         

}
void Sensor::draw(BITMAP *sb)
{
                
   if (!hidden)
   {
         masked_stretch_blit(sprite, sb, 0, 0, sprite->w, sprite->h, x, y, width, height);  
   }           

}
void Sensor::setType (int ty)
{
                
      type = ty;          

}
int Sensor::getX()
{
                
    return  x;

}
int Sensor::getY()
{
                
    return  y;                

}
int Sensor::getWidth()
{
                
    return  width;                

}
int Sensor::getHeight()
{
    return  height;

}
bool Sensor::overlaps(int x1, int y1, int w1, int h1)
{
                
   return (x1 + w1 > x && x1 < x+width && y1+ h1 > y && y1 < y + height);             

}
void Sensor::setX(int new_x)
{
                
    x = new_x;            

}
void Sensor::setY(int new_y)
{
                
    y = new_y;                

}
void Sensor::setPosition (int new_x, int new_y)
{
                
    x = new_x;
    y = new_y;                

}
void Sensor::setWidth(int new_w)
{
                
     width = new_w;               

}
void Sensor::setHeight(int new_h)
{
                
  height = new_h;           

}
int Sensor::getType()
{
                
   return type;             

}
int Sensor::getValue()
{
                
      return value;          

}
bool Sensor::isHidden()
{
                
       return hidden;         

}
void Sensor::setSprite(std::string dir){
                
                sprite = load_bitmap(dir.c_str(), NULL);

}
