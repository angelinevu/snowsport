#include "snowsport.h"

//Angeline Vu, 2/2/2024, CS302-001, Program 1
//This program has LLL class and node definitions.
//Skiiers and iceskaters

//SkiNode functions
//Default constructor
skiNode::skiNode() : next(nullptr) {};

//Constructor setting name
skiNode::skiNode(const string & name) : ski(name), next(nullptr) {}

//Copy Constructor
skiNode::skiNode(const skiNode & src) : ski(src), next(nullptr) {}

//Set next pointer
int skiNode::set_next(skiNode * new_next)
{
	next = new_next;
	return 1;
}

//Get next pointer
skiNode * & skiNode::get_next()
{
	return next;
}

//Destructor
skiNode::~skiNode()
{
	next = nullptr;
}

//Ski LLL
//Constructor
LLLski::LLLski() : head(nullptr) {}

//Copy constructor
LLLski::LLLski(const LLLski & source)
{
	copy_all(source.head);
}

//Assignment overload
LLLski & LLLski::operator=(const LLLski & src)
{
	if (this == &src)
		return *this;

	remove_all();
	copy_all(src.head);

	return *this;
}

//Copy all function
int LLLski::copy_all(skiNode * src)
{
	if (!src)
		return 0;

	return copy_all(src, head);
}

//Recursive function
int LLLski::copy_all(skiNode * source, skiNode * & head)
{
	if (!source)
	{
		head = nullptr;
		return 1;
	}

	head = new skiNode(*source);
	return copy_all(source->get_next(), head->get_next());
}

//Add a new athlete
int LLLski::insert(const skiNode & athlete)
{
	skiNode * hold = head;
	head = new skiNode(athlete);
	head->set_next(hold);	
	return 1;
}

//Get pointer to athlete match
skiNode * LLLski::retrieve(string & name)
{
	if (!head)
		return 0;
	return retrieve(head, name);
}

//Recursive function
skiNode * LLLski::retrieve(skiNode * head, string & name)
{
	if (!head)
		return nullptr;

	if (head->compare_name(name))
		return head;

	return retrieve(head->get_next(), name);
}

//Remove a specific athlete
int LLLski::remove(string & name)
{
	//Empty
	if (!head)
		return 0;

	//First node
	if (head->compare_name(name))
	{
		skiNode * hold = head->get_next();
		delete head;
		head = hold;
		return 1;
	}

	return remove(head->get_next(), name);
}

//Recursive function
int LLLski::remove(skiNode * & head, string & name)
{
	if (!head)
		return 0;

	if (head->compare_name(name))
	{
		skiNode * hold = head->get_next();
		delete head;
		head = hold;
		return 1;
	}

	return remove(head->get_next(), name);
}

//Remove all athletes
int LLLski::remove_all()
{
	if (!head)
		return 0;

	return remove_all(head);
}

//Recursive function
int LLLski::remove_all(skiNode * & head)
{
	if (!head)
		return 1;

	skiNode * hold = head->get_next();
	delete head;
	head = hold;
	return remove_all(head);
}

//Display all function
int LLLski::display()
{
	if (!head)
		return 0;

	return display(head);
}

//Recursive function
int LLLski::display(skiNode * head)
{
	if (!head)
		return 0;

	head->display();
	cout << endl;

	return display(head->get_next());
}

//Adjust score
int LLLski::adjust_score()
{
	if (!head)
		return 0;
	return adjust_score(head);
}

//Recursive function
int LLLski::adjust_score(skiNode * head)
{
	if (!head)
		return 1;
	head->ski::adjust_score(rand());
	return adjust_score(head->get_next());
}

//Sorting function
int LLLski::sort()
{
	if (!head)
		return 0;
	LLLski copy;
	sort(head, copy.head);
	*this = copy;
	return 1;
}

//Sorting recursive function
int LLLski::sort(skiNode * src, skiNode * & head)
{
	if (!src)
		return 1;

	insert_sort(src, head);
	return sort(src->get_next(), head);
}

//Helper recursive function
int LLLski::insert_sort(skiNode * src, skiNode * & head)
{
	if (!head)
	{
		head = new skiNode(*src);
		return 0;
	}
	
	if (src->greater_score(*head))
	{
		skiNode * hold = head;
		head = new skiNode(*src);
		head->set_next(hold);
		return 0;	
	}

	return insert_sort(src, head->get_next());
}

//Destructor
LLLski::~LLLski()
{
	remove_all();
}


//IceskateNode functions
//Default constructor
iceskateNode::iceskateNode() : next(nullptr) {};

