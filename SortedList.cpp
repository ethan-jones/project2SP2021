#include <iostream>
using namespace std;
#include "SortedList.h"

template < class ItemType > SortedList < ItemType >::SortedList() 
{
  Length = 0;
  listData = NULL;
}

template < class ItemType > SortedList < ItemType >::~SortedList()
{
  Node<ItemType>* tempPtr;

  while(listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}

template < class ItemType > void SortedList < ItemType >::makeEmpty() 
{
  Node<ItemType>* tempPtr;
  
  while(listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  
  Length = 0;
}

template < class ItemType > bool SortedList < ItemType >::isEmpty() const
{
  if (Length == 0) {
    return true; 
  } else {
    return false; 
  }
}

template < class ItemType > bool SortedList < ItemType >::isFull() const
{
  Node<ItemType>* location;
  
  try {
    location = new Node<ItemType>;
    delete location;
    return false;
  }
  catch(bad_alloc exception) {
     return true;
  }
}

template < class ItemType > void SortedList < ItemType >::putItem(ItemType item)
{
  if (isFull() == true) {
    throw FullList(); 
  }
  Node<ItemType>* predecessor;
  if (findItem(item, predecessor) == true) {
    throw DuplicateItem(); 
  }                         
  Node<ItemType>* location;
  location = new Node<ItemType>;
  predecessor = listData;
  Node<ItemType>* node = listData;
  bool found = false;
    while (found == false) {
    	if (Length == 0) {
		location->info=item;
     		location->next=listData;
      		listData = location;
      		Length++;
		found = true;
	} else if (listData->info > item) {
		location->info = item;
		location->next = listData;
		listData = location;
		found = true;
		Length++;
	} else if (node->info > item) {
		location->info = item;
		location->next = node;
		predecessor->next = location;
		found = true;
		Length++;
	} else if (node->next == NULL) {
		location->info = item;
		location->next = NULL;
		node->next = location;
		Length++;
		found = true;
	} else {
		predecessor = node;
		node = node->next;
	}
    }
}

template < class ItemType > void SortedList < ItemType >::deleteItem(ItemType item)
{
  if (isEmpty() == true) {
    throw EmptyList(); 
  } else {
    Node<ItemType>* predecessor;
    if (findItem(item, predecessor) == false) {
      throw DeletingMissingItem(); 
    }
    Node<ItemType>* location=listData;
    Node<ItemType>* tempLocation;
    if(item==(location->info))
    {
        tempLocation=location;
        listData=listData->next;
    }
    else{
        while(item!=location->next->info)
        {
            location=location->next;
        }
        
        tempLocation=location->next;
        location->next=location->next->next;

    }
    delete tempLocation;
    Length--;
  } 
}

template < class ItemType > int SortedList < ItemType >::getLength() const
{
  return Length;
}

template < class ItemType > void SortedList < ItemType >::printList(ofstream& outFile)
{
  Node<ItemType>* temp = listData;
  for (int i = 0; i < Length; i++) {
    outFile << temp->info << "->";
    temp = temp->next;
  }
  outFile << "NULL";
}

template < class ItemType > ItemType SortedList < ItemType >::getAt(int index)
{
  if (index < 1 || index > Length) {
    throw OutOfBound();
  }
  Node<ItemType>* temp = listData;
  for (int j = 1; j < index; j++) {
    temp = temp->next;
  }
  return temp->info;
}
  
template < class ItemType > void SortedList < ItemType >::merge(SortedList& otherList)
{
  Node<ItemType>* node = listData;
  Node<ItemType>* predecessor = listData;
  while (node != NULL && otherList.listData != NULL) {
    Node<ItemType>* temp2 = otherList.listData;
    if (node->info > temp2->info) {
      if (node != listData) {
	predecessor->next = temp2;
      } 
      otherList.listData = otherList.listData->next;
      temp2->next = node;
      predecessor = temp2;
      otherList.Length--;
      Length++;
      if (node == listData) {
	listData = predecessor;
      }
    } else if (temp2->info > node->info) {
      predecessor = node;
      node = node->next;
    } else {
      otherList.listData = otherList.listData->next;
      otherList.Length--;
      delete temp2;
    } 
  }
  
  if (otherList.listData != NULL && isEmpty() == false) {
    predecessor->next = otherList.listData;
    Length += otherList.Length;
    otherList.listData = NULL;
    otherList.Length = 0;
  } else if (otherList.listData != NULL && isEmpty()) {
    listData = otherList.listData;
    Length += otherList.Length;
    otherList.listData = NULL;
    otherList.Length = 0;
  }
} 

template < class ItemType > bool SortedList < ItemType >::findItem(ItemType item, Node<ItemType>*& predecessor)
{
  Node<ItemType>* temp = listData;
  for (int i = 0; i < Length; i++) {
    if (temp->info == item) {
      if (i == 0) {
	predecessor = NULL;
	return true;
      }
      return true;
    }
    predecessor = temp;
    temp = temp->next;
  }
  return false;
}
