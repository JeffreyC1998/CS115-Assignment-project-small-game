#ifndef WORLD_H
#define WORLD_H

#include "Node.h"
#include "ObstructedNode.h"
#include "Location.h"
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std; 
const unsigned int MAX_DESCRIPTION_COUNT = 1000;
const unsigned int DESCRIPTION_COUNT = 54;

class World
{
 private:

  string descriptions[DESCRIPTION_COUNT];
  void loadNodes (const string& filename);
  void loadDescriptions (const string& filename);
  bool invariant () const;
  unsigned int NODE_COUNT;
  unsigned int VICTORY_NODE;
  unsigned int START_NODE;
  Node** node_array;

 
 public:
 World (const string& game_name);
 World (const World& to_copy);
 ~World ();
 World& operator= (const World& to_copy);
 void debugPrint () const;
 Location getStart () const;
 bool isValid (const Location& location) const;
 void printDescription (const Location& location) const;
 bool canGoNorth (const Location& location) const;
 bool canGoSouth (const Location& location) const;
 bool canGoEast  (const Location& location) const;
 bool canGoWest  (const Location& location) const;
 Location getNorth (const Location& location) const;
 Location getSouth (const Location& location) const;
 Location getEast  (const Location& location) const;
 Location getWest  (const Location& location) const;
 bool isAccessible (const Location& location) const;
 bool isDeath   (const Location& location) const;
 bool isVictory (const Location& location) const;
 bool isObstructed (const Location& location) const;
 char getRequiredItem (const Location& location) const;
 void printDescriptionFailure (const Location& location) const;
 void printDescriptionSuccess (const Location& location) const;
};
#endif 
