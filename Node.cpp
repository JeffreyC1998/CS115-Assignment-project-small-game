#include "Node.h"

Node::Node()
{
  description = 0;
  north = 0;
  south = 0;
  east = 0;
  west = 0;
  is_death = false;
}

Node::Node(const Node& to_copy)
  :description(to_copy.description),
   north(to_copy.north),
   south(to_copy.south),
   east(to_copy.east),
   west(to_copy.west),
   is_death(to_copy.is_death)
{
  
}

Node::~Node ()
{
}

Node& Node::operator= (const Node& to_copy)
{
  if (&to_copy != this)

     {

           // nothing from destructor

           // no base class from which to call operator

 

           // from copy constructor
           description = to_copy.description;
           north = to_copy.north;
           south = to_copy.south;
           east = to_copy.east;
           west = to_copy.west;
           is_death = to_copy.is_death;
           
     }

     return *this;
}
Node::Node(unsigned int description1,
      unsigned int north1,
      unsigned int south1,
      unsigned int east1,
      unsigned int west1,
	   bool is_death1)
{
  description = description1;
  north = north1;
  south = south1;
  east = east1;
  west = west1;
  is_death = is_death1;
}

void Node::debugPrint () const
{
  if(is_death)
    cout << 'D' << endl;
  else
    cout << 'N' << endl;
  cout << "Description number is: " << description << endl;
  cout << "North is: " << north << endl;
  cout << "South is: " << south << endl;
  cout << "East is: " << east << endl;
  cout << "West is: " << west << endl;
}

Node* Node::getClone () const
{
  Node* pNode = new Node(*this);
  return pNode;
}

bool Node::isObstructed () const
{
  return false;
}

char Node::getRequiredItem () const
{
  assert(isObstructed () == true);
  return REQUIRED_ITEM_NOT_SET;
  
}

unsigned int Node::getDescriptionFailure () const
{
  assert(isObstructed());
  return 0;
}

unsigned int Node::getDescriptionSuccess () const
{
  assert(isObstructed());
  return 0;
}
unsigned int Node::getDescription () const
{
  return description;
}

bool Node::isDeath () const
{
  return is_death;
}

Location Node::getNorth () const
{
  return north;
}

Location Node::getSouth () const
{
  return south;
}

Location Node::getEast() const
{
  return east;
}

Location Node::getWest() const
{
  return west;
}
