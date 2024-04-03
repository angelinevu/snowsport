#include "snowsport.h"

//Angeline Vu, 2/2/2024, CS302-001, Program 1
//This file manages the sport related functions:
//parent sport class, ski, iceskate, snowboard

//Sport functions
//Default constructor
sport::sport() : name(nullptr), score(0) {}

//Constructor setting name
sport::sport(const string & a_name) : score(0)
{
	name = nullptr;
	set_name(a_name);
}

//Copy constructor
sport::sport(const sport & a_sport) : score(a_sport.score)
{
	name = new char[strlen(a_sport.name) + 1];
	strcpy(name, a_sport.name);
}

//Assignment operator
sport & sport::operator=(const sport & src)
{
	if (this == &src)
		return *this;

	if (name)
		delete [] name;

	name = new char[strlen(src.name) + 1];
	strcpy(name, src.name);

	return *this;
}

//Displays athlete name and score
int sport::display()
{
	if (!name)
		return 0;
	cout << "Athlete " << name;
	return 1;
}

//Sets athlete name
int sport::set_name(const string & a_name)
{
	if (name)
		delete [] name;
	name = new char[strlen(a_name.c_str()) + 1];
	strcpy(name, a_name.c_str());
	return 1;
}

//Adjusts athlete score & displays event
int sport::adjust_score(const int change)
{
	if (!change)
		return 0;
	score += change;
	return 1;
}

//Compares names, returns true if same
bool sport::compare_name(const string & a_name)
{
	if (!strcmp(a_name.c_str(), name))
		return true;
	return false;
}

//Compares scores, returns true if this greater
bool sport::greater_score(const sport & a_sport)
{
	if (score >= a_sport.score)
		return true;
	return false;
}

//Destructor
sport::~sport()
{
	if (name)
		delete [] name;
	name = nullptr;
	score = 0;
}

//Ski functions
//Default Constructor
ski::ski() {}

//Copy constructor
ski::ski(const ski & src) : sport(src) {}

//Sets name in parent class
ski::ski(const string & a_name) : sport(a_name) {}

//Adjsut score
int ski::adjust_score(const int change)
{
	if (change%MOD == 1)
	{
		sport::adjust_score(MINUS);
		return lost_ski();	
	}

	if (change%MOD == 2)
	{
		sport::adjust_score(2*MINUS);
		return buried();	
	}

	if (change%MOD == 3)
	{
		sport::adjust_score(3*MINUS);
		return faceplant();	
	}

	if (change%MOD == 4)
	{
		sport::adjust_score(PLUS);
		display();
		cout << " is blazing through!\n";
	}

	sport::adjust_score(PLUS);
	return 1;
}

//Events
int ski::lost_ski()
{
	if (!display())
		return 0;
	cout << " lost a ski in the snow...\n";
	return 1;
}

int ski::buried()
{
	if (!display())
		return 0;
	cout << " fell and got buried in the snow!\n";
	return 1;
}

int ski::faceplant()
{
	if (!display())
		return 0;
	cout << " faceplanted...!\n";
	return 1;
}

//Snowboard functions
//Constructor
snowboard::snowboard() {}

//Copy constructor
snowboard::snowboard(const snowboard & src) : sport(src) {}

//Sets name in parent class
snowboard::snowboard(const string & a_name) : sport(a_name) {}

//Adjust score
int snowboard::adjust_score(const int change)
{
	if (change%MOD == 1)
	{
		sport::adjust_score(MINUS);
		return twist_ankle();	
	}

	if (change%MOD == 2)
	{
		sport::adjust_score(2*MINUS);
		return broken_arm();	
	}

	if (change%MOD == 3)
	{
		sport::adjust_score(3*MINUS);
		return lost_board();	
	}

	if (change%MOD == 4)
	{
		sport::adjust_score(PLUS);
		display();
		cout << " is blazing through!\n";
	}

	sport::adjust_score(PLUS);
	return 1;
}

//Events
int snowboard::twist_ankle()
{
	if (!display())
		return 0;
	cout << " twisted an ankle...\n";
	return 1;
}

int snowboard::broken_arm()
{
	if (!display())
		return 0;
	cout << " broke an arm...\n";
	return 1;
}

int snowboard::lost_board()
{
	if (!display())
		return 0;
	cout << " lost their board...\n";
	return 1;
}

//Iceskate functions
//Constructor
iceskate::iceskate() : nickname(nullptr) {}

//Copy constructor
iceskate::iceskate(const iceskate & src) : sport(src)
{
	nickname = new char[strlen(src.nickname) + 1];
	strcpy(nickname, src.nickname);
}

//Initializes name in parent function
iceskate::iceskate(const string & a_name, const string & a_nick) : sport(a_name) 
{
	nickname = nullptr;
	set_nick(a_nick);
}

//Assignment operator
iceskate & iceskate::operator=(const iceskate & src)
{
	if (this == &src)
		return *this;

	sport::set_name(src.name);
	set_nick(src.nickname);
	return *this;
}

//Display function
int iceskate::display()
{
	if (!sport::display() || !nickname)
		return 0;
	cout << " the " << nickname;
	return 1;
}

//Set nickname for athlete
int iceskate::set_nick(const string & new_nick)
{
	if (nickname)
		delete [] nickname;

	nickname = new char[strlen(new_nick.c_str()) + 1];
	strcpy(nickname, new_nick.c_str());
	return 1;
}

//Adjsut score
int iceskate::adjust_score(const int change)
{
	if (change%MOD == 1)
	{
		sport::adjust_score(MINUS);
		return fall();	
	}

	if (change%MOD == 2)
	{
		sport::adjust_score(2*MINUS);
		return slip();	
	}

	if (change%MOD == 3)
	{
		sport::adjust_score(3*MINUS);
		return broken_ankle();	
	}

	if (change%MOD == 4)
	{
		sport::adjust_score(PLUS);
		display();
		cout << " is blazing through!\n";
	}

	sport::adjust_score(PLUS);
	return 1;
}

//Events
int iceskate::fall()
{
	if (!display())
		return 0;
	cout << " fell into a ditch...\n";
	return 1;
}

int iceskate::slip()
{
	if (!display())
		return 0;
	cout << " slipped and slid into a tree...\n";
	return 1;
}

int iceskate::broken_ankle()
{
	if (!display())
		return 0;
	cout << " broke their ankle...!\n";
	return 1;
}

//Destructor
iceskate::~iceskate()
{
	if (nickname)
		delete [] nickname;
	nickname = nullptr;
}
