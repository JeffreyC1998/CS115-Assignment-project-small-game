#ifndef ITEM_H
#define ITEM_H

#include "Location.h"
#include <iostream>
using namespace std;

const char ID_NOT_INITIALIZED = '\0';

class Item
{
 public:
  Item ();
 void debugPrint () const;
 bool isInitialized () const;
 char getId () const;
 bool isInInventory () const;
 bool isAtLocation (const Location& location) const;
 int getPlayerPoints () const;
 void printDescription () const;
 bool operator< (const Item& other) const;
 void init (char id1,
const Location& location,
 int points1,
 const string& world_description1,
const string& inventory_description1);
void reset ();
 void moveToInventory ();
 void moveToLocation (const Location& location);

 private:
 bool invariant () const;
 
  char id;
  Location start_location ;
  Location current_location;
  bool is_in_inventory;
  string world_description;
  string inventory_description;
  int points;
};


#endif

 
