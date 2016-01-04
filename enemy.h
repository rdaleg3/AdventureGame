#ifndef ENEMY_H
#define ENEMY_H
#include "body.h"
#include "sensor.h"
const int OPTIONS_X(2);
const int OPTIONS_Y(3);
const std::string NO_OPTION = "OP_NULL";

//const BITMAP* PLAYER_SPRITE = load_bitmap ("null.bmp", NULL);
class Enemy
{ 
      friend class World;
      friend class Game;
public:
      explicit Enemy(std::string n, int atk, int def, std::string opt0, int type0, int val0, std::string react0, int karmaRequirement, int rewardPascifist, int rewardKiller, std::string imgDir, int health);
      explicit Enemy(std::string n, int atk, int def, std::string opt0, int type0, int val0, std::string react0, std::string opt1, int type1, int val1, std::string react1, int karmaRequirement, int rewardPascifist, int rewardKiller, std::string imgDir, int health);      
      explicit Enemy(std::string n, int atk, int def, std::string opt0, int type0, int val0, std::string react0, std::string opt1, int type1, int val1, std::string react1, std::string opt2, int type2, int val2, std::string react2, int karmaRequirement, int rewardPascifist, int rewardKiller, std::string imgDir, int health);
      explicit Enemy(std::string n, int atk, int def, std::string opt0, int type0, int val0, std::string react0, std::string opt1, int type1, int val1, std::string react1, std::string opt2, int type2, int val2, std::string react2, std::string opt3, int type3, int val3, std::string react3, int karmaRequirement, int rewardPascifist, int rewardKiller, std::string imgDir, int health);      
      explicit Enemy();            
      bool isAlive();
      bool isComplete();    
      std::string getName();
      int getHealth();
      int getKarma();
      int getNumberOfActions();
      std::string getOption(int xLoc, int yLoc);
      bool action(int xLoc, int yLoc);
      std::string response(int xLoc, int yLoc);
      void setSprite(std::string dir);
      void setSprite(std::string dir, int imgx, int imgy, int imgwidth, int imgheight);
      void setSprite(int imgx, int imgy, int imgwidth, int imgheight);
      void takeDamage(int dmg);
      int getAttack();
      void drawToBitmap (BITMAP * bmp, int dest_x, int dest_y);
      
private:
     std::string options[OPTIONS_X][OPTIONS_Y];
     BITMAP* sprite;
     int reactions[OPTIONS_X][OPTIONS_Y][3];
     std::string responces[OPTIONS_X][OPTIONS_Y];
     int attack;
     int defense;
     std::string name;
     int karmaReq;
     int rewards [2] [3]; // type of [completion] [valueOfReward]
     int spriteSheetX;
     int spriteSheetY;
     int spriteSheetWidth;
     int spriteSheetHeight;
     int numberOfOptions;
     int hp;
};
#endif
