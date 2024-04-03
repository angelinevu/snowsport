#include "snowsport.h"

//Angeline Vu, 2/2/2024, CS163-001, Program 1
//This file includes the main function as well as 
//function definitions to manage the UI

//Main
int main()
{
	//Seed random number generator
	srand(time(nullptr));

	//Menu
	int selection = 0;
	selection = menu();

	//Snowboarding
	if (selection == 1)
	{
		//Initialize contestants
		CLLboard athletes;
		initialize_snowboard(athletes);	
		cout << "\nContestants\n\n";
		athletes.display();
		pause();

		for (int i = 0; i < EVENTS; ++i)
		{
			cout << "\n\nUpdate!\n\n";
			athletes.adjust_score();
			cout << endl;
			pause();
		}
		cout << "_______________________________________\n";
		cout << "\nRace Leaderboard\n\n";
		athletes.sort();
		athletes.display();
		cout << "_______________________________________\n\n";
	}

	//Skiing
	else if (selection == 2)
	{
		//Initialize contestants
		LLLski athletes;
		initialize_ski(athletes);	
		cout << "\nContestants\n\n";
		athletes.display();
		pause();

		for (int i = 0; i < EVENTS; ++i)
		{
			cout << "\n\nUpdate!\n\n";
			athletes.adjust_score();
			cout << endl;
			pause();
		}
		cout << "_______________________________________\n";
		cout << "\nRace Leaderboard\n\n";
		athletes.sort();
		athletes.display();
		cout << "_______________________________________\n\n";
	}

	//Iceskating
	else if (selection == 3)
	{
		//Initialize contestants
		LLLiceskate athletes;
		initialize_iceskate(athletes);	
		cout << "\nContestants\n\n";
		athletes.display();
		pause();
		for (int i = 0; i < EVENTS; ++i)
		{
			cout << "\n\nUpdate!\n\n";
			athletes.adjust_score();
			cout << endl;
			pause();
		}
		athletes.sort();
		cout << "_______________________________________\n";
		cout << "\nRace Leaderboard\n\n";
		athletes.display();
		cout << "_______________________________________\n\n";
	}

	return 0;
}

//Displays a menu & user chooses snowsport
int menu()
{
	int selection = 0;
	cout << "\n   *   *   *   *   *   *   *   *   *\n*   *   * Snow Race Simulator *   *   *\n   *   *   *   *   *   *   *   *   *";
	cout <<"\n\nSelect a sport:\n\t1. Snowboarding\n\t2. Skiing\n\t3. Iceskating\n";
	do
	{
		cout << "\nSelection: ";
		cin >> selection;
		cin.ignore(100, '\n');
		if (selection < 1 || selection > 3)
			cout << "Invalid Input.\n";
	} while (selection < 1 || selection > 3);


	if (selection == 1)
	{
		cout << "\n   *   *   *   *   *   *   *   *   *\n" << "*   *   *  Snowboarding Race  *   *   *" << "\n   *   *   *   *   *   *   *   *   *\n";
		cout << "_______________________________________\n";
	}

	if (selection == 2)
	{
		cout << "\n   *   *   *   *   *   *   *   *   *\n" << "*   *   *   * Skiing Race *   *   *   *" << "\n   *   *   *   *   *   *   *   *   *\n";
		cout << "_______________________________________\n";
	}

	if (selection == 3)
	{
		cout << "\n   *   *   *   *   *   *   *   *   *\n" << "*   *   *   Iceskating Race   *   *   *" << "\n   *   *   *   *   *   *   *   *   *\n";
		cout << "_______________________________________\n";
	}

	return selection;
}

//Pauses interface
void pause()
{
	cout << "\nPress ENTER to proceed. ";
	cin.ignore(100, '\n');
	cin.clear();
}
