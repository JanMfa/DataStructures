//  Description: Method Definition of LinkedList Class

#include "LinkedList.h"
# include<vector>
#include<iostream>

// Default constructor
//===========================LinkedList::LinkedList(void)==================
//Purpose:	Creating default constructor
//PRE:
//PARAM:
//POST: Creates node head which pointing to NULL
//			Constructed default deque of size 0
//===================================================================
LinkedList::LinkedList(void){
	head=NULL;
	size=0;
}

// Copy constructor
//===================LinkedList::LinkedList(const LinkedList & ListP==================
// Purpose: Create a deep copy of its parameter
// PRE: LinkedList object has been constructed
// PARAM: ListP is the Deque object to be copied
// POST: Creates a deep copy ListP object
//=========================================================================
LinkedList::LinkedList(const LinkedList & ListP){
	head = NULL;
	size =ListP.size;
	// Only make a copy if st is non-empty
	if(ListP.head != NULL){
		// Make a copy of the parameter
		Node* original = ListP.head;
		Node* copy;
		// First copy the top
		copy = new Node(original->data, NULL);
		head = copy;
		original = original->next;

		// Now copy the rest of the stack
		while(original != NULL){
			copy->next = new Node(original->data, NULL);
			copy = copy->next;
			original = original->next;
		}
	}
}

// Destructor
//=========================LinkedList::~LinkedList(void)===========================
// Purpose: Frees dynamic memory associated with the node pointer
// PRE: NONE
// POST:  De-allocates dynamics memory associated with object
// PARAM: NONE
//=============================================================================
LinkedList::~LinkedList(void){
	//cout<<"LinkedList destructor:" <<endl;
	Node* temp = head;
	// While the element is not empty, delete the elements and the next element
	while(temp!=NULL){
		temp = head->next;
		delete head;
		head=temp;
	}
	head= NULL;
}


// Overloading operator
//========LinkedList &LinkedList::operator = (const LinkedList &ListP)===========
// Purpose: Create a deep copy of its parameter
// PRE: LinkedList object has been constructed
// PARAM: ListP is the Deque object to be copied
// POST: De-allocates dynamics memory associated with object
//		Creates a deep copy ListP deque
//		Returns a reference to the calling object
//=========================================================================
LinkedList &LinkedList::operator = (const LinkedList &ListP){
	// Don't copy if the calling object is the same as the parameter operator
	if(&ListP!=this){
		Node* temp = head;
		// While the element is not empty, delete the elements and the next element
		while(temp != NULL){
			temp = head->next;
			delete head;
			head = temp;
		}
		head = NULL;
		size =ListP.size;
		// Only make a copy if st is non-empty
		if(ListP.head != NULL){
			// Make a copy of the parameter
			Node* original = ListP.head;
			Node* copy;
			// First copy the top
			copy = new Node(original->data, NULL);
			head = copy;
			original = original->next;

			// Now copy the rest of the stack
			while(original != NULL){
				copy->next = new Node(original->data, NULL);
				copy = copy->next;
				original = original->next;
			}
		}
	}
	return *this;
}
// Insert
//==================bool LinkedList::insert(string ListP)====================================
//PURPOSE: Insetys the string parameter 
//PRE:		
//PARAM:	ListP parameter to be inserted
//POST: 
//			bool returns true when the string has been inserted
//				returns false if the string is already in the list
//==============================================================================
bool LinkedList::insert(string ListP){
	// allowing for no duplication
	if(search(ListP)==true){
		return false;
	}
	//Creates a new node pointing to the NULL
	Node* temp = new Node(ListP, NULL);
	Node*temp1;
	// When the Deque is empty, insert right away
	if (head == NULL){
		head = temp;
		head->next=NULL;
		// If there is an element on the back, insert the new element to the next element 
		//of the deque and set it to the back
	}else{
		temp->next=head;
		head=temp;
	}
	size++;
	return true;
}

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
bool LinkedList::remove(string ListP){
	// not in the list
	if (search(ListP)==false){
		return false;
	}
	Node*temp,*temp1;
	temp=head;
	// when there is string in the list
	while(temp!=NULL){
		// check the data in the head
		if(temp->data==ListP){
			// delete if it is
			if(temp==head){
				head=temp->next;
				delete temp;
				size--;
				return true;
				// if not then store the node on temp1
			}else{
				temp1->next=temp->next;
				delete temp;
				size--;
				return true;
			}
			// if head does not contain the parameter to be removed
			// go to next
		}else{
			temp1=temp;
			temp=temp->next;
		}
	}
	size--;
	return true;
}

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
bool LinkedList::search (string ListP)const{
	bool exist=searchHelper(ListP,head);
	return exist;
}

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
bool LinkedList::searchHelper(string ListP, Node* temp) const{
	// return false if it is empty
	if(temp==NULL){
		return false;
		// has been found
	}else if (temp->data==ListP){
		return true;
		// recursively call
		//go to another node 
	}else{
		return searchHelper(ListP,temp->next);
	}
	return true;
}

// Get to returns a vector of content
//==================vector<string> LinkedList::get()====================================
//PURPOSE: Get to returns a vector of content
//PRE:		The size cannot be zero
//			The size can be one 
//PARAM:	
//POST: 
//			vector<string> returns vector inside the list
//==============================================================================
vector<string> LinkedList::get()const{
	vector <string> v;
	// set the node in the head
	Node *temp=head;
	while(temp!=NULL){
		// push the data
		v.push_back(temp->data);
		// set the next pointer 
		temp=temp->next;
	}
	return v; // return vector of content
}

//===================void LinkedList::print()==================================
// Purpose: printing out the data iside
// PRE: 
// POST:  Returns the data
// PARAM: 
//=============================================================================
void LinkedList::print(){
	Node*temp = head;
	while (temp!=NULL){
		cout<< temp->data<<endl;
		temp = temp->next;
	}
}

//===================int LinkedList::sz()==================================
// Purpose: Size of the data
// PRE: 
// POST:  Returns the size
// PARAM: 
//=============================================================================
int LinkedList::sz(){
	return size;
}
