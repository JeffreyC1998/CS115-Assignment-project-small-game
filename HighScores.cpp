//
//  HighScores.cpp
//

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>

#include "HighScores.h"

using namespace std;



HighScores :: HighScores ()
		: p_head(nullptr)
{
	assert(invariant());
}

HighScores :: HighScores (const string& game_name)
		: p_head(nullptr)
{
	string filename = getFilename(game_name);
	assert(filename != "");
	ifstream fin(filename);

	// special case: no high scores file
	if(!fin)
	{
		assert(invariant());
		return;
	}

	// general case: high scores already exist
	assert(fin.good());

	Element* p_tail = nullptr;

	while(true)  // loop exits on EOF below
	{
		// read score
		int score;
		fin >> score;

		if(!fin)
			break;  // loop drops out here
		assert(fin.good());

		// read player name
		string player_name;
		getline(fin, player_name);
		assert(fin.good());
		assert(player_name.size() > 1);

		// remove tab from player name
		assert(player_name != "");
		player_name = player_name.substr(1);
		assert(player_name != "");

		// insert new score into list
		//insert(score, player_name);  // if file is  unsorted

		// more efficient version for when file is already sorted
		Element* p_new_element = new Element;
		p_new_element->score  = score;
		p_new_element->name   = player_name;
		p_new_element->p_next = nullptr;

		if(p_tail == nullptr)
			p_head = p_new_element;
		else
			p_tail->p_next = p_new_element;
		p_tail = p_new_element;
	}

	assert(invariant());
}

HighScores :: HighScores (const HighScores& to_copy)
		: p_head(copyLinkedList(to_copy.p_head))
{
	assert(to_copy.invariant());
	assert(invariant());
}

HighScores :: ~HighScores ()
{
	assert(invariant());

	destroyLinkedList(p_head);
}

HighScores& HighScores :: operator= (const HighScores& to_copy)
{
	assert(invariant());
	assert(to_copy.invariant());

	if(&to_copy != this)
	{
		destroyLinkedList(p_head);
		p_head = copyLinkedList(to_copy.p_head);
	}

	assert(invariant());
	assert(to_copy.invariant());
	return *this;
}



void HighScores :: print () const
{
	assert(invariant());

	cout << "High Scores:" << endl;
	printToStream(cout);
}

void HighScores :: save (const string& game_name) const
{
	assert(invariant());

	ofstream fout(getFilename(game_name), ios::trunc);
	printToStream(fout);
}

void HighScores :: insert (int score, const string& player_name)
{
	assert(invariant());

	// create new element
	Element* p_new_element = new Element;
	p_new_element->score  = score;
	p_new_element->name   = player_name;
	p_new_element->p_next = nullptr;

	// special case: linked list was empty
	if(p_head == nullptr)
	{
		p_head = p_new_element;
		assert(invariant());
		return;
	}

	// special case: insert at front of linked list
	assert(p_head != nullptr);
	if(p_head->score <= score)
	{
		p_new_element->p_next = p_head;
		p_head = p_new_element;
		assert(invariant());
		return;
	}

	// general case: insert part way through the linked list
	Element* p_previous = p_head;
	assert(p_previous != nullptr);
	while(p_previous->p_next != nullptr &&
	      p_previous->p_next->score > score)
	{
		p_previous = p_previous->p_next;
		assert(p_previous != nullptr);
	}

	assert(p_previous != nullptr);
	assert(p_previous->score > score);
	assert(p_previous->p_next == nullptr ||
	       p_previous->p_next->score <= score);
	p_new_element->p_next = p_previous->p_next;
	p_previous->p_next = p_new_element;

	assert(invariant());
}



Element* HighScores :: copyLinkedList (const Element* p_old_head) const
{
	if(p_old_head == nullptr)
		return nullptr;

	// copy head
	Element* p_new_head = new Element;
	p_new_head->score  = p_old_head->score;
	p_new_head->name   = p_old_head->name;
	p_new_head->p_next = nullptr;

	// copy linked list after head
	const Element* p_old_current = p_old_head;
	Element*       p_new_current = p_new_head;
	while(p_old_current->p_next != nullptr)
	{
		p_old_current = p_old_current->p_next;

		p_new_current->p_next = new Element;
		p_new_current = p_new_current->p_next;

		p_new_current->score  = p_old_current->score;
		p_new_current->name   = p_old_current->name;
		p_new_current->p_next = nullptr;
	}

	// return head of new linked list
	return p_new_head;
}

void HighScores :: destroyLinkedList (Element* p_head) const
{
	while(p_head != nullptr)
	{
		Element* p_current = p_head;
		p_head = p_head->p_next;
		delete p_current;
	}
	assert(p_head == nullptr);
}

void HighScores :: printToStream (ostream& out) const
{
	for(Element* p_current = p_head;
	    p_current != nullptr;
	    p_current = p_current->p_next)
	{
		out << p_current->score << "\t"
			<< p_current->name << endl;
	}
}

string HighScores :: getFilename (const string& game_name) const
{
	return game_name + "_highscores.txt";
}

bool HighScores :: invariant () const
{
	for(Element* p_current = p_head;
	    p_current != nullptr;
	    p_current = p_current->p_next)
	{
		if(p_current->p_next != nullptr &&
		   p_current->score < p_current->p_next->score)
		{
			return false;
		}
	}
	return true;
}

