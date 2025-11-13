#ifndef characterType_h
#define characterType_h

#include <iostream>

using namespace std;

//headers by Ellie
class characterType{
	
  private:
  
  string race; 
  //This is a private variable that will store the race of the character created by the player
  //Example: elf, dwarf, dragonborn (selected from menu)
  
  string charClass;
  //This is a private variable to store the character’s class
  //Example: Barbarian, druid, rogue (selected from menu)
  		
  string name;
  //This is a variable to store the name of the character entered by player

  int gold = 0;
  //this variable holds the amount of gold the player has

  string items[50];
  //this is a variable for the player's inventory

  int numList = 0;
  //stores number of items in the list
  
  public:
  void setRace(string);
  //a function that will set the race of the character input by user (of type string)
  
  string getRace();
  //a function that returns the race input by user
  
  
  void setClass(string);
  //a function that will set the class of the character input by user (of type string)
  
  string getClass();
  //a function that returns the class input by user
  
  void setName(string);
  //a function that will set the name of the character input by user (of type string)
  
  string getName();
  //a function that returns the name input by user

  void addGold(int);
  //this function adds to the player's current amount of gold

  int getGold();
  //returns gold

  void addItem(string);
  //adds item to inventory

  void printItem();
  //prints all items in the inventory

  int getNumItems();
  // return number of items in inventory

  void removeItem(int);
  // remove item from inventory

  string getItem(int);
  // get the item at a specfic index

};


void characterType::setRace(string r){
  race = r;
}


string characterType::getRace(){
  return race;
}


void characterType::setClass(string c){
  charClass = c;
}


string characterType::getClass(){
  return charClass;
}


void characterType::setName(string n){
  name = n;
}

string characterType::getName(){
  return name;
}

void characterType::addGold(int g){
  gold = gold + g;
}

int characterType::getGold(){
  return gold;
}

void characterType::addItem(string i){
  items[numList] = i;
  numList++;
}

void characterType::printItem(){
  for(int i = 0; i < numList; i++){
    cout << items[i] << ", ";
  }
}

int characterType::getNumItems(){
  return numList;
}

string characterType::getItem(int index){
  if (index >= 0 && index < numList) {
    return items[index];
}
return "";  // Return an empty string if index is invalid
}

void characterType::removeItem(int index) {
  if (index >=0 && index < numList) {
    for (int i = index; i < numList - 1; i++) {
        items[i] = items[i + 1];  // Shift items left
    }
    numList--;  // Decrease item count
  }
}

#endif

