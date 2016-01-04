#include "world.h"
using namespace std;
World::World()
{
	 //worldSpace = create_bitmap(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	 for (int i = 0; i < NUMBER_OF_EVENTS; i++)
	 {
	  	 eventBooleans[i] = false;
	 }
     cameraX = 0;   
	 cameraY = 0;
	 hat = 1;
	 width = DEFAULT_WIDTH;
	 height = DEFAULT_HEIGHT;
	 player.setX(320.0);
	 player.setY(240);
	 player.setWidth(23);
	 player.setHeight(42);
	 player.setSprite("player_walk_0_0.bmp");
	 playerFacing = 0;
	 frame = 0;
	 hatFrame = 0;
	 zone = 1;
	 playerCanMoveW = true;
     playerCanMoveE = true;
     playerCanMoveN = true;
     playerCanMoveS = true;
	 zoneFloor = load_bitmap("zone1_ground.bmp", NULL);
	 for (int i = 0; i < NUMBER_OF_ROOMS; i++)
	 {
         for(int j = 0; j < 10; j++)
         {
                 roomTriggers[i][j] = false;
         }
    }
    
    colisionWithIndex = -1;
	 
}
World::World(int worldWidth, int worldHeight)
{
	 //worldSpace = create_bitmap(worldWidth, worldHeight);
	 for (int i = 0; i < NUMBER_OF_EVENTS; i++)
	 {
	  	 eventBooleans[NUMBER_OF_EVENTS] = false;
	 }
	 cameraX = 0;   
     cameraY = 0;
	 width = 1080;
	 height = 720;
	 player.setX(320);
	 player.setY(240);
	 player.setWidth(23);
	 player.setHeight(42);
	 player.setSprite("player_walk_0_0.bmp");
	 frame = 0;
	 	 for (int i = 0; i < NUMBER_OF_ROOMS; i++)
	 {
         for(int j = 0; j < 10; j++)
         {
                 roomTriggers[i][j] = false;
         }
    }
}
void World::drawAll(BITMAP *sb)
{
     for (int i = 0; i < width; i = i + zoneFloor->w)
     {
         for (int j = 0; j < height; j = j + zoneFloor->h)
         {
             blit(zoneFloor, sb, 0, 0, i, j, zoneFloor->w, zoneFloor->h);
         }
     }            
     for (int i = inWorld.size()-1; i >= 0; i--)
 	 {
	  	 inWorld[i].draw(sb);
	 }
	 player.draw(sb);
	 //debugValueB = inWorld.size();
	 
	 drawHat(sb); //Somehow this is causing a crash when it is called :(
	 
     textprintf_ex(sb, font, cameraX+10, cameraY+10, makecol(255, 100, 200), -1, "Width: %d", width);
     textprintf_ex(sb, font, cameraX+10, cameraY+190, makecol(255, 100, 200), -1, "DebugA: %d", player.getX());
     textprintf_ex(sb, font, cameraX+10, cameraY+280, makecol(255, 100, 200), -1, "DebugB: %d", player.getY());
     textprintf_ex(sb, font, cameraX+10, cameraY+370, makecol(255, 100, 200), -1, "DebugC: %d", debugValueC);
     textprintf_ex(sb, font, cameraX+10, cameraY+460, makecol(255, 100, 200), -1, "DebugD: %d", debugValueD);
     textout_ex(sb, font, getColisionData().c_str(), cameraX+10, cameraY+390, makecol(255, 100, 200), -1 );
     
}


