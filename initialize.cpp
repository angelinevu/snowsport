#include "snowsport.h"

//Angeline Vu, 2/2/2024, CS302-001, Program 1
//This program has function definitions to initialize
//the race structures

//Initialize members for ski LLL
void initialize_ski(LLLski & athletes)
{
	for (auto i = alphabet.begin(); i < alphabet.end(); ++i)
	{
		skiNode * hold = new skiNode(*i);	
		athletes.insert(*hold);
		delete hold;
	}
}

//Initialize members for snowboard CLL
void initialize_snowboard(class CLLboard & athletes)
{
	for (auto i = alphabet.begin(); i < alphabet.end(); ++i)
	{
		boardNode * hold = new boardNode(*i);	
		athletes.insert(*hold);
		delete hold;
	}
}

//Initialize members for iceskate LLL
void initialize_iceskate(class LLLiceskate & athletes)
{
	for (int i = 0; i < alphabet.size(); ++i)
	{
		iceskateNode * hold = new iceskateNode(alphabet[i], nickname[i]);	
		athletes.insert(*hold);
		delete hold;
	}
}
