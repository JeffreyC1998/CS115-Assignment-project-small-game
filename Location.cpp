#include<iostream>
#include "Location.h"
using namespace std;

Location::Location()
{
  node = 0;
}

Location::Location(unsigned int node1)
{
  node = node1;
}

bool Location::operator== (const Location& other) const
{
  if ((node != other.node))
    return false;
  else
    return true;
}

bool Location::isInaccessible() const
{
  bool status;
  if(node == 0)
    status = true;
  else
    status = false;
  return status;
}
/*void Location::print(ostream& out) const
{
  out << "(row = " << row;
  out << "column = ) " << column;
  }*/
  




std::ostream& operator<< (std::ostream& out, const Location& location)
{
  out << "(node = " << location.node;
  return out;
}
 
