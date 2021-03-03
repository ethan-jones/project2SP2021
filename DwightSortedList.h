#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template <class ItemType>
//Linked List Node definition
struct Node {
	ItemType info;
	Node<ItemType>* next;
};
// Exception classes
class OutOfBound {
};

class DeletingMissingItem {
};

class FullList{
};  

class EmptyList{
};

class DuplicateItem{
};
// Sorted List Template
template <class ItemType>
class SortedList
{
public: 
	// Class constructor.
	SortedList();
	
	// Class destructor. 
    ~SortedList();
	
	// Function: Deallocates all list nodes, and reinitializes the list to its empty state.
	// Pre: List is initialized
	//Post: list is empty.
	void makeEmpty();
	
	// Function: Determines whether the list is empty.
	// Pre: List is initialized
	// Post: Function value = (list is empty)
    bool isEmpty() const;
	
	// Function: Determines whether the list is full.
	// Pre: List is initialized
	// Post: Function value = (list is full)       
   bool isFull() const;
   
   // Function: Adds newItem to the end of the list.
   // Pre: List is initialized
   // Post: If (List is full) FullList exception is thrown
   //       If item is already in the list DuplicateItem exception is thrown
   //       else newItem is in the list at the correct position based on key value.
   //         list maintains the sortedness property  
	void putItem(ItemType newItem);
   
	// Function: deletes Item from the list.
	// Post: If List is empty, EmptyList exception is thrown.
	// If item is not in the list, DeletingMissingItem exception is thrown.
    //   else Item is not in the list.
	void deleteItem(ItemType item);
	
	// Function: returns the number of items in the list
	// pre: List is initialized.
	//post: Function value = number of elemnts in the list.
	int getLength()const;
	
	// Function: returns the ith element of the list
	// pre: List is initialized.
	//post: if 0< i <= getLength(), Function value =  the ith list element.
	// Throws the exception OutOfBound, if i>getLenghth() or i <=0 
	ItemType getAt(int i);
	
	//Function: Merges two sorted lists in place.
	//Preconditions: List is initialized. otherList is initialized. 
	//               otherList is sorted.
	//Postconditions: Function returns the implicit list (current List)
	//after inserting all elements of otherList at their correct positions.
	//Current list is sortedand with no duplicate keys.
	//otherList is empty.
	void merge(SortedList& otherList);
	
	// Function: Prints the list to a file
	//pre: List is initialized
	//post: List is not changed
	void printList(ofstream&);

private:
    Node<ItemType>* listData;
    int Length;

	// Function: Searches the list for item and returns a pointer to item's predecessor node.
	//pre: list is initialized
	// post: (1) If item is in the list, function value =  true 
	//       (2) if item is not in the list, function value is false  
	//       (3) predecessor contains the address of item's predecessor node ( i.e. node with largest value < item's key)
	//        if no predescessor exit, predecessor is set to NULL.
	bool findItem(ItemType item, Node<ItemType>*& predecessor);
};


