#include "textbox.h"
#include <allegro.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Textbox::Textbox()
{
    display = "";
    text = "I THINK I SMELL AN ERROR!";
    choice = -1;
    choiceA = "";
    choiceB = "";
    fontInUse = 0;
    typed = false;
    indexTyped = 1;    
}
Textbox::Textbox(std::string message)
{
    display = "";
    text = message;
    choice = -1;
    choiceA = "";
    choiceB = "";
    fontInUse = 0;
    typed = false;
    indexTyped = 1;
}
Textbox::Textbox(string message, string choice1, string choice2)
{
    
    display = "";
    text = message;
    choice = 0;
    choiceA = choice1;
    choiceB = choice2;
    fontInUse = 0;
    typed = false;
    indexTyped = 1;
}

Textbox::Textbox(string message, int fontSelect)
{ // maybe add later functionality
    display = "";
    text = message;
    choice = -1;
    choiceA = "";
    choiceB = "";
    fontInUse = fontSelect;
    typed = false;
    indexTyped = 1;
}             
void Textbox::draw(BITMAP *sbmp, int camX, int camY)
{
     textout_ex(sbmp, font, display.c_str(), camX+10, camY+10, -1, 0 );
     if (display.size() != text.size())
     {
         display = text.substr(0, indexTyped);
         rest(20);
         indexTyped++;
     }
     if (indexTyped >= text.size())
        typed = true;
}
     
bool Textbox::isFinished()
{
     return typed;
}
int Textbox::getChoice() 
{
    return choice;
}
void Textbox::rush()
{
     indexTyped = text.size();
}