int World::getCameraX()
{
 	return cameraX;
}
int World::getCameraY()
{
 	return cameraY;
}
int World::getPlayerX()
{
 	return (int)player.getX();
}
int World::getPlayerY()
{
 	return (int)player.getY();
}
int World::getRoom()
{
 	return inRoom;
}
int World::getHat()
{
 	return hat;
}
void World::clearAll()
{
 	 inWorld.clear();

}	 
void World::setWidth(int w)
{
 	 width = w;
}
void World::setHeight(int h)	  
{
 	 height = h;
}
void World::setCameraX(int cx)
{
 	 cameraX = cx;
}
void World::setCameraY(int cy)
{
 	 cameraY = cy;
}
void World::addBody(Body b)
{
 	 inWorld.push_back(b);
}
void World::update(int dt)
{
 	        debugValueB = dt;
 	        //colisionWithIndex = -1;
     	   //player.setX((double)player.getX()-2.0);
           	   
          if (key[KEY_LEFT] && player.getX() > 0.0 && playerCanMoveW)
          {
                colisionWithIndex =-1;            
                playerFacing = 1; 
                            
				if (6*dt/3 <= 3)          
    			   player.setX(player.getX()-6*dt/3);
	   			else
				      player.setX(player.getX()-3);
    			 switch (frame/5)
   			    {
                       case 0:
                            player.setSprite("player_walk_1_0.bmp");
                            break;
                       case 1:
                            player.setSprite("player_walk_1_0.bmp");
                            break;
                       case 2:
                            player.setSprite("player_walk_1_1.bmp");
                            break;
                       case 3:
                            player.setSprite("player_walk_1_1.bmp");
                            break;
                       case 4:
                            player.setSprite("player_walk_1_2.bmp");
                            break;
                       case 5:
                            player.setSprite("player_walk_1_2.bmp");
                            break;
                       case 6:
                            player.setSprite("player_walk_1_3.bmp");
                            break;
                       case 7:
                            player.setSprite("player_walk_1_3.bmp");
                            break;
                       case 8:
                            player.setSprite("player_walk_1_2.bmp");
                            break;
                       case 9:
                            player.setSprite("player_walk_1_2.bmp");
                            break;
                       case 10:
                            player.setSprite("player_walk_1_1.bmp");
                            break;
                       case 11:
                            player.setSprite("player_walk_1_1.bmp");
                            break;
                       
               }
               frame++;
               frame = frame%60; 
          }
          else if (key[KEY_RIGHT] && player.getX() + player.getWidth() < width && playerCanMoveE)
          {
               colisionWithIndex =-1;
                playerFacing = 0;
               
				if (6*dt/3 <= 3)          
    			   player.setX(player.getX()+6*dt/3);
	   			else
				      player.setX(player.getX()+3);            
    			//player.setX(player.getX()+6*dt/3);
   			    switch (frame/5)
   			    {
                       case 0:
                            player.setSprite("player_walk_0_0.bmp");
                            break;
                       case 1:
                            player.setSprite("player_walk_0_0.bmp");
                            break;
                       case 2:
                            player.setSprite("player_walk_0_1.bmp");
                            break;
                       case 3:
                            player.setSprite("player_walk_0_1.bmp");
                            break;
                       case 4:
                            player.setSprite("player_walk_0_2.bmp");
                            break;
                       case 5:
                            player.setSprite("player_walk_0_2.bmp");
                            break;
                       case 6:
                            player.setSprite("player_walk_0_3.bmp");
                            break;
                       case 7:
                            player.setSprite("player_walk_0_3.bmp");
                            break;
                       case 8:
                            player.setSprite("player_walk_0_2.bmp");
                            break;
                       case 9:
                            player.setSprite("player_walk_0_2.bmp");
                            break;
                       case 10:
                            player.setSprite("player_walk_0_1.bmp");
                            break;
                       case 11:
                            player.setSprite("player_walk_0_1.bmp");
                            break;
                       
               }
               frame++;
               frame = frame%60;            
   			    
   			    
          }
          if (key[KEY_UP] && player.getY() > 0 && playerCanMoveN)
          {
                colisionWithIndex =-1;
                playerFacing = 3;   
                
    			//player.setY(player.getY()-6*dt/3);
    			if (6*dt/3 <= 3)          
    			   player.setY(player.getY()-6*dt/3);
	   			else
				      player.setY(player.getY()-3);
  			    switch (frame/5)
   			    {
                       case 0:
                            player.setSprite("player_walk_3_0.bmp");
                            break;
                       case 1:
                            player.setSprite("player_walk_3_0.bmp");
                            break;
                       case 2:
                            player.setSprite("player_walk_3_0.bmp");
                            break;
                       case 3:
                            player.setSprite("player_walk_3_1.bmp");
                            break;
                       case 4:
                            player.setSprite("player_walk_3_1.bmp");
                            break;
                       case 5:
                            player.setSprite("player_walk_3_1.bmp");
                            break;
                       case 6:
                            player.setSprite("player_walk_3_0.bmp");
                            break;
                       case 7:
                            player.setSprite("player_walk_3_0.bmp");
                            break;
                       case 8:
                            player.setSprite("player_walk_3_0.bmp");
                            break;
                       case 9:
                            player.setSprite("player_walk_3_3.bmp");
                            break;
                       case 10:
                            player.setSprite("player_walk_3_3.bmp");
                            break;
                       case 11:
                            player.setSprite("player_walk_3_3.bmp");
                            break;
                       
               }
               frame++;
               frame = frame%60; 
          }
          else if (key[KEY_DOWN] && player.getY()+player.getHeight() < height && playerCanMoveS)
          {
               colisionWithIndex =-1;
                playerFacing = 2;
                            
    			if (6*dt/3 <= 3)          
    			   player.setY(player.getY()+6*dt/3);
	   			else
				      player.setY(player.getY()+3);
    			switch (frame/5)
   			    {
                       case 0:
                            player.setSprite("player_walk_2_0.bmp");
                            break;
                       case 1:
                            player.setSprite("player_walk_2_0.bmp");
                            break;
                       case 2:
                            player.setSprite("player_walk_2_0.bmp");
                            break;
                       case 3:
                            player.setSprite("player_walk_2_1.bmp");
                            break;
                       case 4:
                            player.setSprite("player_walk_2_1.bmp");
                            break;
                       case 5:
                            player.setSprite("player_walk_2_1.bmp");
                            break;
                       case 6:
                            player.setSprite("player_walk_2_0.bmp");
                            break;
                       case 7:
                            player.setSprite("player_walk_2_0.bmp");
                            break;
                       case 8:
                            player.setSprite("player_walk_2_0.bmp");
                            break;
                       case 9:
                            player.setSprite("player_walk_2_3.bmp");
                            break;
                       case 10:
                            player.setSprite("player_walk_2_3.bmp");
                            break;
                       case 11:
                            player.setSprite("player_walk_2_3.bmp");
                            break;
                       
               }
               frame++;
               frame = frame%60; 
          }
          if(!key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_LEFT] && !key[KEY_RIGHT])
           {               frame = 0;
                           switch (playerFacing)
                           {
                                  case 0:
                                       player.setSprite("player_walk_0_0.bmp");
                                       //if (hat == 1)
                                          //hatSprite = load_bitmap("hat_1_0.bmp", NULL);
                                       break;
                                  case 1:
                                       player.setSprite("player_walk_1_0.bmp");
                                       //if (hat == 1)
                                         // hatSprite = load_bitmap("hat_1_0.bmp", NULL);
                                       break;
                                  case 2:
                                       player.setSprite("player_walk_2_0.bmp");
                                       //if (hat == 1)
                                          //hatSprite = load_bitmap("hat_1_2.bmp", NULL);
                                       break;
                                  case 3:
                                       player.setSprite("player_walk_3_0.bmp");
                                       //if (hat == 1)
                                          //hatSprite = load_bitmap("hat_1_2.bmp", NULL);
                                       break;     
                           }
           }         
          
      
          playerCanMoveW = true;
          playerCanMoveE = true;
          playerCanMoveN = true;
          playerCanMoveS = true;
          
          for (int i = 0; i < inWorld.size(); i++)
          {
              
               //textprintf_ex(screen, font, cameraX+10, cameraY+100, makecol(255, 100, 200), -1, "Val: %d", temp);
              switch (inWorld[i].overlaps(player.getX(), player.getY()+30, player.getWidth(), player.getHeight()-30))
              {
                     
                     case 1:
                          playerCanMoveW = false;
                          	player.setX(inWorld[i].getX()+inWorld[i].getWidth()+1);
                          //player.setX(player.getX()+1);
                          //playerCanMoveFreely = false;
                          debugValueC = 1;
                          colisionWithIndex = i;
                          break;
                     case 2:
                          playerCanMoveE = false;
                           player.setX(inWorld[i].getX()-player.getWidth()-1);
                          //player.setX(player.getX()-1);
                          debugValueC = 2;
                          //playerCanMoveFreely = false;
                          colisionWithIndex = i;
                          break;
                     case 3:
                          playerCanMoveS = false;
                           player.setY(inWorld[i].getY()-player.getHeight()-1);
                          //player.setY(player.getY()+30-1);
                          //playerCanMoveFreely = false;
                          colisionWithIndex = i;
                          debugValueC = 3;
                          break;
                     case 4 :
                          playerCanMoveN = false; 
                           player.setY(inWorld[i].getY()+ inWorld[i].getHeight()-29);
                          //player.setY(player.getY()+30+1);
                          //playerCanMoveFreely = false;
                          colisionWithIndex = i;
                          debugValueC = 4;       
                          break;
                     case 5:
					 	   playerCanMoveW = false;
							player.setX(inWorld[i].getX()+inWorld[i].getWidth()+1);
					 	   //player.setX(player.getX()+);
						   playerCanMoveS = false;
						    player.setY(inWorld[i].getY()+player.getHeight()-30);
					       //player.setY(player.getY()+30-2);
					       colisionWithIndex = i;
                          debugValueC = 5;					       
						   break;  
			        case 6:
					 	   playerCanMoveW = false;  
					 	   player.setX(inWorld[i].getX()+inWorld[i].getWidth()+1);
					 	   //player.setX(player.getX()+2);
						   playerCanMoveN = false;
						    player.setY(inWorld[i].getY()+ inWorld[i].getHeight()+1);
						    //player.setY(player.getY()+30+2);
						    colisionWithIndex = i;
                          debugValueC = 6;						    
						   break;
			       case 7:
					 	   playerCanMoveE = false;  
					 	   player.setX(inWorld[i].getX()-player.getWidth()-1);
					 	   //player.setX(player.getX()-2);
						   playerCanMoveS = false;
						    player.setY(inWorld[i].getY()+player.getHeight()-30+1);
						    //player.setY(player.getY()+30-2);
						    colisionWithIndex = i;
                          debugValueC = 7;						    
						   break;  
			        case 8:
					 	   playerCanMoveE = false; 
					 	   player.setX(inWorld[i].getX()-player.getWidth()-1);
							//player.setX(player.getX()-1); 
							colisionWithIndex = i;
						   playerCanMoveN = false;
						    player.setY(inWorld[i].getY()+ inWorld[i].getHeight()+1);
						   //player.setY(player.getY()+30+1);
                          debugValueC = 8;						   
						   break;  
				    case 9:
                           break;
                     default:
                          break;
              }          
          }
          if (!(playerCanMoveN && playerCanMoveS && playerCanMoveE && playerCanMoveW) && colisionWithIndex >= 0)
          {
                               
               if (inWorld[colisionWithIndex].getUserData().compare("door") == 0)
               {
                     loadRoom(inWorld[colisionWithIndex].getType());
               }
               else if (inWorld[colisionWithIndex].getUserData().compare("Ndoor") == 0)
               {
                     double px = player.getX();
                     loadRoom(inWorld[colisionWithIndex].getType());
                     player.setY(height-100);
                     player.setX (px);
                     
               }
               else if (inWorld[colisionWithIndex].getUserData().compare("Sdoor") == 0)
               {
                    double px = player.getX();
                     loadRoom(inWorld[colisionWithIndex].getType());
                     player.setY(100);
                     player.setX (px);
                     
               } 
               else if (inWorld[colisionWithIndex].getUserData().compare("Edoor") == 0)
               {
                     double py = player.getY();
                     loadRoom(inWorld[colisionWithIndex].getType());
                     player.setX(50);
                     player.setY (py);
                     
               }
               else if (inWorld[colisionWithIndex].getUserData().compare("Wdoor") == 0)
               {
                    double py = player.getY();
                     loadRoom(inWorld[colisionWithIndex].getType());
                     player.setX(width - 50);
                     player.setY (py);
                     
               }
               // 
          }        
          
         cameraX = player.getX()-(((screen->w)/2));
          if (cameraX < 0)
             cameraX = 0;
          if ((cameraX + (screen->w)) > width)
             cameraX =  width - (screen -> w);
          cameraY = player.getY()-((screen->h)/2);
          if (cameraY < 0)
             cameraY = 0;
          if ((cameraY + (screen->h)) > height)
             cameraY =  height - (screen -> h);             
      //frame++;
      //frame = frame%6;    
         
}

