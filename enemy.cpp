#include "enemy.h"
using namespace std;
Enemy::Enemy(string n, int atk, int def, string opt0, int type0, int val0, string react0, int karmaRequirement, int rewardPascifist, int rewardKiller, string imgDir, int health)
{
      for (int i = 0; i < OPTIONS_X; i++)
     {
         for (int j = 0; j < OPTIONS_Y; j++)
         {
                options[i][j] = NO_OPTION;
                reactions [i] [j] [0] = 0;
                reactions [i] [j] [1] = 0;
                reactions [i] [j] [2] = 0;
         }
         
     }              
     options[0][0] = opt0;     
     sprite = load_bitmap (imgDir.c_str(), NULL);
     reactions[0][0][type0] = val0;
     responces[0][0] = react0;
     attack = atk;
     defense = def;
     name = n;
     karmaReq = karmaRequirement;
     rewards [0] [0] = 0;// killer Gold
     rewards [0] [1] = rewardKiller;// killer EXP
     rewards [0] [2] = -10;// killer KP
     rewards [1] [0] = rewardPascifist; // Friend Gold
     rewards [1] [1] = 0;// friend EXP
     rewards [1] [2] = 5;// friend KP
     spriteSheetX = 0;
     spriteSheetY = 0;
     spriteSheetWidth = sprite->w;
     spriteSheetHeight = sprite->h;
     hp = health;
     numberOfOptions = 1;
}
Enemy::Enemy()
{
     for (int i = 0; i < OPTIONS_X; i++)
     {
         for (int j = 0; j < OPTIONS_Y; j++)
         {
             options[i][j] = NO_OPTION;
             reactions [i] [j] [0] = 0;
            reactions [i] [j] [1] = 0;
            reactions [i] [j] [2] = 0;
         }
     }
             
     sprite = load_bitmap ("null.bmp", NULL);
     reactions[0][0][0] = 0;
     responces[0][0] = "ERROR";
     attack = 0;
     defense = 0;
     name = "ERROR";
     karmaReq = -99999;
     rewards [0] [0] = 0;// killer Gold
     rewards [0] [1] = 5;// killer EXP
     rewards [0] [2] = -10;// killer KP
     rewards [1] [0] = 5; // Friend Gold
     rewards [1] [1] = 0;// friend EXP
     rewards [1] [2] = 5;// friend KP
     spriteSheetX = 0;
     spriteSheetY = 0;
     spriteSheetWidth = sprite->w;
     spriteSheetHeight = sprite->h;
     hp = 99999;
     numberOfOptions = -1;
}
Enemy::Enemy(string n, int atk, int def, string opt0, int type0, int val0, string react0, string opt1, int type1, int val1, string react1, int karmaRequirement, int rewardPascifist, int rewardKiller, string imgDir, int health)
{
     for (int i = 0; i < OPTIONS_X; i++)
     {
         for (int j = 0; j < OPTIONS_Y; j++)
         {
                options[i][j] = NO_OPTION;
                reactions [i] [j] [0] = 0;
                reactions [i] [j] [1] = 0;
                reactions [i] [j] [2] = 0;
         }
         
     }               
     options[0][0] = opt0;
     options[1][0] = opt1;

     sprite = load_bitmap (imgDir.c_str(), NULL);
     reactions[0][0][type0] = val0;
     reactions[1][0][type1] = val1;
     responces[0][0] = react0;
     responces[1][0] = react1;
     attack = atk;
     defense = def;
     name = n;
     karmaReq = karmaRequirement;
     rewards [0] [0] = 0;// killer Gold
     rewards [0] [1] = rewardKiller;// killer EXP
     rewards [0] [2] = -10;// killer KP
     rewards [1] [0] = rewardPascifist; // Friend Gold
     rewards [1] [1] = 0;// friend EXP
     rewards [1] [2] = 5;// friend KP
     spriteSheetX = 0;
     spriteSheetY = 0;
     spriteSheetWidth = sprite->w;
     spriteSheetHeight = sprite->h;
     hp = health;
     numberOfOptions = 2;
}
Enemy::Enemy(string n, int atk, int def, string opt0, int type0, int val0, string react0, string opt1, int type1, int val1, string react1, string opt2, int type2, int val2, string react2, int karmaRequirement, int rewardPascifist, int rewardKiller, string imgDir, int health)
{
     for (int i = 0; i < OPTIONS_X; i++)
     {
         for (int j = 0; j < OPTIONS_Y; j++)
         {
                options[i][j] = NO_OPTION;
                reactions [i] [j] [0] = 0;
                reactions [i] [j] [1] = 0;
                reactions [i] [j] [2] = 0;
         }
         
     }
     options[0][0] = opt0;
     options[1][0] = opt1;
     options[0][2] = opt2;
     sprite = load_bitmap (imgDir.c_str(), NULL);
     reactions[0][0][type0] = val0;
     reactions[0][1][type1] = val1;
     reactions[0][2][type2] = val2;
     responces[0][0] = react0;
     responces[0][1] = react1;
     responces[0][2] = react2;
     attack = atk;
     defense = def;
     name = n;
     karmaReq = karmaRequirement;
     rewards [0] [0] = 0;// killer Gold
     rewards [0] [1] = rewardKiller;// killer EXP
     rewards [0] [2] = -10;// killer KP
     rewards [1] [0] = rewardPascifist; // Friend Gold
     rewards [1] [1] = 0;// friend EXP
     rewards [1] [2] = 5;// friend KP
     spriteSheetX = 0;
     spriteSheetY = 0;
     spriteSheetWidth = sprite->w;
     spriteSheetHeight = sprite->h;
     hp = health;
     numberOfOptions = 3;
}
Enemy::Enemy(std::string n, int atk, int def, std::string opt0, int type0, int val0, std::string react0, std::string opt1, int type1, int val1, std::string react1, std::string opt2, int type2, int val2, std::string react2, std::string opt3, int type3, int val3, std::string react3, int karmaRequirement, int rewardPascifist, int rewardKiller, std::string imgDir, int health)
{
      for (int i = 0; i < OPTIONS_X; i++)
     {
         for (int j = 0; j < OPTIONS_Y; j++)
         {
                options[i][j] = NO_OPTION;
                reactions [i] [j] [0] = 0;
                reactions [i] [j] [1] = 0;
                reactions [i] [j] [2] = 0;
         }
         
     }                   
     options[0][0] = opt0;
     options[1][0] = opt1;
     options[0][1] = opt2;
     options[1][1] = opt3;
     
     sprite = load_bitmap (imgDir.c_str(), NULL);
     reactions[0][0][type0] = val0;
     reactions[1][0][type1] = val1;
     reactions[0][1][type2] = val2;
     reactions[1][1][type3] = val3;
     responces[0][0] = react0;
     responces[1][0] = react1;
     responces[0][1] = react2;
     responces[1][1] = react3;
     attack = atk;
     defense = def;
     name = n;
     karmaReq = karmaRequirement;
     rewards [0] [0] = 0;// killer Gold
     rewards [0] [1] = rewardKiller;// killer EXP
     rewards [0] [2] = -10;// killer KP
     rewards [1] [0] = rewardPascifist; // Friend Gold
     rewards [1] [1] = 0;// friend EXP
     rewards [1] [2] = 5;// friend KP
     spriteSheetX = 0;
     spriteSheetY = 0;
     spriteSheetWidth = sprite->w;
     spriteSheetHeight = sprite->h;
     hp = health;
     numberOfOptions = 4;
}

