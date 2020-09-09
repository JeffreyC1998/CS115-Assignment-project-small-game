
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "Item.h"
using namespace std;
#include "Game.h"
#include "ItemManager.h"
#include "World.h"
#include "Location.h"
#include "HighScores.h"


void doEndScore (const Game& game,
                 const string& player_name);

static const string GAME_NAME = "ghostwood";




int main()
{

	Game game("ghostwood");

	string input;
	string player_name;

        
	
	cout << "Welcome to Jungle Quest! " << '\n' << "You recently obtained an old treasure map in mysterious " << '\n' << "circumstances.  It showed the location of the Lost Jewel of " << '\n' << "Leopold II, evil king of the Congo Free State.  And since you " << '\n' << "have always wanted to be more like Indiana Jones, you have " << '\n' << "mounted an expedition to find it. " << endl;

	cout << "Your name is: ";
	getline(cin,player_name);

	
	

	game.world.printDescription(game.player_location);


		bool is_quit = false;
	while(!is_quit && !game.isOver())
	{
		cout << "Next? ";

		string line;
		do  // must get some input!
		{
			getline(cin, line);
		}
		while(line == "");

		char command = line[0];
		switch(command)
		{
		case 'q':
			cout << "Are you sure you want to quit? ";
			getline(cin, line);
			if(line != "" && line[0] == 'y')
				is_quit = true;
			break;

		case 'n':
			game.moveNorth();
			break;
		case 's':
			game.moveSouth();
			break;
		case 'e':
			game.moveEast();
			break;
		case 'w':
			game.moveWest();
			break;

		case 't':
			cout << "Take what? ";
			getline(cin, line);

			if(line != "")
				game.takeItem(line[0]);
			else
				cout << "Invalid item." << endl;
			break;

		case 'l':
			cout << "Leave what? ";
			getline(cin, line);

			if(line != "")
				game.leaveItem(line[0]);
			else
				cout << "Invalid item." << endl;
			break;

		case 'i':
			game.printInventory();
			break;

		case 'r':
			cout << "Are you sure you want to restart? ";
			getline(cin, line);
			if(line != "" && line[0] == 'y')
			{
				doEndScore(game, player_name);
				game.reset();
				game.printDescription();
			}
			break;

		default:
			cout << "Invalid command!" << endl;
			break;
		}
	}

	
        doEndScore(game, player_name);

	cout << "Thank you for playing Jungle Quest!" << endl;
	return 0;
}

void doEndScore (const Game& game,
                 const string& player_name)
{
	cout << endl;
	cout << "In this game you scored " << game.getScore() << " points." << endl;

	HighScores high_scores(GAME_NAME);
	high_scores.insert(game.getScore(), player_name);
	high_scores.save(GAME_NAME);
	high_scores.print();
	cout << endl;
}
