#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#define nullptr 0
#include <iostream>
#include <fstream>
#include <cassert>
#include "Item.h"
#include "Location.h"
using namespace std;



class ItemManager
{
 public:
  ItemManager ();
  ItemManager (const string& game_name);
  ItemManager (const ItemManager& to_copy);
  ~ItemManager ();
  ItemManager& operator= (const ItemManager& to_copy);
  int getScore () const;
  void printAtLocation (const Location& location) const;
  void printInventory () const;
  bool isInInventory (char id) const;
  void reset ();
  void take  (char id, const Location& player_location);
  void leave (char id, const Location& player_location);
  Item*  my_item_array;
  
 private:
  void load(const string& filename);
  unsigned int find (char id) const;
  void sort();
  bool invariant () const;
  unsigned int item_count;
};

#endif
