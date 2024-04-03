#include "snowsport.h"

//Angeline Vu, 2/2/2024, CS302-001, Program 1
//This program has snwoboard node and CLL snowboard athlete
//class definitions.

//Snowboard Node Class
//Constructor
boardNode::boardNode() : next(nullptr) {}

//Constructor with name
boardNode::boardNode(const string & name) : snowboard(name), next(nullptr) {}

//Copy Constructor
boardNode::boardNode(const boardNode & src) : snowboard(src), next(nullptr) {}

//Sets next pointer
int boardNode::set_next(boardNode * new_next)
{
	if (!new_next)
		return 0;

	next = new_next;
	return 1;
}

//Gets the next pointer
boardNode * & boardNode::get_next()
{
	return next;
}

//Destructor
boardNode::~boardNode() 
{
	next = nullptr;
}

//Snowboard CLL
//Constructor
CLLboard::CLLboard() : rear(nullptr) {}

//Copy constructor
CLLboard::CLLboard(const CLLboard & source)
{
	if (!source.rear)
		return;
	copy_all(source.rear, rear);
}

//Assignment overload
CLLboard & CLLboard::operator=(const CLLboard & src)
{
	if (this == &src)
		return *this;

	remove_all();

	copy_all(src.rear, rear);	
	return *this;
}

//Copy entire CLL
int CLLboard::copy_all(boardNode * source, boardNode * & rear)
{
	//Empty
	if (!source)
	{
		rear = nullptr;
		return 0;
	}

	rear = new boardNode(*source);

	//1 item
	if (source == source->get_next())
	{
		rear->set_next(rear);	
		return true;
	}	

	return copy_all(source->get_next(), source, rear->get_next());
}

//Recursive copy function
int CLLboard::copy_all(boardNode * source, boardNode * s_rear, boardNode * & rear)
{
	if (source == s_rear)
	{
		rear = this->rear;
		return 1;
	}

	rear = new boardNode(*source);
	return copy_all(source->get_next(), s_rear, rear->get_next());
}

//Add a new athlete
int CLLboard::insert(const boardNode & athlete)
{
	if (!rear)
	{
		rear = new boardNode(athlete);
		rear->set_next(rear);	
		return 1;
	}

	boardNode * hold = rear->get_next();
	rear->get_next() = new boardNode(athlete);
	rear->get_next()->set_next(hold);

	return 1;
}

//Gets pointer to an athlete
boardNode * CLLboard::retrieve(string & name)
{
	if (!rear)	
		return nullptr;
	if (rear->compare_name(name))
		return rear;
	return retrieve(rear->get_next(), name);
}

//Recursive function
boardNode * CLLboard::retrieve(boardNode * rear, string & name)
{
	if (rear == this->rear)
		return nullptr;

	if (rear->compare_name(name))
		return rear;

	return retrieve(rear->get_next(), name);
}

//Remove one athlete
int CLLboard::remove(string & name)
{
	//Empty
	if (!rear)
		return 0;

	//One node match
	if (rear->compare_name(name) && rear->get_next() == rear)
	{
		delete rear;
		rear = nullptr;
		return 1;
	}

	return remove(rear->get_next(), name);
}

//Recursive function
int CLLboard::remove(boardNode * & rear, string & name)
{
	//Match
	if (rear->compare_name(name))
	{
		boardNode * hold = rear->get_next();
		delete rear;
		rear = hold;
		return 1;
	}

	//Real rear match
	if (rear->get_next() == this->rear && rear->get_next()->compare_name(name))
	{
		boardNode * front = this->rear->get_next();
		this->rear = rear;
		delete rear->get_next();
		rear->set_next(front);
		return 1;	
	}

	//No match
	if (rear == this->rear)
		return 0;

	return remove(rear->get_next(), name);
}

//Remove all athletes
int CLLboard::remove_all()
{
	if (!rear)
		return 1;
	return remove_all(rear->get_next());
}

//Recursive function
int CLLboard::remove_all(boardNode * & rear)
{
	if (rear == this->rear)
	{
		delete rear;
		this->rear = nullptr;
		return 1;
	}

	boardNode * hold = rear->get_next();
	delete rear;
	rear = hold;
	return remove_all(rear);
}

//Displays all athletes
int CLLboard::display()
{
	if (!rear)
		return 0;
	return display(rear->get_next());
}

//Recursive function display
int CLLboard::display(boardNode * rear)
{
	rear->display();
	cout << endl;

	//One node
	if (rear == rear->get_next())
		return 1;

	//End of list
	if (rear == this->rear)
		return 1;

	return display(rear->get_next());
}

//Adjust score
int CLLboard::adjust_score()
{
	if (!rear)
		return 0;
	return adjust_score(rear->get_next());
}

//Recursive function
int CLLboard::adjust_score(boardNode * rear)
{
	rear->snowboard::adjust_score(rand());
	if (rear == this->rear)
		return 1;
	return adjust_score(rear->get_next());
}

//Sorting function
int CLLboard::sort()
{
	//Empty
	if (!rear)
		return 0;

	//1 Item
	if (rear == rear->get_next())
		return 1;

	CLLboard copy;

	//LOST
	copy.rear = new boardNode(*rear);

	//sort(rear->get_next(), copy.rear->get_next(), nullptr);
	//sort(rear->get_next(), copy.rear, copy.rear);
	boardNode * tail = copy.rear;
	sort(rear->get_next(), copy.rear, tail);
	

	*this = copy;
	return 1;
}

//Sorting recursive function (LLL -> CLL)
int CLLboard::sort(boardNode * rear, boardNode * & head, boardNode * & tail)
{
	//Copied all nodes
	if (rear == this->rear)
	{
		if (tail)
			tail->set_next(head);	
		return 1;
	}

	insert_sort(rear, head, tail);
	return sort(rear->get_next(), head, tail);
}

//Helper recursive function
int CLLboard::insert_sort(boardNode * rear, boardNode * & head, boardNode * & tail)
{
	//FIX FIRST NODE: LOST WHEN HEAD IS NULL?
	if (!head)
	{
		head = new boardNode(*rear);
		tail = head;
		return 1;
	}

	//Not new rear (!smallest item)
	if (rear->greater_score(*head))
	{
		boardNode * hold = head;
		head = new boardNode(*rear);
		head->set_next(hold);
		return 1;	
	}

	return insert_sort(rear, head->get_next(), tail);
}

//Destructor
CLLboard::~CLLboard()
{
	remove_all();
}
