#include "Game.h"

Game::Game (const string& game_name)
  :world(game_name),itemmanager(game_name),player_location()
{
  player_location=world.getStart();
  assert(invariant ());
}

bool Game::isOver () const
{
  assert(invariant ());
  if(world.isDeath(player_location) || world.isVictory(player_location))
    return true;
  else
    return false;
}

void Game::printDescription () const
{
  assert(invariant ());
  world.printDescription(player_location);
}

int Game::getScore () const
{
  assert(invariant ());
  return itemmanager.getScore();
}

void Game::printInventory () const
{
  assert(invariant ());
  itemmanager.printInventory ();
}

void Game::moveNorth ()
{
  assert(invariant ());
  if(world.canGoNorth(player_location) == true)
				  {
				    player_location = moveTo(player_location);
					world.printDescription(player_location);
					itemmanager.printAtLocation(player_location);
				   }
				else
					cout << "Can not reach " << endl;
				assert(invariant ());
}

void Game::moveSouth ()
{
  assert(invariant ());
  if(world.canGoSouth(player_location) == true)
				  {
					player_location = moveTo(player_location);
					world.printDescription(player_location);
					itemmanager.printAtLocation(player_location);
				  }
				else
					cout << "Can not reach " << endl;
				assert(invariant ());
}

void Game::moveEast ()
{
  assert(invariant ());
  if(world.canGoEast(player_location) == true )
				  {
				    player_location = moveTo(player_location);
				    world.printDescription(player_location);
				    itemmanager.printAtLocation(player_location);
				   }
				else
					cout << "Can not reach " << endl;
				assert(invariant ());
}

void Game::moveWest ()
{
  assert(invariant ());
  if(world.canGoWest(player_location) == true )
				  {
				    player_location = move(player_location);
				    world.printDescription(player_location);
			            itemmanager.printAtLocation(player_location);
				  }
				else
					cout << "Can not reach " << endl;
				assert(invariant ());
}

void Game::takeItem (char id)
{
  assert(invariant ());
  itemmanager.take(id,player_location);
  assert(invariant ());
}

void Game::leaveItem (char id)
{
  assert(invariant ());
  itemmanager.leave(id,player_location);
  assert(invariant ());
}

void Game::reset ()
{
  assert(invariant ());
  itemmanager.reset();
  assert(invariant ());
}

void Game::moveTo (const Location& location)
{
  if(world.iObstructed(location) != true)
    {
      play_location = location;
      printDescription();
    }
  else
    {
      if((world.isObstructed(player_location) == true))
	{
	  player_location = location;
	  printDescription();
	}
      else
	{
	  if(itemmanager.isInInventory(world.getRequiredItem(location)))
	    world.printDescriptionSuccess(location);
	  else
	    world.printDescriptionFailure(location);
	}
    }
}
	    
bool Game::invariant () const
{
  if(world.isValid(player_location) == true)
    return true;
  else
    return false;
}
