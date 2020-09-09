#include "ObstructedNode.h"


ObstructedNode::ObstructedNode () :Node()
{
  required_item = REQUIRED_ITEM_NOT_SET;
  description_success = 0;
  description_failure = 0;
}

ObstructedNode::ObstructedNode (const ObstructedNode& to_copy)
  :Node(to_copy),
   required_item(to_copy.required_item),
   description_success(to_copy.description_success),
   description_failure(to_copy.description_failure)
{

}

ObstructedNode::~ObstructedNode ()
{

}

ObstructedNode& ObstructedNode::operator= (const ObstructedNode& to_copy)
{
  if(&to_copy != this)
    {
      Node::operator= (to_copy);

      required_item = to_copy.required_item;
      description_success = to_copy.description_success;
      description_failure = to_copy.description_failure;
    }
  return *this;
}

ObstructedNode::ObstructedNode (unsigned int description1,
                unsigned int north1,
                unsigned int south1,
                unsigned int east1,
                unsigned int west1,
                char required_item1,
                unsigned int description_failure1,
                unsigned int description_success1)
  :Node(description1,north1,south1,east1,west1,false)
{
  required_item = required_item1;
  description_success = description_success1;
  description_failure = description_failure1;
}

void ObstructedNode::debugPrint () const
{
  cout << 'O' << endl;
  cout << "Description number is: " << getDescription() << endl;
  cout << "North is: " << getNorth() << endl;
  cout << "South is: " << getSouth() << endl;
  cout << "East is: " << getEast() << endl;
  cout << "West is: " << getWest() << endl;
  cout << "required item is: " << required_item << endl;
  cout << "description of success is: " << description_success << endl;
  cout << "description of failure is: " << description_failure << endl;
}

Node* ObstructedNode::getClone () const
{
  Node* pO = new ObstructedNode(*this);
  return pO;
}

bool ObstructedNode::isObstructed () const
{
  return true;
}

unsigned int ObstructedNode::getDescriptionFailure () const
{
  assert(isObstructed () == true);
  return description_failure;
}

unsigned int ObstructedNode::getDescriptionSuccess () const
{
  assert(isObstructed () == true);
  return description_success;
}
    