string World::getColisionData()
{
       
        bool  isSensor = false;
        for (int i = 0; i < inWorld.size(); i++)
        { 
               isSensor = false;                                                                              
              if (inWorld[i].overlaps(player.getX()-3, player.getY(), player.getWidth()+6, player.getHeight()+3) >= 1)
              {
                  size_t found = inWorld[i].getUserData().find("sensor", 0);
                  if (found!=string::npos)
                  {
                     isSensor = true;
                     //return inWorld[i].getUserData();
                  }
                  else 
                       isSensor = false;                                                                              
                 if (inWorld[i].getUserData().compare("wall") != 0 && !isSensor)
                 {
                     colisionWithIndex = i;                                    
                     return inWorld[colisionWithIndex].getUserData();
                 }    
              }
        }
       return "NONE";
}


void World::loadRoom(int roomNumber)
{
 	 int roomNum = roomNumber;
 	 if (roomNumber >= roomLibrary.size())
 	 	roomNum = roomLibrary.size()-1;
     inWorld.clear();
     if (player.getX() > width-100)
     { 
        player.setX(50);
     }
     else if (player.getX() < 100)
     { 
        player.setX(roomLibrary[roomNum].getWidth()-50);
     }
     else if (player.getY() < 100)
     { 
        player.setY(roomLibrary[roomNum].getHeight()-100);
     } 
     else if (player.getY() > height -100)
     { 
        player.setY(100);
     }
     else
     {
         player.setPosition(200, 200);
     }
     int i = roomLibrary[roomNum].numberOfBodies()-1;
     debugValueA = roomLibrary[roomNum].numberOfBodies();
     debugValueC = roomNum;
 	 while ( i >= 0 )
 	 {
           inWorld.push_back(roomLibrary[roomNum].pullNextBody());
           roomLibrary[roomNum].popLastBody();
           i--;
     }
     for (int b = 0; b < inWorld.size(); b++)
     {
         roomLibrary[roomNum].addBody(inWorld[b]);
     }
     width = roomLibrary[roomNum].getWidth();
     height = roomLibrary[roomNum].getHeight();
     inRoom = roomNum;
     zone = roomLibrary[roomNum].getZone();
     switch (zone)
     {
            case 1:
                  zoneFloor = load_bitmap("zone1_ground.bmp", NULL);
                  break;
            case 2:
                 zoneFloor = load_bitmap("zone2_ground.bmp", NULL);
                 break;
     }
     buildAllRooms();
     
     
}


     
void World::drawHat(BITMAP * drawHere)
{
     
     //BITMAP * hatSprite;
     
      
      int hatH;
      switch (playerFacing)
                  {
                         case 0:
                              hatH = hatE->h;
                              break;
                         case 1:
                              hatH = hatW->h;
                              break;
                         case 2:
                              hatH = hatN->h;
                              break;
                         case 3:
                              hatH = hatN->h;
                              break;
                  }        
 	 switch (hat)
     {
	  		case 1:
            {
                 switch (playerFacing)
                  {
                         case 0:
                              masked_blit(hatE, drawHere, (hatFrame/5)*23, 0, player.getX(), player.getY()-9, 23, hatH);
                              break;
                         case 1:
                              masked_blit(hatW, drawHere, (hatFrame/5)*23, 0, player.getX(), player.getY()-9, 23, hatH);
                              break;
                         case 2:
                              hatH = 15;
                              masked_blit(hatN, drawHere, (hatFrame/5)*23, 0, player.getX(), player.getY()-9, 23, 15);
                              break;
                              
                         case 3:
                              masked_blit(hatN, drawHere, (hatFrame/5)*23, 0, player.getX(), player.getY()-9, 23, hatH);
                              break;
                  }
 				 
 				 break;
            }
		    case 2:
            {
                 switch (playerFacing)
                  {
                         case 0:
                              masked_blit(hatE, drawHere, 0, 0, player.getX(), player.getY()-7, 23, hatH);
                              break;
                         case 1:
                              masked_blit(hatW, drawHere, 0, 0, player.getX(), player.getY()-7, 23, hatH);
                              break;
                         case 2:
                              masked_blit(hatN, drawHere, 0, 0, player.getX(), player.getY()-7, 23, hatH);
                              break;
                         case 3:
                              masked_blit(hatN, drawHere, 0, 0, player.getX(), player.getY()-7, 23, hatH);
                              break;
                  }
 				 
 				 break;
             }
       default:
               break;
               
				 
    }
    hatFrame++;
    hatFrame = hatFrame%20;
}

