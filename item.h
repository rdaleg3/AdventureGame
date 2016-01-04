#ifndef ITEM_H
#define ITEM_H
#include <allegro.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
class Item
{ 
      friend class Game;
public:
      explicit Item();
      explicit Item(std::string n, std::string iText, std::string uText, int ty, int val, int id);
      std::string getName();
	  std::string getItemText();
	  std::string getUseText();
	  int getType();
	  int getValue();
	  int getID();
 
      
private:
     std::string name;
	 std::string itemText;
	 std::string useText;
	 int type;
	 int value;
	 int itemID;

};
#endif
