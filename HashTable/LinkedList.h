//  Description: Class Definition of LinkedList Class

#pragma once
#include <string>
#include<vector>

using namespace std;

class Node
{
public:
	string data;
	Node* next;
	// Node constructor
	Node(string x, Node* nd) : data(x), next(nd) {};
	Node(string x) : data(x){};
private:
};

class LinkedList
{
public:
	// Default constructor
	//===========================LinkedList::LinkedList(void)==================
	//Purpose:	Creating default constructor
	//PRE:
	//PARAM:
	//POST: Creates node head which pointing to NULL
	//			Constructed default deque of size 0
	//===================================================================
	LinkedList(void);

	// Copy constructor
	//===================LinkedList::LinkedList(const LinkedList & ListP==================
	// Purpose: Create a deep copy of its parameter
	// PRE: LinkedList object has been constructed
	// PARAM: ListP is the Deque object to be copied
	// POST: Creates a deep copy ListP object
	//=========================================================================
	LinkedList(const LinkedList &);

	// Overloading operator
	//========LinkedList &LinkedList::operator = (const LinkedList &ListP)===========
	// Purpose: Create a deep copy of its parameter
	// PRE: LinkedList object has been constructed
	// PARAM: ListP is the Deque object to be copied
	// POST: De-allocates dynamics memory associated with object
	//		Creates a deep copy ListP deque
	//		Returns a reference to the calling object
	//=========================================================================
	LinkedList &operator = (const LinkedList &);

	// Destructor
	//=========================LinkedList::~LinkedList(void)===========================
	// Purpose: Frees dynamic memory associated with the node pointer
	// PRE: NONE
	// POST:  De-allocates dynamics memory associated with object
	// PARAM: NONE
	//=============================================================================
	~LinkedList(void);

	// Insert
	//==================bool LinkedList::insert(string ListP)====================================
	//PURPOSE: Insetys the string parameter 
	//PRE:		
	//PARAM:	ListP parameter to be inserted
	//POST: 
	//			bool returns true when the string has been inserted
	//				returns false if the string is already in the list
	//==============================================================================
	bool insert(string);

	// Remove
	//==================bool LinkedList::remove(string ListP)====================================
	//PURPOSE: Removes the string parameter 
	//PRE:		The size cannot be zero
	//			The size can be one 
	//PARAM:	ListP parameter to be removed
	//POST: 
	//			bool returns true when the string has been removed
	//				returns false if the string is not in the list
	//==============================================================================
	bool remove(string);

	// Search
	//==================bool LinkedList::search (string ListP)const====================================
	//PURPOSE: Searches the string parameter 
	//PRE:		The size cannot be zero
	//			The size can be one 
	//PARAM:	ListP parameter to be searched
	//POST: 
	//			bool  returns true if its single string parameter is contained in the list,
	//				returns false otherwise
	//==============================================================================
	bool search (string)const;

	// Get to returns a vector of content
	//==================vector<string> LinkedList::get()====================================
	//PURPOSE: Get to returns a vector of content
	//PRE:		The size cannot be zero
	//			The size can be one 
	//PARAM:	
	//POST: 
	//			vector<string> returns vector inside the list
	//==============================================================================
	vector<string> get() const;

	//===================void LinkedList::print()==================================
	// Purpose: printing out the data iside
	// PRE: 
	// POST:  Returns the data
	// PARAM: 
	//=============================================================================
	void print();

	//===================int LinkedList::sz()==================================
	// Purpose: Size of the data
	// PRE: 
	// POST:  Returns the size
	// PARAM: 
	//=============================================================================
	int sz();
private:
	Node* head;
	int size;

	//search helper function
	//==================bool LinkedList::search (string ListP)const====================================
	//PURPOSE: Search function helper 
	//PRE:		The size cannot be zero
	//			The size can be one 
	//PARAM:	ListP parameter to be searched
	//			temp parameter node, which is head
	//POST: 
	//			bool  returns true if its single string parameter is contained in the list,
	//				returns false otherwise
	//==============================================================================
	bool searchHelper(string ListP, Node* temp) const;

};
