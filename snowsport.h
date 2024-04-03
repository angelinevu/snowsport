#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//Angeline Vu, 2/2/2024, CS302-001, Program 1
//This program simulates a race of some snow sport. There is a set 
//number of athletes with set names. There will be 3 randomly
//generated wave of events that determine the winner.

//This file has class interfaces, prototypes, and
//global constants.

//Global Constants
const int PEOPLE = 10;	//10 competitors
const int EVENTS = 5;	//5 racing events
const int PLUS = 25;	//Points for no misfortune
const int MINUS = -5;	//Misfortune points
const int MOD = 10;	//Helper constant for rand

//Constant names
const vector<string> alphabet = {"Alpha", "Beta", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "Indigo", "John"};
const vector<string> nickname = {"Alligator", "Bear", "Cheetah", "Deer", "Elephant", "Fox", "Gorilla", "Hippo", "Ibis", "Jaguar"};

//Menu Prototype
int menu();		//User chooses sport
void pause();		//Pauses UI

//Initialize structures
void initialize_ski(class LLLski & athletes);
void initialize_snowboard(class CLLboard & athletes);
void initialize_iceskate(class LLLiceskate & athletes);

//Parent Class 
class sport
{
	public:
		sport();				//Default Constructor
		sport(const string & a_name);		//Constructor with name
		sport(const sport & a_sport);		//Copy constructor
		sport & operator=(const sport & src);	//Assignment operator
		int display();				//Display name
		int set_name(const string & name);	//Sets name
		int adjust_score(const int change);		//Adjustment to score (+/-)
		bool compare_name(const string & a_name);	//Compares name
		bool greater_score(const sport & a_sport);	//Compares score
		~sport();

	protected:
		char * name;	//Name of athlete
		int score;	//Determines placement
};

//Ski Class
class ski : public sport 
{
	public:
		ski();					//Default Constructor
		ski(const ski & src);			//Copy Constructor
		ski(const string & a_name);		//Constructor for hierarchy
		int adjust_score(const int change);	//Adjustment to score (+/-)

		//Event
		int lost_ski();
		int buried();
		int faceplant();
};

//Ski Node Class
class skiNode : public ski
{
	public:
		skiNode();			//Constructor
		skiNode(const string & a_name);	//Constructor initializing name
		skiNode(const skiNode & src);	//Copy constructor
		int set_next(skiNode * next);	//Setter
		skiNode * & get_next();		//Get next node
		~skiNode();			//Destructor

	private:
		skiNode * next;		//Node class
};

//ski LLL Class
class LLLski
{
	public:
		LLLski();					//Default Constructor
		LLLski(const LLLski & source);			//Copy Constructor
		LLLski & operator=(const LLLski & src);		//Assignment Op
		int insert(const skiNode & athlete);		//Add a new athlete

		skiNode * retrieve(string & name);	//Get an athlete
		int remove(string & name);		//Remove an athlete
		int remove_all();			//Remove all athletes
		int display();				//Display name
		int adjust_score();			//Adjust score
		int sort();				//Sort

		~LLLski();					//Destructor

	private:
		int copy_all(skiNode * src);		//Copy All
		int copy_all(skiNode * source, skiNode * & head);
		skiNode * retrieve(skiNode * head, string & name);	
		int remove(skiNode * & head, string & name);
		int remove_all(skiNode * & head);
		int display(skiNode * head);
		int adjust_score(skiNode * head);

		int sort(skiNode * src, skiNode * & head);
		int insert_sort(skiNode * src, skiNode * & head);

		skiNode * head;					//Head of LLL
};

//Snowboarding Class
class snowboard : public sport 
{
	public:
		snowboard();				//Default Constructor
		snowboard(const snowboard & src);	//Copy Constructor
		snowboard(const string & a_name);	//Constructor for hierarchy
		int adjust_score(const int change);	//Adjustment to score (+/-)

		//Events
		int twist_ankle();
		int broken_arm();
		int lost_board();
};

