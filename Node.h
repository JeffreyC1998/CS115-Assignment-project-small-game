#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cassert>
#include "Location.h"
using namespace std;

const char REQUIRED_ITEM_NOT_SET = '\0';
class Node
{
 public:
  Node ();
  Node (const Node& to_copy);
  virtual ~Node ();
  Node& operator= (const Node& to_copy);
  virtual void debugPrint () const;
  virtual Node* getClone () const;
  Node (unsigned int description1,
      unsigned int north1,
      unsigned int south1,
      unsigned int east1,
      unsigned int west1,
      bool is_death1);
  unsigned int getDescription () const;
  Location getNorth () const;
  Location getSouth () const;
  Location getEast  () const;
  Location getWest  () const;
  bool isDeath () const;
  virtual bool isObstructed () const;
  virtual char getRequiredItem () const;
  virtual unsigned int getDescriptionFailure () const;
  virtual unsigned int getDescriptionSuccess () const;
 private:
  unsigned int description;
  unsigned int north;
  unsigned int south;
  unsigned int east;
  unsigned int west;
  bool is_death;

};

#endif
