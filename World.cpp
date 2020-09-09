#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include <cassert>
using namespace std;
#include "Location.h"
#include "World.h"

World::World(const World& to_copy)
{
  NODE_COUNT = to_copy.NODE_COUNT;
  VICTORY_NODE = to_copy.VICTORY_NODE;
  START_NODE = to_copy.START_NODE;

  node_array = new Node*[NODE_COUNT];
  for(int i = 0;i< NODE_COUNT;i++)
    {
      node_array[i] = to_copy.node_array[i]->getClone();
    }
}

World::~World ()
{
  for(int i = 0;i < NODE_COUNT;i++)
    {
      delete node_array[i];
    }

}

World& World::operator= (const World& to_copy)
{
  if(&to_copy != this)
    {
       for(int i = 0;i < NODE_COUNT;i++)
         {
	   delete node_array[i];
	 }
       node_array = new Node*[NODE_COUNT];
       for(int i = 0;i< NODE_COUNT;i++)
	 {
	   node_array[i] = to_copy.node_array[i]->getClone();
	 }
    }
  return *this;

}
void World::loadNodes(const string& filename)
{
  assert(node_array == nullptr);
  ifstream inf;
  char ch;
  inf.open(filename.c_str());
  char require_item;
  unsigned int description,north,south,east,west;
  unsigned int description_failure;
  unsigned int description_success;	

  if (!inf.fail())
    {
      inf >> NODE_COUNT >> START_NODE >> VICTORY_NODE;
      for (unsigned int i = 0; i < 62; i++)
	{


	  node_array = new Node*[NODE_COUNT];
	  inf >> ch;

	  cout << ch << endl;

	  inf >> description >> north >> south >> east >> west;

	  if(ch == 'N')
	    {
	      node_array[i] = (Node*)(description,north,south,east,west,false);
	    }
	  else if(ch == 'D')
	    node_array[i] = (Node*)(description,north,south,east,west,true);
	  else if(ch == 'O')
	    {
	      node_array[i] = (ObstructedNode*)(description,north,south,east,west,false,require_item,description_failure,description_success);
	    }
        
	}

    }
  else
    {
      cout << "Can not open" << endl;
    }

}

void World::loadDescriptions(const string& filename)
{
	ifstream inf;
	inf.open(filename.c_str());
	int var;
	inf >> var;
	if (var != DESCRIPTION_COUNT)
	{
		cout << "error";
		exit(1);
	}
	string line;
	getline(inf, line);
	getline(inf, line);


	cout << line;
	for (int i = 0; i < DESCRIPTION_COUNT; i++)
	{
		getline(inf, line);
		while (line != "")
		{
			descriptions[i] += line + '\n';
			getline(inf, line);
		}
	}

	for (int i = 0; i < DESCRIPTION_COUNT; i++)
	{
		cout << i << ": " << descriptions[i] << endl;
	}
}

World::World (const string& game_name)
{
  node_array == nullptr;
  loadNodes(game_name + "_nodes.txt");
  loadDescriptions(game_name + "_text.txt");
  assert(invariant());
}

void World::debugPrint() const
{
 
  for (int i = 0; i < NODE_COUNT; i++)
    {
      cout << "check" << endl;
      node_array[i]->debugPrint();	
    }
}

Location World::getStart() const
{
  assert(invariant());
  
  return START_NODE;
}
bool World::isValid(const Location& location) const
{
        assert(invariant());
	if (location.node < NODE_COUNT)
	{
		return true;
	}

	else
		return false;
}

void World::printDescription(const Location& location) const
{
  assert(invariant());

	cout << descriptions[node_array[location.node]->getDescription()] << endl;
}

bool World::canGoNorth(const Location& location) const
{
  assert(invariant());
  Location loc(node_array[location.node]->getNorth());
  if(!loc.isInaccessible())
    return true;
  else
    return false;
}

bool World::canGoSouth(const Location& location) const
{
  assert(invariant());
  bool status;
  Location loc(node_array[location.node]->getSouth());
  if(!loc.isInaccessible())
    status = true;
  else
    status = false;
  return status;

}

bool World::canGoEast(const Location& location) const
{
  assert(invariant());
  bool status;
  Location loc(node_array[location.node]->getEast());
  if(!loc.isInaccessible())
    status = true;
  else
    status = false;

}

bool World::canGoWest(const Location& location) const
{
  assert(invariant());
  bool status;
  Location loc(node_array[location.node]->getWest());
  if(!loc.isInaccessible())
    status = true;
  else
    status = false;

  return status;
}

Location World::getNorth (const Location& location) const
{
  assert(invariant());
  
  if(canGoNorth(location))
  {
    Location loc(node_array[location.node]->getNorth());
    return loc;
  }
  else
    return location;
}

Location World::getSouth (const Location& location) const
{
  assert(invariant());
  if(canGoSouth(location))
  {
    Location loc(node_array[location.node]->getSouth());
    return loc;
  }
  else
    return location;
  
}

Location World::getEast (const Location& location) const
{
  assert(invariant());
  if(canGoEast(location))
  {
    Location loc(node_array[location.node]->getEast());
    return loc;
  }
  else
    return location;
  
}

Location World::getWest (const Location& location) const
{
  assert(invariant());
  if(canGoWest(location))
  {
    Location loc(node_array[location.node]->getWest());
    return loc;
  }
  else
    return location;
}

bool World::isDeath(const Location& location) const
{
  assert(invariant());
  return node_array[location.node]->isDeath();
}

 bool World::isVictory(const Location& location) const
 {
   assert(invariant());
   if(location.node == VICTORY_NODE)
     return true;
   else
     return false;
 }
 
 bool World::isObstructed (const Location& location) const
{
  if(node_array[location.node]->isObstructed())
    return true;
  else
    return false;
}

char World::getRequiredItem (const Location& location) const
 {
   assert(isObstructed(location) == true);
   return node_array[location.node]->getRequiredItem();
 }

void World::printDescriptionFailure (const Location& location) const
 {
   assert(isObstructed(location) == true);
   cout << descriptions[node_array[location.node]->description_failure] << endl;
 }

void World::printDescriptionSuccess (const Location& location) const
 {
   assert(isObstructed(location) == true);
   cout << descriptions[node_array[location.node]->description_success] << endl;
 }
   
bool World::invariant () const
{
  for(int i = 0;i < NODE_COUNT; i++)
    {
      if(node_array[i] == nullptr)
	return false;
    }
  if(DESCRIPTION_COUNT < MAX_DESCRIPTION_COUNT && START_NODE < NODE_COUNT && VICTORY_NODE < NODE_COUNT)
    return true;
  else 
    return false;

}