void World::buildAllRooms()
{
 	 BITMAP * spriteSheet = load_bitmap("spritesheet_zone1.bmp", NULL);
 	 roomLibrary.clear();
 	 
 	 Room room0 (0, 640, 480, 1, -1); // creates room object with a roomNumber of 0, a width of 5060, a height of 720, a zone of 0 and no puzzle.
 	 int objectWidth = 80;
 	 int objectHeight = 150;
     Body room0_bed("bed", objectWidth, objectHeight); // creates a 80x150 bed
 	 room0_bed.setX(50.0);
     room0_bed.setY(100.0); // places that block at (50, 100)
     BITMAP * temp = create_bitmap(objectWidth, objectHeight);
     masked_blit(spriteSheet, temp, 50, 50, 0, 0, objectWidth, objectHeight);
     room0_bed.setSprite(temp);
 	 room0.addBody(room0_bed);// adds that bed to the room
 	 Body room0_door1("door", 27, 70);// crates a 27x70 door
 	 room0_door1.setPosition (620, (480/2)-35.0); // places that door at (1048, 325)
 	 room0_door1.setType(1);// door goes to room 1
     room0.addBody(room0_door1);// adds that door to room 0
     objectWidth = 80;
 	 objectHeight = 53;
     Body room0_basket("dirtyClothes", 60, 30); // creates a 60x30 dirtyClothes
 	 room0_basket.setX(200);
     room0_basket.setY(50); // places that block at (50, 100)
     BITMAP * clothesBasket = create_bitmap(objectWidth, objectHeight);
     clear(clothesBasket);
     blit(spriteSheet, clothesBasket, 130, 50, 0, 0, 80, 53);
     room0_basket.setSprite(clothesBasket);
     room0.addBody(room0_basket);
     
     
     Body room0_divider("wall", 20, 350); // creates a 10x350 wall
 	 room0_divider.setX(280);
     room0_divider.setY(0); // places that block at (50, 100)
     BITMAP * wallPiece = load_bitmap("wallZone1.bmp", NULL);
     BITMAP* divider = create_bitmap(20, 350);
     clear_to_color( divider ,0 );
     //clear(temp1);
     blit(wallPiece, divider, 0, 0, 0, 320, 20, 30);
     room0_divider.setSprite(divider);
     room0.addBody(room0_divider);
     
     objectWidth = 100;
 	 objectHeight = 30;
 	 Body room0_table("hallwayTable", objectWidth, objectHeight);
 	 BITMAP * smallTable = create_bitmap(objectWidth, objectHeight);
     blit(spriteSheet, smallTable, 210, 50, 0, 0, objectWidth, objectHeight);
 	 room0_table.setSprite (smallTable);
      room0_table.setPosition (300, 20);
 	 room0.addBody(room0_table);
     
     
	 roomLibrary.push_back(room0); // adds room 0 to the room library
     
     // room 1
      Room room1 (roomLibrary.size(), 640, 480, 1, -1);
 	 Body room1_block1("TV", 50, 50);
 	 BITMAP * TV  = create_bitmap(50, 50);
     blit(spriteSheet, TV, 310, 50, 0, 0, 50, 50);
 	 room1_block1.setSprite(TV);
      room1_block1.setPosition (100, 15);
 	 room1.addBody(room1_block1);
 	 Body room1_door1("door", 27, 70);
 	 room1_door1.setPosition (0, (480/2)-35);
 	 room1_door1.setType(0);
     room1.addBody(room1_door1);
     Body room1_door2("door", 27, 45);
     room1_door2.setPosition (320, -1);
 	 room1_door2.setType(2);
 	 BITMAP* black = create_bitmap(20, 350);
     clear_to_color( black ,0 );
 	 room1_door2.setSprite (black);
     room1.addBody(room1_door2);
     Body room1_hatRack("hatStand", 27, 70);
 	 BITMAP * hatpole  = create_bitmap(27, 70);
 	 clear_to_color(hatpole, makecol(255, 0, 255));
     blit(spriteSheet, hatpole, 360, 50, 0, 0, 27, 70);
 	 room1_hatRack.setSprite(hatpole);
     room1_hatRack.setPosition (270, 5);
 	 room1.addBody(room1_hatRack);
 	 
 	 roomLibrary.push_back(room1);
	  
     Room room2 (roomLibrary.size(), 640, 720, 2, -1);
 	 
 	 Body room2_door1("door", 27, 30);
 	 room2_door1.setPosition (320-(27/2), 720-20);
 	 room2_door1.setType(1);
 	 
 	 room2_door1.setSprite (black);//add a sprite for doors
 	 room2.addBody(room2_door1);
 	 
 	 
 	 Body room2_path("sensor_path", 54, 60);
 	 room2_path.setPosition (320-(54/2), 720-60-27);
 	 room2_path.setSprite ("path.bmp");//add a sprite for doors
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*1));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*2));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*3));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*4));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*5));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*6));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*7));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*8));
 	 room2.addBody(room2_path);
 	 room2_path.setPosition (320-(54/2), 720-60-27-(60*9));
 	 room2.addBody(room2_path);
     room2_path.setPosition (320-(54/2), 720-60-27-(60*10));
     room2.addBody(room2_path);
   	 room2_path.setPosition (320-(54/2), 720-60-27-(60*11));
   	 room2.addBody(room2_path);
 	 
 	 BITMAP *fence = load_bitmap("fence.bmp", NULL);
 	 BITMAP *fenceFlip = create_bitmap(fence->w, fence->h);
 	 clear_to_color(fenceFlip, makecol(255, 0 , 255));
 	 draw_sprite_h_flip(fenceFlip, fence, 0, 0);
	 Body room2_fence1 ("fence", fence->w, fence->h);
	 room2_fence1.setPosition (0, 715-fence->h);
	 room2_fence1.setSprite(fence);
     room2.addBody(room2_fence1);
     
     Body room2_fence2 ("fence", fence->w, fence->h);
	 room2_fence2.setPosition (635-fence->w, 715-fence->h);
	 room2_fence2.setSprite(fenceFlip);
     room2.addBody(room2_fence2);
	  
	  Body room2_door2("Ndoor", 640, 35);
	  room2_door2.setPosition(0,0);
	  room2_door2.setType(3);
      BITMAP * invisible = create_bitmap(50, 50);
       clear_to_color(invisible, makecol(255, 0, 255));
       room2_door2.setSprite(invisible);
	   room2.addBody(room2_door2);
	  roomLibrary.push_back(room2);
	  
	 Room room3 (roomLibrary.size(), 1080, 480, 2, -1);
	 Body room3_door1("Edoor", 35, 480);
  	  room3_door1.setPosition(1070, 0);
	  room3_door1.setType(4);
      room3_door1.setSprite(invisible);
      room3.addBody(room3_door1);
	   
   Body room3_path("sensor_path", 54, 60);
 	 room3_path.setSprite ("path.bmp");//add a sprite for doors
 	 room3_path.setPosition (320-(54/2), 420);
 	 room3.addBody(room3_path);
 	 room3_path.setPosition (320-(54/2), 380);
 	 room3.addBody(room3_path);
 	 room3_path.setPosition (320-(54/2), 320);
 	 room3.addBody(room3_path);
     room3_path.setPosition (320-(54/2), 260);
     room3.addBody(room3_path);
   	 room3_path.setPosition (320-(54/2), 200);
     room3.addBody(room3_path);
     room3_path.setPosition (320-(54/2)+(54*1), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*2), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*3), 200);
     room3.addBody(room3_path);
     room3_path.setPosition (320-(54/2)+(54*4), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*5), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*6), 200);
     room3.addBody(room3_path);
     room3_path.setPosition (320-(54/2)+(54*7), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*8), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*9), 200);
     room3.addBody(room3_path);
     room3_path.setPosition (320-(54/2)+(54*10), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*11), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*12), 200);
     room3.addBody(room3_path);
     room3_path.setPosition (320-(54/2)+(54*13), 200);
     room3.addBody(room3_path);
      room3_path.setPosition (320-(54/2)+(54*14), 200);
     room3.addBody(room3_path);
      //room3_path.setPosition (320-(54/2)+(54*15), 200);
     //room3.addBody(room3_path);
     //room3_path.setPosition (320-(54/2)+(54*16), 200);
     //room3.addBody(room3_path);
      //room3_path.setPosition (320-(54/2)+(54*17), 200);
     //room3.addBody(room3_path);
      //room3_path.setPosition (320-(54/2)+(54*18), 200);
     //room3.addBody(room3_path);
 	 //room3_path.setPosition (320-(54/2), 480);
 	 //room3.addBody(room3_path);
 	 
 	 Body room3_door2("Sdoor", 27, 30);
 	 room3_door2.setPosition (320-(27/2), 480-20);
 	 room3_door2.setType(2);
 	 
 	 room3_door2.setSprite (black);//add a sprite for doors
 	 room3.addBody(room3_door2);
	     
	  roomLibrary.push_back(room3);
	  
	  
	  //First town
	  Room simpleTown(roomLibrary.size(), 640, 480, 2, -1);
  	 Body simpleTown_shop1("shopA", 200, 150);
 	 simpleTown_shop1.setPosition (0, 0);
 	 simpleTown.addBody(simpleTown_shop1);
 	 
 	 Body townDoor ("Wdoor", 27, 70 );
 	 townDoor.setPosition(0, 240-(70/2));
 	 townDoor.setSprite(black);
 	 townDoor.setType(roomLibrary.size()-1);
 	 simpleTown.addBody(townDoor);
 	 
 	 Body simpleTown_path("sensor_path", 54, 60);
 	 simpleTown_path.setSprite ("path.bmp");//add a sprite for doors
 	 int pathSeg = 0;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
     simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 /*simpleTown_path.setPosition (0 + (54*pathSeg), (480)-(60));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480)-(60*2));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2));
 	 simpleTown.addBody(simpleTown_path);
 	 //simpleTown_path.setPosition (0 + (54*pathSeg), (480)-(60*4));
 	 //simpleTown.addBody(simpleTown_path);
 	 */
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(90));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(90+60));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(90+60*2));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(90+60*3));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)+(30));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)+(30+60));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)+(30+60*2));
 	 simpleTown.addBody(simpleTown_path);
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)+(30+60*3));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 simpleTown_path.setPosition (0 + (54*pathSeg), (480/2)-(30));
 	 simpleTown.addBody(simpleTown_path);
 	 pathSeg++;
 	 
 	 roomLibrary.push_back(simpleTown); 
	  
  	  //Error room 0.0
     Room iAmError(-1, 640, 480, 0, -1);
  	 Body iAmError_block1("block", 50, 50);
 	 iAmError_block1.setPosition (200, 300);
 	 iAmError.addBody(iAmError_block1);
 	 roomLibrary.push_back(iAmError); 
	  /*
     // room 0
     Room room0 (0, 5080, 720, 0, -1); // creates room object with a roomNumber of 0, a width of 5060, a height of 720, a zone of 0 and no puzzle.
 	 Body room0_block1("block", 50, 50); // creates a 50x50 block
 	 room0_block1.setX(50.0);
      room0_block1.setY(100.0); // places that block at (50, 100)
 	 room0.addBody(room0_block1);// adds that block to the room
 	 Body room0_door1("door", 27, 70);// crates a 27x70 door
 	 room0_door1.setPosition (5048.0, (720/2)-35.0); // places that door at (5048, 325)
 	 room0_door1.setType(1);// door goes to room 1
     room0.addBody(room0_door1);// adds that door to room 0
 	 roomLibrary.push_back(room0); // adds room 0 to the room library
     
     
     // room 1
      Room room1 (1, 1080, 720, 0, -1);
 	 Body room1_block1("block", 50, 50);
 	 room1_block1.setPosition (200, 300);
 	 room1.addBody(room1_block1);
 	 Body room1_door1("door", 27, 70);
 	 room1_door1.setPosition (0, (720/2)-35);
 	 room1_door1.setType(0);
     room1.addBody(room1_door1);
     Body room1_door2("door", 27, 70);
     room1_door2.setPosition (1048, (720/2)-35);
 	 room1_door2.setType(2);
     room1.addBody(room1_door2);
 	 roomLibrary.push_back(room1);
 	 
     Room room2 (2, 1080, 720, 0, -1);
 	 Body room2_block1("block", 50, 50);
 	 room2_block1.setPosition (200, 300);
 	 room2.addBody(room2_block1);
 	 Body room2_door1("door", 27, 80);
 	 room2_door1.setPosition (0, (720/2)-35);
 	 room2_door1.setType(1);
     room2.addBody(room2_door1);
 	 roomLibrary.push_back(room2);
 	 */
 	 
 	 
 	 
 	
}
void World::drawPlayer(BITMAP* pl)
{
     
}
void World::setHat(int hatID)
{
     hat = hatID;
     switch (hat)
     {
	  		case 1:
 				 hatE = load_bitmap("hat_1_0.bmp", NULL);
 				 hatW = load_bitmap("hat_1_0.bmp", NULL);
 				 hatN = load_bitmap("hat_1_2.bmp", NULL);
 				 hatS = hatN;
 				 break;
		    case 2:
 				 hatE = load_bitmap("hat_2_0.bmp", NULL);
 				 hatW = load_bitmap("hat_2_1.bmp", NULL);
 				 hatN = load_bitmap("hat_2_3.bmp", NULL);
 				 hatS = hatN;
 				 break;
           default:
                 hatE = load_bitmap("hat_1_0.bmp", NULL);
 				 hatW = load_bitmap("hat_1_0.bmp", NULL);
 				 hatN = load_bitmap("hat_1_2.bmp", NULL);
 				 hatS = hatN;
 				 break;  
    }
}