//Constructor setting name
iceskateNode::iceskateNode(const string & name, const string & nickname) : iceskate(name, nickname), next(nullptr) {}

//Copy Constructor
iceskateNode::iceskateNode(const iceskateNode & src) : iceskate(src), next(nullptr) {}

//Set next pointer
int iceskateNode::set_next(iceskateNode * new_next)
{
	next = new_next;
	return 1;
}

//Get next pointer
iceskateNode * & iceskateNode::get_next()
{
	return next;
}

//Destructor
iceskateNode::~iceskateNode()
{
	next = nullptr;
}

//Iceskate LLL
//Constructor
LLLiceskate::LLLiceskate() : head(nullptr) {}

//Copy constructor
LLLiceskate::LLLiceskate(const LLLiceskate & source)
{
	copy_all(source.head);
}

//Assignment overload
LLLiceskate & LLLiceskate::operator=(const LLLiceskate & src)
{
	if (this == &src)
		return *this;

	remove_all();
	copy_all(src.head);

	return *this;
}

//Copy all function
int LLLiceskate::copy_all(iceskateNode * src)
{
	if (!src)
		return 0;

	return copy_all(src, head);
}

//Recursive function
int LLLiceskate::copy_all(iceskateNode * source, iceskateNode * & head)
{
	if (!source)
	{
		head = nullptr;
		return 1;
	}

	head = new iceskateNode(*source);
	return copy_all(source->get_next(), head->get_next());
}

//Add a new athlete
int LLLiceskate::insert(const iceskateNode & athlete)
{
	iceskateNode * hold = head;
	head = new iceskateNode(athlete);
	head->set_next(hold);	
	return 1;
}

//Get pointer to athlete match
iceskateNode * LLLiceskate::retrieve(string & name)
{
	if (!head)
		return 0;
	return retrieve(head, name);
}

//Recursive function
iceskateNode * LLLiceskate::retrieve(iceskateNode * head, string & name)
{
	if (!head)
		return nullptr;

	if (head->compare_name(name))
		return head;

	return retrieve(head->get_next(), name);
}

//Remove a specific athlete
int LLLiceskate::remove(string & name)
{
	//Empty
	if (!head)
		return 0;

	//First node
	if (head->compare_name(name))
	{
		iceskateNode * hold = head->get_next();
		delete head;
		head = hold;
		return 1;
	}

	return remove(head->get_next(), name);
}

//Recursive function
int LLLiceskate::remove(iceskateNode * & head, string & name)
{
	if (!head)
		return 0;

	if (head->compare_name(name))
	{
		iceskateNode * hold = head->get_next();
		delete head;
		head = hold;
		return 1;
	}

	return remove(head->get_next(), name);
}

//Remove all athletes
int LLLiceskate::remove_all()
{
	if (!head)
		return 0;

	return remove_all(head);
}

//Recursive function
int LLLiceskate::remove_all(iceskateNode * & head)
{
	if (!head)
		return 1;

	iceskateNode * hold = head->get_next();
	delete head;
	head = hold;
	return remove_all(head);
}

//Display all function
int LLLiceskate::display()
{
	if (!head)
		return 0;

	return display(head);
}

//Recursive function
int LLLiceskate::display(iceskateNode * head)
{
	if (!head)
		return 0;

	head->display();
	cout << endl;

	return display(head->get_next());
}

//Adjust score
int LLLiceskate::adjust_score()
{
	if (!head)
		return 0;
	return adjust_score(head);
}

//Recursive function
int LLLiceskate::adjust_score(iceskateNode * head)
{
	if (!head)
		return 1;
	head->iceskate::adjust_score(rand());
	return adjust_score(head->get_next());
}

//Sorting function
int LLLiceskate::sort()
{
	if (!head)
		return 0;
	LLLiceskate copy;
	sort(head, copy.head);
	*this = copy;
	return 1;
}

//Sorting recursive function
int LLLiceskate::sort(iceskateNode * src, iceskateNode * & head)
{
	if (!src)
		return 1;

	insert_sort(src, head);
	return sort(src->get_next(), head);
}

//Helper recursive function
int LLLiceskate::insert_sort(iceskateNode * src, iceskateNode * & head)
{
	if (!head)
	{
		head = new iceskateNode(*src);
		return 0;
	}
	
	if (src->greater_score(*head))
	{
		iceskateNode * hold = head;
		head = new iceskateNode(*src);
		head->set_next(hold);
		return 0;	
	}

	return insert_sort(src, head->get_next());
}

//Destructor
LLLiceskate::~LLLiceskate()
{
	remove_all();
}
