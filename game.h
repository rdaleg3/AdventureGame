#ifndef GAME_H      
#define GAME_H 
#include <allegro.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "world.h"
#include "enemy.h"
#include "item.h"
const double GRAVITY = .0000001;
const int PIPE_WIDTH (40);
const int GAP_HEIGHT = 100;
const double JUMP_VALUE = 2;
const int INVENTORY_SIZE(6);
const int NUMBER_OF_INTERACTIONS (50);
const int INVCAP (8);
//const int NUMBER_OF_ITEMS (50);
class Game
{

      public:
             explicit Game();
             void update(BITMAP *sb, int dt);
             int getCamX();
             int getCamY();
             void load();
             bool onKeyPress(std::string keyCode, BITMAP * screenForText);
             void textBox(std::string message);
             void combat(BITMAP *sb, int enemyID, int dt);
             void startCombat (int enemyID);
             void buildEnemies();
             void flappyGame(int specialEvents, BITMAP *scr, int dt);
             bool saveToFile();
             bool loadFromFile();
             void drawInventory(BITMAP* drawMe);
             bool useItem(int slot);
             void reload();
             
             
      private:
             World world;
             bool keyPresses[32];//a-z and enter, space, ctrl, shift, esc, and more
             std::string displayText;
             std::string message;
             std::string optionA;
             std::string optionB;
             int frames;
             int timer;
             double flappyTimer;
             int enemyAtID;
             int messageTimer;
             int gameState;
             int combatStep;
             std::vector <Enemy> enemyLibrary;
             BITMAP * loading;
             int cursorX;
             int cursorY;
             int cursorXLimit;
             int cursorYLimit;
             double birdY;
             double birdYVelocity;
             int pipe1X, pipe2X;
             int pipe3X;
             int pipe1Y, pipe2Y;
             int pipe3Y;
             int playerHP;
             int playerHPCap;
             int playerAttack;
             double invTimer;
             std::string playerName;
             void setMessage(std::string ms);
             void drawMessageBox();
             bool setOption(std::string ms, std::string a, std::string b);
             bool drawOptionBox();
             int roomNumber;
             int karmaPoints;
             int hat;
             int armor;
             int weapon;
             bool interactedWith[NUMBER_OF_INTERACTIONS];
             //std::vector <Item> itemLibrary;
             std::vector <Item> inventory;
             bool itemSelected;
             int cursorPos;
             int selectorPos;
             int textout_hack(BITMAP*b , FONT *font , int x , int y , double multiplier , const char *msg , int color );
             int textout_hack(BITMAP*b , FONT *font , int x , int y , double multiplier , const char *msg , int color, int bkgColor );
             bool addToInventory(int ID);
             bool forceToInventory(int ID);
             bool triggers (BITMAP *draw, int dt);
             bool hasBeenTriggered[50];//this is only for "Triggers"
             SAMPLE *backgroundMusic;
             SAMPLE *gameOverMusic;
             //int test;
             //int cursorYLimit1;
};

#endif             