bool Enemy::isAlive()
{
     return (hp > 0);
}
bool Enemy::isComplete()  
{
     return (karmaReq > 0);
} 
string Enemy::getName()
{
     return name;
}
string Enemy::getOption(int xLoc, int yLoc)
{
     return options [xLoc] [yLoc];
}
bool Enemy::action(int xLoc, int yLoc)
{
     attack += reactions [xLoc] [xLoc] [0];
     karmaReq += reactions [xLoc] [xLoc] [1];
     defense += reactions [xLoc] [xLoc] [2];
     return false;
}
string Enemy::response(int xLoc, int yLoc)
{
     return responces [xLoc] [yLoc];
}
void Enemy::setSprite(std::string dir)
{
     sprite = load_bitmap (dir.c_str(), NULL);
     spriteSheetX = 0;
     spriteSheetY = 0;
     spriteSheetWidth = sprite->w;
     spriteSheetHeight = sprite->h;
}
void Enemy::setSprite(std::string dir, int imgx, int imgy, int imgwidth, int imgheight)
{
     sprite = load_bitmap (dir.c_str(), NULL);
     spriteSheetX = imgx;
     spriteSheetY = imgy;
     spriteSheetWidth = imgwidth;
     spriteSheetHeight = imgheight;
}
void Enemy::setSprite(int imgx, int imgy, int imgwidth, int imgheight)
{
     spriteSheetX = imgx;
     spriteSheetY = imgy;
     spriteSheetWidth = imgwidth;
     spriteSheetHeight = imgheight;
}
void Enemy::drawToBitmap (BITMAP * bmp, int dest_x, int dest_y)
{
     masked_blit(sprite, bmp, spriteSheetX, spriteSheetY, dest_x, dest_y, spriteSheetWidth, spriteSheetHeight);
}
int Enemy::getHealth()
{
     return hp;
}
int Enemy::getKarma()
{
     return karmaReq;
}
int Enemy::getNumberOfActions()
{
     return numberOfOptions;
}
void Enemy::takeDamage(int dmg)
{
     hp -= dmg;
}
int Enemy::getAttack()
{
    return attack;
}
