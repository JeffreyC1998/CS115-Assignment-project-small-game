#include "Item.h"
#include <cassert>
#include "Location.h"

Item::Item()
{
  id = ID_NOT_INITIALIZED;
  Location();
  is_in_inventory = false;
  world_description = "";
  inventory_description = "";
  points = 0;
  
}

void Item::init (char id1,
		 const Location& location,
	       int points1,
               const string& world_description1,
               const string& inventory_description1)  //initialize the Item
{
  assert (id1 != ID_NOT_INITIALIZED);
  assert (world_description1 != "");
  assert (inventory_description1 != "");
  id = id1;
  points = points1;
  start_location = location;
  current_location = location;
  is_in_inventory = false;
  world_description = world_description1;
  inventory_description = inventory_description1;
  assert(invariant ());
  
}

void Item::debugPrint () const //to print all fields of the item
{
  cout << "id: " << '\'' << id << '\'' << '\n';
  cout << "start: " << start_location << '\n';
  cout << "current: " << current_location << '\n';
  cout << "is_in_inventory: " << is_in_inventory << '\n';
  cout << "points: " << points << '\n';
  cout << "world_description: " << '\"' << world_description << '\"' << '\n';
  cout << "inventory_description: " << '\"' << inventory_description << '\"' << '\n';
}

bool Item::isInitialized () const
{
  assert(invariant ());
  if(id != ID_NOT_INITIALIZED)
    return true;
  else
    return false;
 
}

char Item::getId () const //to get item's id
{
  assert(invariant ());
  return id;
  
}

bool Item::isInInventory () const //to return whether the items is in the player inventory
{
  assert(invariant ());
  return is_in_inventory;
 
}

bool Item::isAtLocation (const Location& location) const //to return whether the item is in the player's location
{
  assert(invariant ());
  if (!(current_location == location))
    return false;
  else
    return true;
 
}

int Item::getPlayerPoints () const //to return how many points the player gets
{
  assert(invariant ());
  if(is_in_inventory == true)
    return points;
  else
    return 0;
 
}

void Item::printDescription () const //to print the description if the item is in inventory
{
  assert(invariant ());
  if(is_in_inventory == true)
    cout << inventory_description << '\n';
  else
    cout << world_description << '\n';

}

void Item::reset () //to set the game
{
  assert(invariant ());
  current_location = start_location;
  is_in_inventory = false;
  assert(invariant ());
}

void Item::moveToInventory ()  //to move the item to player inventory
{
  assert(invariant ());
  is_in_inventory = true;
  assert(invariant ());
}

void Item::moveToLocation (const Location& location) //to move the item to the specified location
{
  assert(invariant ());
  current_location = location;
  is_in_inventory = false;
  assert(invariant ());
}

bool Item::operator< (const Item& other) const
{
  assert(invariant ());
  if (id < other.id)
    return true;
  else
    false;
  
}

bool Item::invariant () const
{
  bool status = true;
  if (world_description != "" && inventory_description != "")
    status = true;
  else
    status = false;
  return status;
}
