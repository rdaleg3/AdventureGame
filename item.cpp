#include "item.h"
using namespace std;
Item::Item()
{
 	name = "defalt";
	itemText = "It looks... like an error";
	useText = "You used it... it tastes like error";	   
	type = 1;
	value = 0; 
}
Item::Item(string n, string iText, string uText, int ty, int val, int id)
{
 	name = n;
	itemText = iText;
	useText = uText;
	type = ty;
	value = val; 
	itemID = id;
}
string Item::getName()
{
 	return name;
}
string Item::getItemText()
{
 	return itemText;
}
string Item::getUseText()
{
 	return useText;
}
int Item::getType()
{
 	return type;
}
int Item::getValue()
{ 
 	return value;
}

int Item::getID()
{
 	return itemID;
}
