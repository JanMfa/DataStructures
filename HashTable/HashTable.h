// CMPT 225 Assignment 5
// Name: Janice Mardjuki
// Student Number: 301152558
//  Description: Class Definition of HashTable Class

#pragma once
#include "LinkedList.h"
#include<vector>
#include<string>

using namespace std;

class HashTable
{
public:
	// Default Constructor
	//===========================HashTable::HashTable(void)==================
	//Purpose:	Creating hash table of default size: 101
	//PRE:
	//PARAM:
	//POST: Creates arr with size of 101
	//		Constructed default currentSize of size 0
	//		Constructed default maxSz of size 101
	//===================================================================
	HashTable(void);

	// Constructor
	//===========================HashTable::HashTable(int n)==================
	//Purpose:	Creating hash table to store n items
	//PRE:
	//PARAM:	n is the array size
	//POST: Creates arr with size of approximately 2n
	//		and at least equal to 2n
	//		and has to be a prime number
	//===================================================================
	HashTable(int n);

	// Copy constructor
	//===================HashTable::HashTable(HashTable & p)==================
	// Purpose: Create a deep copy of its parameter
	// PRE: HashTab;le object has been constructed
	// PARAM: Tablep is the HashTable object to be copied
	// POST: Creates a deep copy Tablep object
	//=========================================================================
	HashTable(HashTable &);

	// Destructor
	//=========================HashTable::~HashTable(void)===========================
	// Purpose: Frees dynamic memory associated with the node pointer
	// PRE: NONE
	// POST:  De-allocates dynamics memory associated with object
	// PARAM: NONE
	//=============================================================================
	~HashTable(void);

	// Overloading assignment operator
	//========HashTable &HashTable::operator = (HashTable & Tablep)===========
	// Purpose: Create a deep copy of its parameter
	// PRE: HashTable object has been constructed
	// PARAM: Tablep is the HashTable object to be copied
	// POST: De-allocates dynamics memory associated with object
	//		Creates a deep copy Tablep
	//		Returns a reference to the calling object
	//=========================================================================
	HashTable &operator = (HashTable &);

	// Insert
	//==================bool HashTable::insert(string p))====================================
	//PURPOSE: Insetys the string parameter 
	//PRE:		
	//PARAM:	Tablep parameter to be inserted
	//POST: 
	//			bool returns true when the string has been inserted
	//				returns false if the string is already in the list
	//==============================================================================
	bool insert(string);

	// Remove
	//==================bool HashTable::remove(string Tablep)====================================
	//PURPOSE: Removes the string parameter 
	//PRE:		The size cannot be zero
	//			The size can be one 
	//PARAM:	Tablep parameter to be removed
	//POST: 
	//			bool returns true when the string has been removed
	//				returns false if the string is not in the list
	//==============================================================================
	bool remove(string);

	// Search
	//==================bool HashTable::search(string Tablep)const====================================
	//PURPOSE: Searches the string parameter 
	//PRE:		The size cannot be zero
	//			The size can be one 
	//PARAM:	Tablep parameter to be searched
	//POST: 
	//			bool  returns true if its single string parameter is contained in the list,
	//				returns false otherwise
	//==============================================================================
	bool search(string)const;

	// Size
	//=========================int HashTable::size()const============================
	// Purpose: Find the  current number of items in the hash table
	// PRE: NONE
	// POST:  Returns the  number of items stored in the hash table 
	// PARAM: NONE
	//==============================================================================
	int size()const;

	// maxSize
	//=========================int HashTable::maxSize()const============================
	// Purpose: Find the  size of the underlying array
	// PRE: NONE
	// POST:  Returns the  size of the hash table’s underlying array 
	// PARAM: NONE
	//==============================================================================
	int maxSize()const;

	// loadFactor
	//=========================int HashTable::maxSize()const============================
	// Purpose: Find the   load factor of the hash table
	// PRE: NONE
	// POST:  Returns the load factor of the hash table
	// PARAM: NONE
	//==============================================================================
	double loadFactor()const;

	// Intersection
	//========================vector<string> HashTable::intersection(const HashTable & TableH)const============================
	// Purpose: returns vector object that contains the intersection of the calling object and the parameter object
	// PRE: 
	// POST:  Returns the intersection of the calling object and StringS
	// PARAM: stringS is the string set object to be compared
	//==============================================================================================================
	vector<string> intersection(const HashTable &)const;

	// Unions
	//===============vector<string> HashTable::unions(const HashTable & TableH)const============================
	// Purpose: returns StringSet object that contains the union of the calling object and the parameter
	// PRE: 
	// POST:  Returns the union of the calling object and StringS
	// PARAM: stringS is the string set object to be compared
	//===========================================================================================================
	vector<string> unions(const HashTable &)const;

	// Difference
	//===================vector<string> HashTable::difference(const HashTable & TableH)const============================
	// Purpose: returns avector that contains the difference of the calling object and the parameter
	// PRE: 
	// POST:  Returns the difference of the calling object and StringS
	// PARAM: stringS is the string set object to be compared
	//==============================================================================================================
	vector<string> difference(const HashTable &)const;

	//printing out the array
	//===================void HashTable::print()==================================
	// Purpose: printing out the array
	// PRE: 
	// POST:  Returns the array
	// PARAM: 
	//=============================================================================
	void print();

private:
	// A pointer to a string in an array of string
	LinkedList *arr;

	// Current number of strings storred in an array of string
	int currentSize;

	// Records the maximum size of the aray
	int maxSz;

	// private boolean method
	//=========================bool HashTable::checkPrime(int n)const============================
	// Purpose: Checking the size if it's prime or not
	// PRE: NONE
	// POST:  Returns true if it is prime,false if not 
	// PARAM: NONE
	//==============================================================================
	bool checkPrime(int n)const;

	// Hashing helper function
	//=========================int HashTable::hashing(string p)const============================
	// Purpose: Generating the hash value from a string
	// PRE: NONE
	// POST:  Returns the assigned number (1-26) to letters a-z 
	// PARAM: NONE
	//==============================================================================
	int hashing(string p)const;

};