//Snowboarding Node Class
class boardNode : public snowboard
{
	public:
		boardNode();				//Constructor
		boardNode(const string & a_name);	//Constructor name
		boardNode(const boardNode & src);	//Copy constructor
		int set_next(boardNode * next);		//Setter
		boardNode * & get_next();		//Get next node
		~boardNode();				//Destructor

	private:
		boardNode * next;			//Node class
};

//Snowboard CLL Class
class CLLboard : public snowboard
{
	public:
		CLLboard();				//Default Constructor
		CLLboard(const CLLboard & source);		//Copy Constructor
		CLLboard & operator=(const CLLboard & src);	//Assignment Op
		int insert(const boardNode & athlete);		//Add a new athlete

		boardNode * retrieve(string & name);			//Get athlete
		int copy_all(boardNode * source, boardNode * & rear);	//Copy wrapper function
		int remove(string & name);				//Remove one athlete
		int remove_all();				//Remove all athletes
		int display();					//Display user name
		int adjust_score();				//Adjust score
		int sort();					//Sorts CLL

		~CLLboard();				//Destructor

	private:
		int copy_all(boardNode * source, boardNode * s_rear, boardNode * & head);	//Recursive functions
		int display(boardNode * rear);
		boardNode * retrieve(boardNode * rear, string & name);
		int remove(boardNode * & rear, string & name);
		int remove_all(boardNode * & rear);
		int adjust_score(boardNode * rear);			

		int sort(boardNode * src, boardNode * & rear, boardNode * & rear_tail);
		int insert_sort(boardNode * src, boardNode * & rear, boardNode * & copy_rear);

		boardNode * rear;	//Rear of CLL
};

//Iceskate Class
class iceskate : public sport 
{
	public:
		iceskate();				//Default Constructor
		iceskate(const iceskate & src);		//Copy Constructor
		iceskate(const string & a_name);	//Constructor for hierarchy
		iceskate(const string & a_name, const string & a_nick);	//Constructor name
		iceskate & operator=(const iceskate & src);		//Assignment operator
		int adjust_score(const int change);			//Adjustment to score (+/-)

		int display();

		int set_nick(const string & new_nick);			//Setter
		~iceskate();						//Destructor

		//Events
		int fall();
		int slip();
		int broken_ankle();

	private:
		char * nickname;
};

//Iceskate Node Class
class iceskateNode : public iceskate
{
	public:
		iceskateNode();				//Constructor
		iceskateNode(const string & a_name, const string & nickname);	//Constructor initializing name
		iceskateNode(const iceskateNode & src);	//Copy constructor
		int set_next(iceskateNode * next);	//Setter
		iceskateNode * & get_next();		//Get next node
		~iceskateNode();			//Destructor

	private:
		iceskateNode * next;		//Node class
};

//iceskate LLL Class
class LLLiceskate
{
	public:
		LLLiceskate();						//Default Constructor
		LLLiceskate(const LLLiceskate & source);		//Copy Constructor
		LLLiceskate & operator=(const LLLiceskate & src);	//Assignment Op
		int insert(const iceskateNode & athlete);		//Add a new athlete

		iceskateNode * retrieve(string & name);	//Get an athlete
		int remove(string & name);		//Remove an athlete
		int remove_all();			//Remove all athletes
		int display();				//Display name
		int adjust_score();			//Randomly changes score

		int sort();				//Sorts LLL

		~LLLiceskate();				//Destructor

	private:
		int copy_all(iceskateNode * src);		//Copy All
		int copy_all(iceskateNode * source, iceskateNode * & head);
		iceskateNode * retrieve(iceskateNode * head, string & name);	
		int remove(iceskateNode * & head, string & name);
		int remove_all(iceskateNode * & head);
		int display(iceskateNode * head);
		int adjust_score(iceskateNode * head);

		int sort(iceskateNode * src, iceskateNode * & head);
		int insert_sort(iceskateNode * src, iceskateNode * & head);


		iceskateNode * head;					//Head of LLL
};
