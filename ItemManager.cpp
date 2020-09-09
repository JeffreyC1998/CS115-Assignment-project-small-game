#include "ItemManager.h"
#include "Item.h"
#include "Location.h"
#include <cassert>

const int NO_SUCH_ITEM = 999999999;
ItemManager::ItemManager()
{
  item_count = 0;
  my_item_array = new Item[item_count];
  assert(invariant ());
}
ItemManager::ItemManager(const string& game_name)
{
  
  for(int i = 0;i< item_count;i++)
    {
      my_item_array = nullptr;
    }
  load(game_name);
  sort();
  assert(invariant ());
  
}

ItemManager::ItemManager(const ItemManager& to_copy)
{
  assert(invariant ());
  item_count = to_copy.item_count;
  my_item_array = new Item[item_count];
  for(int i = 0;i<item_count;i++)
    {
      my_item_array[i] = to_copy.my_item_array[i];
    }
  assert(invariant ());
  assert(to_copy.invariant ());
}

ItemManager::~ItemManager()
{
  delete[] my_item_array;
}

ItemManager& ItemManager::operator=(const ItemManager& to_copy)
{
  assert(invariant ());
  assert(to_copy.invariant());
  if (&to_copy != this)
    {
      delete [] my_item_array;
      item_count = to_copy.item_count;
    }
  return *this;
  assert(invariant ());
  assert(to_copy.invariant());
}

void ItemManager::load(const string& filename)
{
  assert(my_item_array != nullptr);
  ifstream inf;
  inf.open(filename.c_str());
  string tempid;
  char id;
  unsigned int start_location;
  int points;
  string world_description;
  string inventory_description;
  string line;

  if(!inf.fail())
    {
      inf >> item_count;
      for(int i = 0;i<item_count;i++)
	{
	  getline(inf,line);
	  getline(inf,line);
	  inf >> tempid >> start_location >> points;
	  getline(inf,world_description);
	  getline(inf,inventory_description);
	  id = tempid.at(0);
	  my_item_array[i].init(id,start_location,points,world_description,inventory_description);
	}
    }
  else
    {
      cout << "Can not open " << endl;
    }

}


int ItemManager::getScore() const
{
  assert(invariant ());
  int score = 0;
  for (int i = 0;i < item_count;i++)
		    {
		      if (my_item_array[i].isInInventory() == true)
		      {		        
			    score = score + my_item_array[i].getPlayerPoints();

		      }

		    }
  return score;
}

void ItemManager::printAtLocation(const Location& location) const
{
  assert(invariant ());
  for(int i = 0;i < item_count;i++)
		      {
			if(my_item_array[i].isAtLocation(location))
			  my_item_array[i].printDescription();
		      }
}

void ItemManager::printInventory () const
{
  assert(invariant ());
  for(int i = 0;i < item_count ; i++)
    {
      if(my_item_array[i].isInInventory() == true)
	my_item_array[i].printDescription();
    }

}

void ItemManager::reset()
{
  assert(invariant ());
  for(int i = 0;i< item_count; i++)
    {
     my_item_array[i].reset();
    }
  assert(invariant ());
}

unsigned int ItemManager::find (char id) const
{
  /*int i;
  for(i = 0;i < item_count;i++)
    {
      if(id == my_item_array[i].getId())
	return i;
    }

   return NO_SUCH_ITEM;
  */

  int low = 0;
  int high = item_count - 1;
  while(low <= high)
    {
      int mid = (low + high) / 2;
      if(id == my_item_array[mid].getId())
	{
	  return mid;
	}
      else if( id < my_item_array[mid].getId())
	{
	  high = mid - 1;
	}
      else if( id > my_item_array[mid].getId())
	{
	  low = mid + 1;
	}
    }
  return -1;

}

bool ItemManager::isInInventory (char id) const
{
  assert(invariant ());
  if(find(id) != NO_SUCH_ITEM)
    return true;
  else
    return false;
}

void ItemManager::take(char id, const Location& player_location)
{
  assert(invariant ());
     for (int i = 0;i < item_count;i++)
		    {
		      if (id == my_item_array[i].getId())
		      {
			if (my_item_array[i].isAtLocation(player_location) == true)
			    my_item_array[i].moveToInventory();
		      }
		    }
   assert(invariant ());
}

void ItemManager::leave (char id, const Location& player_location)
{
  assert(invariant ());
  int i;
  for (i = 0;i < item_count;i++)
		    {
		      if (id == my_item_array[i].getId())
		      {
			if (my_item_array[i].isInInventory())
			  my_item_array[i].moveToLocation(player_location);
		      }
		    }
  if(i = 10)
    cout << "Invalid item" << endl;
  assert(invariant ());
}

void ItemManager::sort()
{
  int i,j,search_min;
  Item temp;
  for( i = 0;i<item_count;i++)
    {
      search_min = i;
      for(j = i + 1;j < item_count;j++)
	{
	  if (my_item_array[j] < my_item_array[search_min])
	    {
	      search_min = j;
	    }
	  
	}
      temp = my_item_array[i];
      my_item_array[search_min] = my_item_array[i];
      my_item_array[i] = temp;
    }
}
      
bool ItemManager::invariant() const
{
  int i;
  for(i = 0;i<item_count;i++)
    {
      if(!my_item_array[i].isInitialized() || (my_item_array == nullptr))
	return false;
    }

  for(i = 0;i < item_count - 1;i++)
    {
      if(my_item_array[i+1] < my_item_array[i])
	return false;
    }


  return true;
}

