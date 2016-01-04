#include "body.h"
using namespace std;
Body::Body()
{
        x = 5.4;
        y = 5.5;
        width = 50;
        height = 50;
        shape = 4;
        userData = "";
        type = 0;
        sprite = load_bitmap ("null.bmp", NULL);
        dynamic = false;
        isSensor = false;
        size_t found = userData.find("sensor");
        if (found!=string::npos)
           isSensor = true;
        
        
}
Body::Body(string ud, int w, int h )
{
        x = 5.0;
        y = 5.0;
        width = w;
        height = h;
        shape = 4;
        userData = ud;
        type = 0;
        if (ud.compare("player") == 0)
           sprite = load_bitmap ("player.bmp", NULL);
        else if (ud.compare("door") == 0)
           sprite = load_bitmap ("door.bmp", NULL);
        else   
           sprite = load_bitmap ("null.bmp", NULL);    
        dynamic = false;
        isSensor = false;
        size_t found = userData.find("sensor", 0);
        if (found!=string::npos)
           isSensor = true;
}



void Body::draw(BITMAP *sb)
{
     masked_stretch_blit(sprite, sb, 0, 0, sprite->w, sprite->h, (int)x, (int)y, width, height);
}
void Body::setType (int ty)
{
 	 type = ty;
}

void Body::addMask (int m)
{
 	 mask.push_back(m);
}

void Body::subtractMask (int mask_to_remove)
{
 	 vector <int> temp;
 	 for (int m = 0; m < mask.size(); m++)
 	 {
	  	 if (mask[m] != mask_to_remove)
	  	 {
		  			 temp.push_back(mask[m]);
		 }
	 }
	 mask.swap(temp);
}
int Body::getX()
{
 	return (int) x;
}
int Body::getY()
{
 	return (int) y;
}      
int Body::getWidth()
{
 	return width;
}     
int Body::getHeight()
{
 	return height;
}      
void Body::setX(double new_x)
{
  	 x = new_x;
}     
void Body::setY(double new_y)
{
 	 y = new_y;
} 
void Body::setPosition(double new_x, double new_y)
{
 	 setX(new_x);
 	 setY(new_y);
}
void Body::setWidth(int new_w)
{
  	 width = new_w;
}     
void Body::setHeight(int new_h)
{
 	 height = new_h;
} 
int Body::overlaps(int x1, int y1, int w1, int h1)
{
    
   if (isSensor)
           return 9;
     if (x1 + w1 > x && x1 < x+width && y1+ h1 > y && y1 < y + height)
     {
        
               
			   if (x1 + 4  > x + width)
                  return 1;
               else if (x1 + w1 -4  < x )
                   return 2;
               else if  (y1 +6  > y + height )
                   return 4;
   		      else if (y1 - h1 < y  )
                  return 3;
               
               else
			   	   return 4;    
                   
     }
     else
         return -1;
}    
int Body::getType()
{
 	return type;
}
void Body::setSprite(string dir)
{
   sprite = load_bitmap (dir.c_str(), NULL);
}
void Body::setSprite(BITMAP * new_sprite)
{
   sprite = new_sprite;
}
string Body::getUserData()
{
 	   return userData;
}
bool Body::isDynamic()
{
 	 return dynamic;
}
