// CMPT 225 Assignment 5
// Name: Janice Mardjuki
// Student Number: 301152558
//  Description: Method Definition of HashTable Class

#include "HashTable.h"
#include<string>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

// Constructor
//===========================HashTable::HashTable(void)==================
//Purpose:	Creating hash table of default size: 101
//PRE:
//PARAM:
//POST: Creates arr with size of 101
//		Constructed default currentSize of size 0
//		Constructed default maxSz of size 101
//===================================================================
HashTable::HashTable(void){
	arr = new LinkedList [101];
	maxSz = 101;
	currentSize = 0;
}


// Constructor
//===========================HashTable::HashTable(int n)==================
//Purpose:	Creating hash table to store n items
//PRE:
//PARAM:	n is the array size
//POST: Creates arr with size of approximately 2n
//		and at least equal to 2n
//		and has to be a prime number
//===================================================================
HashTable::HashTable(int n){
	bool isPrime=false;
	//If it is not a prime number, keeps incrementing by one until the n is prime
	n=n*2;
	//checking if it is a prime number
	isPrime=checkPrime(n);
	// if not add 1 and check 
	while(!isPrime){
		n++;
		isPrime=checkPrime(n);
	}
	// set as the number of array
	maxSz=n;
	// make a new array of size maxSz
	arr=new LinkedList[maxSz];
	currentSize = 0;
}

// Copy constructor
//===================HashTable::HashTable(HashTable & p)==================
// Purpose: Create a deep copy of its parameter
// PRE: HashTab;le object has been constructed
// PARAM: Tablep is the HashTable object to be copied
// POST: Creates a deep copy Tablep object
//=========================================================================
HashTable::HashTable(HashTable & Tablep){
	//passing the size of number of items in the hash table
	currentSize=Tablep.currentSize;
	// passing the size of the hash table underlying array
	maxSz=Tablep.maxSz;
	arr=new LinkedList [maxSz];
	// Make a copy of the array by signing the matching parameter with the array
	for (int i=0;i<maxSz;i++){
		arr[i]=Tablep.arr[i];
	}
}

// Destructor
//=========================HashTable::~HashTable(void)===========================
// Purpose: Frees dynamic memory associated with the node pointer
// PRE: NONE
// POST:  De-allocates dynamics memory associated with object
// PARAM: NONE
//=============================================================================
HashTable::~HashTable(void){
	delete[]arr;
	arr=NULL;
	//delete arr;
}


// Overloading assignment operator
//========HashTable &HashTable::operator = (HashTable & Tablep)===========
// Purpose: Create a deep copy of its parameter
// PRE: HashTable object has been constructed
// PARAM: Tablep is the HashTable object to be copied
// POST: De-allocates dynamics memory associated with object
//		Creates a deep copy Tablep
//		Returns a reference to the calling object
//=========================================================================
HashTable &HashTable::operator = (HashTable & Tablep){
	// Don't copy if the calling object is the same as the parameter operator
	if(&Tablep==this){
		return *this;
	}
	// de-alocating memory
	delete [] arr;
	currentSize=Tablep.currentSize;
	maxSz=Tablep.maxSz;
	arr=new LinkedList [maxSz];
	// Make a copy of the array by signing the matching parameter with the array
	for (int i=0;i<maxSz;i++){
		arr[i]=Tablep.arr[i];
	}
	return *this;
}

//Checking the size if it's prime or not
//=========================bool HashTable::checkPrime(int n)const============================
// Purpose: Checking the size if it's prime or not
// PRE: NONE
// POST:  Returns true if it is prime,false if not 
// PARAM: NONE
//==============================================================================
bool HashTable::checkPrime(int n)const{
	if(n <= 1){
		return false;
	}
	//checking if it's prime or not
	//not a prime if it is divisible 
	for(int i=2; i <=n;++i){
		// return false if it is not prime
		if(n%i==0){
			return false;
		}
		return true;
	}
} 

// Insert
//==================bool HashTable::insert(string p))====================================
//PURPOSE: Insetys the string parameter 
//PRE:		
//PARAM:	Tablep parameter to be inserted
//POST: 
//			bool returns true when the string has been inserted
//				returns false if the string is already in the list
//==============================================================================
bool HashTable::insert(string Tablep){
	int hashKey = hashing(Tablep);
	// caliing the Linkedlist insert
	bool inserted=arr[hashKey].insert(Tablep);
	if (inserted==true){
		currentSize++;
		return true;
	}
	return false;		
}


