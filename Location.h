#ifndef LOCATION_H
#define LOCATION_H

#include<iostream>
using namespace std;

class Location
{
 
 public:
  Location();
  Location(unsigned int node1);
  bool operator== (const Location& other) const;
  unsigned int node;
  bool isInaccessible () const;
};

ostream& operator<< (ostream& out, const Location& location);

#endif
 
