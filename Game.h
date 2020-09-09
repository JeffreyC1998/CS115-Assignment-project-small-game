#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cassert>
#include "World.h"
#include "ItemManager.h"
#include "Location.h"
#include "Node.h"
using namespace std;

class Game
{
 public:
  Game (const string& game_name);
  bool isOver () const;
  int getScore () const;
  void printDescription () const;
  void printInventory () const;
  void reset ();
  void moveNorth ();
  void moveSouth ();
  void moveEast ();
  void moveWest ();
  void takeItem (char id);
  void leaveItem (char id);
  World world;
  ItemManager itemmanager;
  Location player_location;
 private:
  void moveTo (const Location& location);
  bool invariant () const;
};

#endif

 