//Hash Function
//=========================int HashTable::hashing(string p)const============================
// Purpose: Generating the hash value from a string
// PRE: NONE
// POST:  Returns the assigned number (1-26) to letters a-z 
// PARAM: NONE
//==============================================================================
int HashTable::hashing(string p)const{
	int psize = p.size();
	int sum = 0;
	int ascii=0;
	int d=0;// d is the expression of -1
	//Horner's rule
	for(int i=0; i<psize;i++){
		d++;
		// Assigning the string to number
		ascii=p[i]-96;
		sum = sum+((pow(32.0,psize-d))*ascii);
		sum=sum%maxSz;
	}
	return sum;	
}

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
bool HashTable::remove(string Tablep){
	int hashKey = hashing(Tablep);
	// caliing the Linkedlist remove
	bool removed=arr[hashKey].remove(Tablep);
	if (removed==true){
		currentSize--;
		return true;
	}
	return false;
}

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
bool HashTable::search(string Tablep)const{
	int hashKey = hashing(Tablep);
	// caliing the Linkedlist search
	bool found=arr[hashKey].search(Tablep);
	if (found==true){
		return true;
	}
	return false;
}

// Size
//=========================int HashTable::size()const============================
// Purpose: Find the  current number of items in the hash table
// PRE: NONE
// POST:  Returns the  number of items stored in the hash table 
// PARAM: NONE
//==============================================================================
int HashTable::size()const{
	return currentSize;
}

// maxSize
//=========================int HashTable::maxSize()const============================
// Purpose: Find the  size of the underlying array
// PRE: NONE
// POST:  Returns the  size of the hash table’s underlying array 
// PARAM: NONE
//==============================================================================
int HashTable::maxSize()const{
	return maxSz;
}

// loadFactor
//=========================int HashTable::maxSize()const============================
// Purpose: Find the   load factor of the hash table
// PRE: NONE
// POST:  Returns the load factor of the hash table
// PARAM: NONE
//==============================================================================
double HashTable::loadFactor()const{
	// current number of items /size of the underlying array
	return currentSize/maxSz;
}


// Intersection
//========================vector<string> HashTable::intersection(const HashTable & TableH)const============================
// Purpose: returns vector object that contains the intersection of the calling object and the parameter object
// PRE: 
// POST:  Returns the intersection of the calling object and StringS
// PARAM: TableH is the string set object to be compared
//==============================================================================================================
vector<string> HashTable::intersection(const HashTable & TableH)const{
	vector <string> v; //intersection
	vector<string> v1;
	// Converting the array into vector
	for (int i=0;i<maxSz;i++){
		v1=arr[i].get();
		// Checking if the vector has the same string
		for (int m=0;m<v1.size();m++){
			// push if the vectors are same
			if (TableH.search(v1[m])==true){
				v.push_back(v1[m]);
			}
		}
	}
	// returns the intersection
	return v;
}

// Unions
//===============vector<string> HashTable::unions(const HashTable & TableH)const============================
// Purpose: returns StringSet object that contains the union of the calling object and the parameter
// PRE: 
// POST:  Returns the union of the calling object and StringS
// PARAM: TableH is the string set object to be compared
//===========================================================================================================
vector<string> HashTable::unions(const HashTable & TableH)const{
	vector <string> v;//unions
	vector<string> v1;
	vector<string> v2;
	// Pushing back all of the vector after concverting from array
	for (int i=0;i<maxSz;i++){
		v1=arr[i].get();
		for (int m=0;m<v1.size();m++){
			v.push_back(v1[m]);
		}
	}

	for (int j=0;j<TableH.maxSz;j++){
		v2=TableH.arr[j].get();
		for (int m=0;m<v2.size();m++){
			// Push back when the second array of vector is not the same as the first one
			if(search(v2[m]) ==false){
				v.push_back(v2[m]);
			}
		}
	} 
	// returns the unions
	return v;
}

// Difference
//===================vector<string> HashTable::difference(const HashTable & TableH)const============================
// Purpose: returns avector that contains the difference of the calling object and the parameter
// PRE: 
// POST:  Returns the difference of the calling object and StringS
// PARAM: TableH is the string set object to be compared
//==============================================================================================================
vector<string> HashTable::difference(const HashTable & TableH)const{
	vector <string> v;//difference
	vector<string> v1;
	// Converting the array into vector
	for (int i=0;i<maxSz;i++){
		v1=arr[i].get();
		// Checking if the vector has the same string
		for (int m=0;m<v1.size();m++){
			// push if the vectors are different
			if (TableH.search(v1[m])==false){
				v.push_back(v1[m]);
			}
		}
	}
	// returns the difference
	return v;
}

//printing out the array
//===================void HashTable::print()==================================
// Purpose: printing out the array
// PRE: 
// POST:  Returns the array
// PARAM: 
//=============================================================================
void HashTable::print(){
	for(int i=0;i<maxSz;i++){
		arr[i].print();
	}
}
