#ifndef TEXTBOX_H      
#define TEXTBOX_H 
#include <allegro.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
class Textbox
{
      friend class World;
      public:
             explicit Textbox();
             explicit Textbox(std::string message);
             explicit Textbox(std::string message, std::string choice1, std::string choice2);
             explicit Textbox(std::string message, int fontSelect);
             
             void draw(BITMAP *sbmp, int camX, int camY);
             bool isFinished();
             int getChoice(); 
             void rush();
             
      private:
              std::string display;
              std::string text;
              int choice;
              std::string choiceA;
              std::string choiceB;
              int fontInUse;
              bool typed;
              int indexTyped;              
};
#endif             
